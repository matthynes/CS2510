// Matthew Hynes (201200318)
// This file is used for questions 1 and 2

#include <string>
#include <vector>
#include <iostream>

// Question 1 BEGIN
// not using const-reference for label parameter because there's not really any reason to
void print(std::string label, std::vector<int> &nums) {
    for (int x: nums) {
        std::cout << label << x << std::endl;
    }
}
// Question 1 END

// Question 2 BEGIN
void fib_print(int x, int y, int n) {
    std::vector<int> fib_nums;
    fib_nums.push_back(x);
    fib_nums.push_back(y);

    if (n == 0) {
        fib_nums.push_back(0);
        print("0th fibonacci: ", fib_nums);
    }

    // Because the print() function takes a vector of ints this has to be calculated the same way.
    // But it should really be calculated using unsigned longs as using ints will result in losing accuracy
    // with larger numbers.
    int previous = x;
    int current = y;
    for (int i = 1; i < n; i++) {
        int next = previous + current;
        fib_nums.push_back(next);
        previous = current;
        current = next;

    }

    print("", fib_nums);
}
//Question 2 END


int main() {
    //testing print() function
    std::vector<int> ints = {12, 3, 6, 8, 5, 4, 665436, 7, 5, 3, 553, 2, 5};
    std::string lbl = "The number is ";

    print(lbl, ints);


    //testing fib_print() function
    fib_print(0, 1, 25);
    std::cout << std::endl;
    fib_print(4, 17, 10);
}