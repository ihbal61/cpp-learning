/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-23 11:39
 * @author: yikebaer·aizezi
 * @file: sort_algo.cc
 * @brief: sorting algorithm
*/
#include "sort_algo.h"

namespace sort_algo {

SortAlgo::SortAlgo() {}
SortAlgo::~SortAlgo() {}

/*
 * Leetcode: 912
 * Algorithm complexity: O(n^2)
 * Space complexity: O(1)
 *
*/
std::vector<int> SortAlgo::bubble_sort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
    return nums;
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(n^2)
 * Space complexity: O(1)
 *
*/
std::vector<int> SortAlgo::selection_sort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
    }
    return nums;
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(n^2)
 * Space complexity: O(1)
 *
*/

std::vector<int> SortAlgo::insertion_sort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
    return nums;
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(nlogn)
 * Space complexity: O(1)
 *
*/
std::vector<int> SortAlgo::shell_sort(std::vector<int>& nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int key = nums[i];
            int j = i - gap;
            while (j >= 0 && nums[j] > key) {
                nums[j + gap] = nums[j];
                j -= gap;
            }
            nums[j + gap] = key;
        }
    }
    return nums;
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(nlogn)
 * Space complexity: O(n)
 *
*/
std::vector<int> SortAlgo::merge_sort(std::vector<int>& nums) {
    merge_sort_helper(nums, 0, nums.size() - 1);
    return nums;
}

void SortAlgo::merge_sort_helper(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort_helper(nums, left, mid);
    merge_sort_helper(nums, mid + 1, right);
    merge_sorted_list(nums, left, mid, right);
}

void SortAlgo::merge_sorted_list(std::vector<int>& nums, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    for (int p = 0; p < temp.size(); p++) {
        nums[left + p] = temp[p];
    }
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(nlogn)
 * Space complexity: O(logn)
 *
*/
std::vector<int> SortAlgo::quick_sort(std::vector<int>& nums) {
    quick_sort_helper(nums, 0, nums.size() - 1);
    return nums;
}

void SortAlgo::quick_sort_helper(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quick_sort_helper(nums, left, pivot - 1);
    quick_sort_helper(nums, pivot + 1, right);
}

int SortAlgo::partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            i++;
            std::swap(nums[i], nums[j]);
        }
    }
    std::swap(nums[i + 1], nums[right]);
    return i + 1;
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(nlogn)
 * Space complexity: O(1)
 *
*/
std::vector<int> SortAlgo::heap_sort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
    return nums;
}

void SortAlgo::heapify(std::vector<int>& nums, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && nums[l] > nums[largest]) {
        largest = l;
    }
    if (r < n && nums[r] > nums[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 *
*/
std::vector<int> SortAlgo::counting_sort(std::vector<int>& nums) {
    int n = nums.size();
    int max_val = *std::max_element(nums.begin(), nums.end());
    int min_val = *std::min_element(nums.begin(), nums.end());
    int range = max_val - min_val + 1;
    std::vector<int> count(range), output(n);
    for (int i = 0; i < n; i++) {
        count[nums[i] - min_val]++;
    }
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[nums[i] - min_val] - 1] = nums[i];
        count[nums[i] - min_val]--;
    }
    for (int i = 0; i < n; i++) {
        nums[i] = output[i];
    }
    return nums;
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 *
*/
std::vector<int> SortAlgo::bucket_sort(std::vector<int>& nums) {
    int n = nums.size();
    int max_val = *std::max_element(nums.begin(), nums.end());
    int min_val = *std::min_element(nums.begin(), nums.end());
    int range = max_val - min_val + 1;
    std::vector<std::vector<int>> bucket(range);
    for (int i = 0; i < n; i++) {
        int index = (nums[i] - min_val) * (range - 1) / range;
        bucket[index].push_back(nums[i]);
    }
    for (int i = 0; i < range; i++) {
        std::sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            nums[index++] = bucket[i][j];
        }
    }
    return nums;
}

/*
 * Leetcode: 912
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 *
*/
std::vector<int> SortAlgo::radix_sort(std::vector<int>& nums) {
    if (nums.empty()) return nums;

    // Separate positive and negative numbers
    std::vector<int> positive_nums, negative_nums;
    for (const auto& num : nums) {
        if (num >= 0) {
            positive_nums.push_back(num);
        } else {
            negative_nums.push_back(-num); // Make negative numbers positive for sorting
        }
    }

    // Sort positive numbers
    if (!positive_nums.empty()) {
        int max_val = *std::max_element(positive_nums.begin(), positive_nums.end());
        for (int exp = 1; max_val / exp > 0; exp *= 10) {
            counting_helper(positive_nums, exp);
        }
    }

    // Sort negative numbers
    if (!negative_nums.empty()) {
        int max_val = *std::max_element(negative_nums.begin(), negative_nums.end());
        for (int exp = 1; max_val / exp > 0; exp *= 10) {
            counting_helper(negative_nums, exp);
        }
        std::reverse(negative_nums.begin(), negative_nums.end()); // Reverse to get the correct order
    }

    // Merge negative and positive numbers
    nums.clear();
    for (const auto& num : negative_nums) {
        nums.push_back(-num); // Convert back to negative
    }
    nums.insert(nums.end(), positive_nums.begin(), positive_nums.end());

    return nums;
}

void SortAlgo::counting_helper(std::vector<int>& nums, int exp) {
    int n = nums.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(nums[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(nums[i] / exp) % 10] - 1] = nums[i];
        count[(nums[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        nums[i] = output[i];
    }
}

}; // namespace sort_algo