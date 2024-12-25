/*
 * demo for sorting algorithms
 */

#include <iostream>
#include "sort_algo.h"

using namespace sort_algo;

int main() {
    int n;
    SortAlgo sort_algo;
    while (std::cin >> n) {
        std::vector<int> nums;
        int num;
        for (int i = 0; i < n; i++) {
            num = random() % 100;
            nums.push_back(num);
        }
        // print the original array
        std::cout << "original array: ";
        for (int i = 0; i < n; i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
        // sort the array
        sort_algo.counting_sort(nums);
        
        // print the sorted array
        std::cout << "sorted array: ";
        for (int i = 0; i < n; i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;

    }
    return 0;
}