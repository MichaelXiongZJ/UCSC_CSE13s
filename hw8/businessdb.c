#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Customer {
    char *email;    //key
    char *name;
    char *food;
    int shoe_size;
    struct Customer *next;
} Customer;

typedef struct Table {
    Customer **buckets;
    size_t num_buckets;
}Table;


//By Dan Bernstein
unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;
    while(*str != '\0'){
        c = *str;
        hash = ((hash << 5) + hash) + (unsigned char)c;
        str++;
    }
    return hash;
}

//helper
void remove_newline(char *s){
    if(!s){
        return;
    }
    char *newline;
    newline = strchr(s, '\n');
    if(newline){
        *newline = '\0';
    }
}


//make a table
Table *build_table(size_t num_buckets){
    Table *output = calloc(1, sizeof(Table));
    output->num_buckets = num_buckets;
    output->buckets = calloc(num_buckets, sizeof(Customer *));
    return output;
}

//helper, converts inputs into a customer
Customer *add_customer_to_list(char* email, char* name, char* food, int shoe_size, Customer *bucket){
    Customer *new_customer;
    new_customer = calloc(1, sizeof(Customer));
    new_customer->email = strdup(email);
    new_customer->name = strdup(name);
    new_customer->food = strdup(food);
    new_customer->shoe_size = shoe_size;
    new_customer->next = bucket;
    return new_customer;
}


//helper, remove a customer from list
Customer *remove_from_list(char* email, Customer *linkedlist){
    if(!linkedlist){
        return NULL;
    } else if(!strcmp(email, linkedlist->email)){
        Customer *next = linkedlist->next;
        free(linkedlist->email);
        free(linkedlist->name);
        free(linkedlist->food);
        free(linkedlist);
        return next;
    } else{
        linkedlist->next = remove_from_list(email, linkedlist->next);
        return linkedlist;
    }
}

//remove a customer from table
bool delete(char* email, Table *table){
    remove_newline(email);
    unsigned long hashvalue = hash(email);
    size_t which_bucket = hashvalue % table->num_buckets;
    Customer *linkedlist = table->buckets[which_bucket];
    bool found = false;
    Customer *here = linkedlist;
    while(here){
        if(!strcmp(here->email, email)){
            found = true;
            break;
        }
        here = here->next;
    }
    if(!found){
        return false;
    }
    table->buckets[which_bucket] = remove_from_list(email, linkedlist);
    return true;
}

//add customer to hash table
void add_to_table(char* email, char* name, char* food, int shoe_size, Table *table){
    if(delete(email, table)){
        printf("%s updated!\n", email);
    }
    unsigned long hashvalue = hash(email);
    size_t which_bucket = hashvalue % table->num_buckets;
    Customer *linkedlist = table->buckets[which_bucket];
    table->buckets[which_bucket] = add_customer_to_list(email, name, food, shoe_size, linkedlist);
}


//display everythig of a customer
void display(Customer *node){
    printf("Email: %s\n", node->email);
    printf("Name: %s\n", node->name);
    printf("Shoe Size: %d\n", node->shoe_size);
    printf("Fav Food: %s\n\n", node->food);
}



//load everything from file into ll and table, make a table as well?
void load_file(char *filename, Table *table){
    FILE *infile = fopen(filename, "r");
    if(!infile){
        printf("!!!save file customers.tsv NOT FOUND!!!\n");
        exit(EXIT_FAILURE);
    }
    char buf[1024];
    while(fgets(buf, 1024, infile)){
        remove_newline(buf);
        char *email = strtok(buf, "\t");
        char *name = strtok(NULL, "\t");
        int shoe_size = atoi(strtok(NULL, "\t"));
        char* food = strtok(NULL, "\t");
        add_to_table(email, name, food, shoe_size, table);
    }
    fclose(infile);
}


