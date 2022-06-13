note: i'm not planning on using a headerfile, gonna put everything in businessdb.c

struct:
    similiar to the FriendNode example in class, there will be two structs:
        customer: email, name, shoe size, food, and pointer for the next customer
        table: **buckets, num_buckets

functions:
    functions for command:
        - add_to_table(): will be referencing add_friend_to_table() from FriendNode example
        - lookup(): will be referencing fav_food_for_friend()
        - delete(): referencing unfriend()
        - list(): prints out all 
        - save(): fputs the hash table onto the file
        - quit(): free everything before closing program
    functions for hash:
        - build_table(): referencing build_friend_table()
        - hash(): the class example, by Dan Bernstein
    helper functions:
        - load_file(): load everything from file into ll and table
        - add_customer_to_list(): a helper function that converts inputs into a customer
        - remove_from_list(): reference delete_friend_from_lsit()
        - display(): a helper function that prints out all information of a customer

main:
    similiar to the businessdb example, there will be a while loop and input command will be decide where it goes.
        ex:
            if cmd == quit, then free everything and close program
            else then check if it matches any other commands and leads to each functions for command.
    a lot of string.h functions will be used for reading the command lines as well as reading/writing the file.

