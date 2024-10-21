#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            cout << "Error: Denominator cannot be zero!" << endl;
            denominator = 1;
        }
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero!" << endl;
            denominator = 1;
        }
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    void simplify() {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }

    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    Fraction divide(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        if (denom == 0) {
            cout << "Error: Division by zero!" << endl;
            denom = 1;
        }
        Fraction result(num, denom);
        result.simplify();
        return result;
    }
};

int main() {
    Fraction n1, n2;

    cout << "Enter first fraction:" << endl;
    n1.input();

    cout << "Enter second fraction:" << endl;
    n2.input();

    Fraction result;

    result = n1.add(n2);
    cout << "Sum: ";
    result.display();

    result = n1.subtract(n2);
    cout << "Difference: ";
    result.display();

    result = n1.multiply(n2);
    cout << "Product: ";
    result.display();

    result = n1.divide(n2);
    cout << "Quotient: ";
    result.display();

    return 0;
}
