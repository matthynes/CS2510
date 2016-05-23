// Matthew Hynes (201200318)

//Magic number 4 used for assignment purposes and simplification
// but this could easily be scaled to up to 10 digits by using .size() instead

#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    //seed random num generator
    srand(time(NULL));

    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> num;

    //randomly generate unique numbers by removing them from available digits
    for (int i = 0; i < 4; i++) {
        int index = rand() % (digits.size());
        num.push_back(digits[index]);
        digits.erase(digits.begin() + index);
    }

    string guess;
    vector<int> conv_guess;

    cout << "Enter a 4 digit number to guess, enter | to finish: " << endl;

    while (cin >> guess) {
        cout << "Enter a 4 digit number to guess, enter | to finish: " << endl;
        int cows = 0, bulls = 0;
        conv_guess.clear();
        if (guess == "|") {
            break;
        }
        if (guess.size() != 4) {
            cout << "Guesses must be 4 digits: " << endl;
            continue;
        }
        //convert each character in guess to an integer for comparison
        for (char ch:guess) {
            conv_guess.push_back(ch - '0');
        }

        for (int j = 0; j < 4; j++) {
            if (conv_guess[j] == num[j]) {
                //digit is correct
                bulls++;
            } else {
                //digit does not match
                cows++;
            }
        }
        if (bulls != 4) {
            cout << bulls << " bulls and " << cows << " cows." << endl;
        } else {
            cout << "Congratulations, you win!" << endl;
            break;
        }
    }

    return 0;
}

