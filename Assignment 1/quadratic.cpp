//Matthew Hynes (201200318)

#include <iostream>
#include <cmath>

using namespace std;

double a, b, c;
double x1, x2;
double discriminant;

int QuadMain() {
    cout << "Enter 3 coefficients to calculate: ";
    cin >> a >> b >> c;

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        //two possible roots
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "The roots are real and different:" << endl;
        cout << "x1=" << x1 << ", x2=" << x2 << endl;

    } else if (discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);

        cout << "The roots are real and equal:" << endl;
        cout << "x1=x2=" << x1 << endl;

    } else {
        //number under sqrt is negative so have to calculate imaginary and real part
        double real = -b / (2 * a);
        double imaginary = sqrt(-discriminant) / (2 * a);

        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << "The roots are complex and different:" << endl;
        cout << "x1=" << real << "+" << imaginary << "i" << ", x2=" << real << "-" << imaginary << "i" << endl;

    }

    return 0;
}

