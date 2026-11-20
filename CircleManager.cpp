
#include <iostream>
using namespace std;

class Circle {
    int radius;

public:
    Circle() {
        radius = 1;
    }

    ~Circle() {}

    void setRadius(int r) {
        radius = r;
    }

    double getArea() {
        return 3.14 * radius * radius;
    }
};

class CircleManager {
    Circle* pArray = NULL;
    int size = 0;

    void input() {
        cout << "원의 개수 입력: ";
        cin >> size;

        pArray = new Circle[size];

        for (int i = 0; i < size; i++) {
            int r;
            cout << i + 1 << "번째 원의 반지름: ";
            cin >> r;

            pArray[i].setRadius(r);
        }
    }

    void decide() {
        cout << "\n면적이 100에서 200 사이인 원:\n";

        for (int i = 0; i < size; i++) {
            double area = pArray[i].getArea();

            if (area >= 100 && area <= 200) {
                cout << area << endl;
            }
        }
    }

public:
    CircleManager() {}

    ~CircleManager() {
        delete[] pArray;
    }

    void run() {
        input();
        decide();
    }
};

int main() {
    CircleManager* pMan = new CircleManager();

    pMan->run();

    delete pMan;

    return 0;
}
