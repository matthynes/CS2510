// Matthew Hynes (201200318)

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<double> v;
    double vec;
    double sum = 0;
    cout << "Enter a number, enter any non-number when finished:";

    while (cin >> vec) {
        if (!cin) {
            break;
        }
        cout << "Enter a number, enter any non-number when finished:";
        v.push_back(vec);
    }

    for (double d: v) {
        sum += d;
    }
    cout << "Total distance: " << sum << ". Average distance: " << sum / v.size();

    return 0;
}


