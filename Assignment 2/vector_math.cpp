// Matthew Hynes (201200318)
// Question 3

#include <vector>
#include <algorithm>
#include <iostream>

struct vector_calc {
    double min, max;
    double mean, median;

    vector_calc(double vmin, double vmax, double vmean, double vmed) {
        min = vmin;
        max = vmax;
        mean = vmean;
        median = vmed;
    }
};

// Calculation function that returns struct of answers
vector_calc calculate(std::vector<double> vec) {
    //First, sort vector to make getting min, max easier. Must be sorted for median.
    std::sort(vec.begin(), vec.end());
    unsigned long len = vec.size();

    double sum = 0;
    for (double d:vec) {
        sum += d;
    }

    // Two different cases for getting median.
    double median;
    // Odd number of elements, median is middle element
    if (len % 2 != 0) {
        median = vec[len / 2];
    } else {
        // Even number of elements, median is average of middle 2
        double first = vec[len / 2];
        double second = vec[(len / 2) + 1];
        median = (first + second) / 2;
    }

    return vector_calc(vec[0], vec[len - 1], sum / len, median);
}

// Calculation function that uses const-parameters in place of traditional return statement
void calculate(std::vector<double> vec, double &min, double &max, double &mean, double &median) {
    std::sort(vec.begin(), vec.end());
    unsigned long len = vec.size();

    double sum = 0;
    for (double d:vec) {
        sum += d;
    }

    if (len % 2 != 0) {
        median = vec[len / 2];
    } else {
        double first = vec[len / 2];
        double second = vec[(len / 2) + 1];
        median = (first + second) / 2;
    }

    min = vec[0];
    max = vec[len - 1];
    mean = sum / len;
}

int main() {
    //Struct return testing BEGIN

    //testing vector with odd number of elements
    std::vector<double> dvec1 = {1.2, 67, 48.3, 999.4, 12.56, 8};

    vector_calc vc = calculate(dvec1);
    std::cout << "Smallest element: " << vc.min << std::endl;
    std::cout << "Largest element: " << vc.max << std::endl;
    std::cout << "Mean: " << vc.mean << std::endl;
    std::cout << "Median: " << vc.median << std::endl;
    std::cout << std::endl;

    //testing vector with even number of elements
    std::vector<double> dvec2 = {1.2, 35.9, 48.3, 127.465356, 12.56, 8, 55.6};

    vc = calculate(dvec2);
    std::cout << "Smallest element: " << vc.min << std::endl;
    std::cout << "Largest element: " << vc.max << std::endl;
    std::cout << "Mean: " << vc.mean << std::endl;
    std::cout << "Median: " << vc.median << std::endl;\
    std::cout << std::endl;

    //Struct return testing END

    //cost-reference return BEGIN

    double min, max, mean, median;

    calculate(dvec1, min, max, mean, median);
    std::cout << "Smallest element: " << min << std::endl;
    std::cout << "Largest element: " << max << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << std::endl;


    calculate(dvec2, min, max, mean, median);
    std::cout << "Smallest element: " << min << std::endl;
    std::cout << "Largest element: " << max << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << std::endl;

    //cost-reference return END
    return 0;
}


/**
 * Q: Which of the two ways of returning several result values do you prefer and why?
 *
 * A: It depends on the usage scenario. If I am just making a function do to some quick testing or as proof-of-concept I
 * prefer the const-parameter return as it is much faster to implement.
 * But if I am writing this function for someone else to use I'd prefer the struct return as it is more explicit. It also
 * allows you to extend it with other manipulation functions in the future.
 * /



