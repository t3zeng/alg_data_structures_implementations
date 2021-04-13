// Your job is to find the number of words in a sentence
// Words are separated by any number of spaces
// Words with "-" are valid
// Characters that can be in the string "-.?!"
#include <iostream>
#include "word_counter.h"

using namespace std;

algo_stuff::algo_stuff() {
    counter = 0;
}

void algo_stuff::incr_counter() {
    counter++;
}

int algo_stuff::get_counter() {
    return counter;
}

int algo_stuff::num_words(string s) {
    int word_count = 0;

    bool is_word = false;

    for(char c:s) {
        if(c == ' ' || c == '.' || c == '!' || c == '?') is_word = false;
        else if(!is_word) {
            is_word = true;
            word_count++;
        }
    }

    return word_count;
}

algo_stuff my_algs;

int main() {
    cout << my_algs.num_words(" ! Hello there my guy!  ") << endl;
    return 0;
}