//find customer by email, and display everything abt this customer
bool lookup(char* email, Table *table){
    remove_newline(email);
    unsigned long hashvalue = hash(email);
    unsigned long which_bucket = hashvalue % table->num_buckets;
    Customer *here = table->buckets[which_bucket];
    while(here){
        if(!strcmp(here->email, email)){
            printf("Found:\n");
            display(here);
            return true;
        }
        here = here->next;
    }
    return false;
}


//display every user
void list(Table *table){
    for(size_t i = 0; i < table->num_buckets; i++){
        Customer *here = table->buckets[i];
        while(here){
            display(here);
            here = here->next;
        }
    }
}

//write everything into file
void save(char* filename, Table *table){
    FILE *infile = fopen(filename, "w");
    if(!infile){
        printf("save file customers.tsv NOT FOUND!!!\n");
        exit(EXIT_FAILURE);
    }
    for(size_t i = 0; i < table->num_buckets; i++){ 
        Customer *here = table->buckets[i];
        while(here){
            char *email = strdup(here->email);
            char *name = strdup(here->name);
            int shoe_size = here->shoe_size;
            char *food = strdup(here->food);
            fprintf(infile, "%s\t%s\t%d\t%s\n", email, name, shoe_size, food);
            free(email);
            free(name);
            free(food);
            here = here->next;
        }
    }
    fclose(infile);
}

//free everything
void quit(Table *table){
    for (size_t i = 0; i < table->num_buckets; i++) {
        Customer *here = table->buckets[i];
        while(here) {
            free(here->email);
            free(here->name);
            free(here->food);
            Customer *freethis = here;
            here = here->next;
            free(freethis);
        }
    }
    free(table->buckets);
    free(table);
}

//helper, check if a string is empty
bool is_empty(char *str){
    if(strlen(str) == 0){
        printf("Empty input detected!\n");
        return true;
    }
    return false;
}

//helper, check if a string is made of numbers
bool digits_only(char *s){
    while (*s) {
        if (isdigit(*s++) == 0){
            printf("That contains non-number!\n");
            return false;
        }
    }
    return true;
}

int main(void){

    Table *table = build_table(200);
    load_file("customers.tsv", table);

    while(true){
        char cmd[80] = {0};
        printf("\nEnter Your Command...\n");
        fgets(cmd, 80, stdin);
        remove_newline(cmd);
        if(!strcmp(cmd, "quit")){
            printf("Quitting...\n");
            quit(table);
            break;

        }else if(!strcmp(cmd, "add")){
            char email[80] = {0};
            char name[80] = {0};
            int shoe;
            char food[80] = {0};
            do{
                printf("Enter an Email:\n");
                fgets(email, 80, stdin);
                remove_newline(email);
            }while(is_empty(email));

            do{
                printf("Enter a Name:\n");
                fgets(name, 80, stdin);
                remove_newline(name);
            }while(is_empty(name));

            do{
                printf("Enter a Shoe Size:\n");
                fgets(cmd, 80, stdin);
                remove_newline(cmd);
            }while(is_empty(cmd) || !digits_only(cmd));
            shoe = atoi(cmd);

            do{
                printf("Enter a Fav Food:\n");
                fgets(food, 80, stdin);
                remove_newline(food);
            }while(is_empty(food));

            add_to_table(email, name, food, shoe, table);

        }else if(!strcmp(cmd, "lookup")){
            printf("Enter the email address of the customer:\n");
            fgets(cmd, 80, stdin);
            if(!lookup(cmd, table)){
                printf("Customer not found :(\n");
            }

        }else if(!strcmp(cmd, "delete")){
            printf("Enter the email address of the customer you wish to delete:\n");
            fgets(cmd, 80, stdin);
            if(delete(cmd, table)){
                printf("%s deleted", cmd);
            }else{
                printf("Customer not found :(\n");
            }

        }else if(!strcmp(cmd, "list")){
            printf("Here are all the customers:\n");
            list(table);

        }else if(!strcmp(cmd, "save")){
            save("customers.tsv", table);
            printf("Saved!\n");

        }else{
            printf("Unknown Command :(\n");
        }
    }
    return 0;
}
