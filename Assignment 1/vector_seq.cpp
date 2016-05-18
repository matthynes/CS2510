// Matthew Hynes (201200318)

#include <iostream>
#include <vector>

using namespace std;

int VecMain() {

    vector<double> v;
    double vec;
    double sum = 0;
    cout << "Enter a number, enter any non-number when finished:";

    //constantly read in numbers
    while (cin >> vec) {
        //check if input is a number
        if (!cin) {
            break;
        }
        cout << "Enter a number, enter any non-number when finished:";
        //add number to vector
        v.push_back(vec);
    }

    //calculate total
    for (double d: v) {
        sum += d;
    }
    cout << "Total distance: " << sum << ". Average distance: " << sum / v.size();

    return 0;
}


