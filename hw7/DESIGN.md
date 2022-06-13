score_letter:
    loop thorugh the list of words, and use strchr() on each one of them, +1 to a counter if strchr() return is not a NULL. return counter in the end.

score_word: 
    make a copy of the word, remove duplicated letter in the copy, loop with result += letterscore[index]. return result in the end.

filter_gray:
    loop thorugh the list of words, and use strchr() on each one of them. If return !NUll, free(that pointer), and set NULL, and counter++. return counter in the end.

filter_yellow:
    loop through the list of words. If does not contain letter, free. Else if letter location == position, free, set NULL. counter++ after every time and return it in the end.

filter_green:
    loop through the list of words. If the specific location does not contains the target letter, free, set NULL. counter++ after every time and return it in the end.