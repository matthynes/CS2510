// Matthew Hynes (201200318)
// Question 4

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

std::vector<int> countChars(std::vector<std::string> strings) {
    std::vector<int> char_counts;

    for (std::string s: strings) {
        char_counts.push_back(s.length());
    }

    return char_counts;
}

struct len {
    // Custom comparison function for comparing size of strings, to be used with sort() function.
    bool operator()(const std::string &str1, const std::string &str2) {
        return str1.size() < str2.size();
    }
};

std::string longestString(std::vector<std::string> strings) {
    // Sort each string based on it's length.
    sort(strings.begin(), strings.end(), len());

    // Longest string is last on in vector.
    return strings[strings.size() - 1];
}

std::string shortestString(std::vector<std::string> strings) {
    sort(strings.begin(), strings.end(), len());

    // Shortest string is first in vector.
    return strings[0];
}

std::string lexicalFirst(std::vector<std::string> strings) {
    // sort() automatically sorts the vector lexicographically
    sort(strings.begin(), strings.end());

    // First element is lexically first
    return strings[0];
}

std::string lexicalLast(std::vector<std::string> strings) {
    sort(strings.begin(), strings.end());

    return strings[strings.size() - 1];
}

int main() {
    std::vector<std::string> strs = {"truck", "guitar", "brown", "cow", "popsicle"};

    std::cout << "Longest string is " << longestString(strs) << std::endl;
    std::cout << "Shortest string is " << shortestString(strs) << std::endl;

    std::cout << "Lexicographically sorted, the first element is " << lexicalFirst(strs) << std::endl;
    std::cout << "Lexicographically sorted, the last element is " << lexicalLast(strs) << std::endl;

    return 0;
}

/**
 * Q: How many separate functions would you use for these tasks? Why?
 *
 * A: I would always use 4 separate functions for this because although they perform similar tasks,
 * they still do different things.
 * However, all 4 of these functions would probably be part of some kind of string utility class.
*/