#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// pass in a string and returns true if it is between 1-59
bool is_valid_lotto_num(char *input) {
    int val = atoi(input);
    
    return  ((val >= 1) && (val <= 59)) ;
}

// pass by pointer string to store lotto num
// returns true if lotto number can be generated
bool get_lotto_num(char *input, char *lotto_num) {
    // no point even checking if there's too many numbers
    if(strlen(input)>15) return false;
    
    // bool array to check unique numbers
    bool unique[60];
    for(int i = 0; i < 60; i++) unique[i] = false;
    
    int input_idx = 0;
    int numbers_to_fill = 7;
    char temp[3];
    
    // read two numbers and write to temp
    // if the value is invalid only take the first number and append to lotto_num
    // keep doing this strategy until 
    // the digits remaining is equal to digits left to fill to reach 7 numbers
    while(input_idx<strlen(input)) {
        if(numbers_to_fill == strlen(input)-input_idx) {
            // finish routine and get out
            for(int i = 0; i < numbers_to_fill; i++) {
                char single_num[2];
                memset(single_num, 0, 2);
                strncat(single_num, &input[input_idx], 1);
                if(!is_valid_lotto_num(single_num) || unique[atoi(single_num)]) return false;
                strncat(lotto_num, " ", 1);
                strncat(lotto_num, &input[input_idx], 1);
                unique[atoi(single_num)] = true;
                input_idx++;
            }
            numbers_to_fill = 0;
            break;
        }
        else {
            memset(temp, 0, 3);
            // fill two
            strncat(temp, &input[input_idx], 2);

            // two digit value is valid, adding to lotto
            if(is_valid_lotto_num(temp) && !unique[atoi(temp)]) {
                strncat(lotto_num, " ", 1);
                strncat(lotto_num, temp, 2);
                input_idx+=2;
                unique[atoi(temp)] = true;
            }
            // two digit value is invalid, using 1 digit
            else {
                strncat(lotto_num, " ", 1);
                strncat(lotto_num, &input[input_idx], 1);
                input_idx++;
            }
            numbers_to_fill--;
        }
    }
    
    return numbers_to_fill==0;
}

// takes in the line and prints to stdout lotto number
void lotto_printer(char * line) {
    char lotto_str[100];
    memset(lotto_str, 0, 100);
    
    if(get_lotto_num(line, lotto_str)) {
        // clean init of return string
        char ret_str[100];
        memset(ret_str, 0, 100);
        
        // prep return string to print since lotto is valid
        strncat(ret_str, line, strlen(line));
        strncat(ret_str, " ->", strlen(" ->"));
        strncat(ret_str, lotto_str, strlen(lotto_str));
        printf("%s\n", ret_str);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[100];
    gets(str);
    int num_lines = atoi(str);
        
    for(int i = 0; i < num_lines; i++) {
        gets(str);
        lotto_printer(str);
    }
    
    return 0;
}