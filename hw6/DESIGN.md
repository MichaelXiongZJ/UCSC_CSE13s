load_vocab:
    Use fopen to load the file line by line, allocate the array for the pointers of strings and use strdup to give each line allocation. Then use realloc to increase the size of allocated array. +1 on wordcount each time in the loop as well. Use fclose before returning

valid_guess:
    Loop through the array of strong to check if guess match one of them.

score_guess:
    compare each letter within the two strings with a loop and put the result on the result string. return true if the entire word matches.

Hard Mode:

Create an list of char that are revealed not in the secret word.

conflicted_guess:
    loop through each letter in guess, if it is in the list, return true, otherwise false.