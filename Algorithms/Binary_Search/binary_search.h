/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2025-01-22 11:27
 * @author: yikebaer·aizezi
 * @file: binary_search.h
 * @brief: 二分查找相关题目整理
*/
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <climits>

namespace binary_search {

class BinarySearch {
    public:
        int version_compare(std::string version1, std::string version2);
        int search(std::vector<int>& nums, int target);
};
} // namespace binary_search