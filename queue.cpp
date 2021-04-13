#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdint>

using namespace std;

#define QUEUE_SIZE (10)

class my_queue {
    private:
        int capacity;
        int front_idx;
        int rear_idx;
        char * arr;
        int queue_size;
    public:
        my_queue(int size = QUEUE_SIZE);
        ~my_queue();
        void enqueue(char c);
        char dequeue();
        char peek();
        int get_queue_size();
};

my_queue::my_queue(int size){
    capacity = size;
    front_idx = 0;
    rear_idx = 0;
    arr = new char[capacity];
    queue_size = 0;
}

my_queue::~my_queue() {
    delete[] arr;
}

void my_queue::enqueue(char c) {
    // load value
    arr[rear_idx] = c;

    // update indices
    rear_idx = (rear_idx+1)%capacity;
    if (front_idx == rear_idx) {
        front_idx = (front_idx+1)%capacity;
    }
    else queue_size++;
}

char my_queue::dequeue() {
    if(queue_size == 0) return '/';
    char ret = arr[front_idx];

    // update indices
    front_idx = (front_idx+1)%capacity;
    queue_size--;

    return ret;
}

char my_queue::peek() {
    return arr[front_idx];
}

int my_queue::get_queue_size() {
    return queue_size;
}

char int2char(uint8_t i) {
    uint8_t digit = i; // ensure only one digit is used
    while(digit > 10) digit /= 10;
    return '0'+digit;
}

int main() {
    my_queue queue(5);

    cout << "Hello World" << endl;
    for(int i = 0; i < 69; i++) {
        queue.enqueue(int2char(i%10));
    }
    while(queue.get_queue_size()) {
        cout << queue.dequeue() << endl;
    }
    return 0;
}