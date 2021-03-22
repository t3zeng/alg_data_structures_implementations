#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;

class Point {
    private:
        float x, y;
    public:
        Point(float xin, float yin) {
            x = xin;
            y = yin;
        }
        float angle() {
            return atan(y/x);
        }
        float distance(Point other) {
            cout << other.x << " " << x << " " << other.y << " " << y << endl;
            return sqrt(abs(other.x-x)*abs(other.x-x)+abs(other.y-y)*abs(other.y-y));
        }
};

int main() {
    Point p1(1,1);
    Point p2(4,5);

    cout << p1.distance(p2) << endl;
    return 0;
}