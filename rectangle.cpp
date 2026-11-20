
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle() {
        width = 1;
        height = 1;
    }

    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    Rectangle(int length) {
        width = length;
        height = length;
    }

    bool isSquare() {
        return width == height;
    }
};

int main() {
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if (rect1.isSquare())
        cout << "rect1은 정사각형이다." << endl;

    if (rect2.isSquare())
        cout << "rect2는 정사각형이다." << endl;

    if (rect3.isSquare())
        cout << "rect3는 정사각형이다." << endl;

    return 0;
}
