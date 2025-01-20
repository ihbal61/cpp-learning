#include <iostream>
#include <string>
#include <sstream>

/*
 * read from string
 * for example: some algorithms input is a vector<int>, and its value contains: 1,2,3,4,5,6,7
 * we should be able to read this string and convert it to a vector<int>
 */
int main() {
    // input string
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string token;
    std::vector<int> nums;

    // read and convert each number to integer and push into the vector
    while (std::getline(ss, token, ',')) {
        nums.push_back(std::stoi(token));
    }

    return 0;
}