#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

typedef struct {
    uint16_t lvl;
    uint16_t hp;
    uint16_t str;
    uint16_t def;
} stats_t;

class Human {
    private:
        string name;
        uint8_t age;
        bool is_male;
        stats_t *stats;

    public:
    Human();
    Human(string &n, uint8_t a, bool im);
    ~Human();
    string get_name() {
        return name;
    }
    uint16_t get_lvl() {
        return stats->lvl;
    }
};

Human::Human() {
    name = "Joe";
    age = 69;
    is_male = true;

    stats_t *stats = new stats_t();
    stats->lvl = 69;
    stats->hp = 420;
    stats->str = 69;
    stats->def = 420;
}

Human::Human(string &n, uint8_t a, bool im) {
    name = n;
    age = a;
    is_male = im;
    n = "Jojo";

    stats_t *stats = new stats_t();
    stats->lvl = 1337;
    stats->hp = 1337;
    stats->str = 1337;
    stats->def = 1337;
}

Human::~Human() {
    delete stats;
}

int main() {
    Human man = Human();
    cout << man.get_lvl() << endl;

    string n = "Bob";
    Human man2 = Human(n, 69, true);
    cout << man2.get_name() << endl;
    cout << n << endl;

    return 0;
}