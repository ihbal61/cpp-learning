/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-23 11:39
 * @author: yikebaer·aizezi
 * @file: sort_algo.h
 * @brief: header for sorting algorithm
*/
#pragma once

#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

namespace sort_algo {

class SortAlgo {
public:
    SortAlgo();
    ~SortAlgo();

public:
    std::vector<int> bubble_sort(std::vector<int>& nums);
    std::vector<int> selection_sort(std::vector<int>& nums);
    std::vector<int> insertion_sort(std::vector<int>& nums);
    std::vector<int> shell_sort(std::vector<int>& nums);
    std::vector<int> merge_sort(std::vector<int>& nums);
    std::vector<int> quick_sort(std::vector<int>& nums);
    std::vector<int> heap_sort(std::vector<int>& nums);
    std::vector<int> counting_sort(std::vector<int>& nums);
    std::vector<int> bucket_sort(std::vector<int>& nums);
    std::vector<int> radix_sort(std::vector<int>& nums);
private:
    void merge_sort_helper(std::vector<int>& nums, int left, int right);
    void merge_sorted_list(std::vector<int>& nums, int left, int mid, int right);
    void quick_sort_helper(std::vector<int>& nums, int left, int right);
    int partition(std::vector<int>& nums, int left, int right);
    void heapify(std::vector<int>& nums, int n, int i);
    void counting_helper(std::vector<int>& nums, int exp);

};

};// namespace sort_algo