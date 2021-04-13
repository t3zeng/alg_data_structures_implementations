#pragma once

#include <string>

class algo_stuff {
    private:
        int counter;
    public:
        algo_stuff();
        void incr_counter();
        int get_counter();
        int num_words(std::string s);
};