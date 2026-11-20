
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction {
private:
    long long num, den;

    void reduce() {
        long long g = gcd(num < 0 ? -num : num, den);

        num /= g;
        den /= g;

        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraction(long long num, long long den) {
        this->num = num;
        this->den = den;
        reduce();
    }

    Fraction add(Fraction other) {
        return Fraction(
            num * other.den + other.num * den,
            den * other.den
        );
    }

    Fraction mul(Fraction other) {
        return Fraction(
            num * other.num,
            den * other.den
        );
    }

    void print() {
        if (den == 1)
            cout << num;
        else
            cout << num << "/" << den;
    }
};

int main() {
    int N;

    cout << "N을 입력하세요 : ";
    cin >> N;

    Fraction sum(0, 1);
    Fraction product(1, 1);

    for (int i = 1; i <= N; i++) {
        Fraction f(1, i);

        sum = sum.add(f);

        Fraction temp = Fraction(1, 1).add(f);
        product = product.mul(temp);
    }

    cout << "(1) : ";
    sum.print();

    cout << endl;

    cout << "(2) : ";
    product.print();

    cout << endl;

    return 0;
}
