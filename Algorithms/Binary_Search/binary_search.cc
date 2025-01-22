/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2025-01-22 11:27
 * @author: yikebaer·aizezi
 * @file: binary_search.cc
 * @brief: 二分查找相关题目整理
*/
#include "binary_search.h"

namespace binary_search {
    /*
    * Algorithm complexity: O(n)
    * Space complexity: O(n)
    * nowcoder BM22
    */
    int BinarySearch::version_compare(std::string version1, std::string version2) {
        std::stringstream ss1(version1), ss2(version2);
        std::string token;
        std::vector<int> v1, v2;

        // read version info, split with '.', e.g. "1.0.1" -> vector {1, 0, 1}
        while (std::getline(ss1, token, '.')) {
            v1.push_back(std::stoi(token));
        }
        while (std::getline(ss2, token, '.')) {
            v2.push_back(std::stoi(token));
        }

        int n1 = v1.size(), n2 = v2.size(), i = 0;
        // if n1 != n2, we should ensure each of the index (n1 or n2) can be access
        // e.g. version1 = "1.0.1", version2 = "1"， If the statement in the while is （i < n1 && i < n2）
        // then after v1[0] == v2[0], i++, we cannot compare next part of the version
        while (i < std::max(n1, n2)) { 
            int num1 = (i < n1) ? v1[i] : 0;
            int num2 = (i < n2) ? v2[i] : 0;
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
            i++;
        }
        return 0; // version1 = version2
    }

    /*
    * Algorithm complexity: O(logn)
    * Space complexity: O(1)
    * leetcode 113
    */
    int BinarySearch::search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }

} // namespace binary_search