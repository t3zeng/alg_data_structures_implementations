#include <iostream>
using namespace std;

class Rectangle {
    private:
        int width, height;
    public:
        void set_values(int x, int y) {
            width = x;
            height = y;
        }
        int area() {
            return width*height;
        }
};

int main() {
    Rectangle rect;
    rect.set_values(2,3);
    cout << "area: " << rect.area() << endl;
    return 0;
}