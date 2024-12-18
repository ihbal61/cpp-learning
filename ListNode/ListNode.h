/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-19 11:27
 * @author: yikebaer·aizezi
 * @file: ListNode.cc
 * @brief: ListNode related algorithm
*/

#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

namespace list_node_algo {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListNodeHelper {
    public:
    // api for main.cc
    ListNode* reverse_list_node(ListNode* head);
    ListNode* merge_sorted_list_node(ListNode* head1, ListNode* head2);
    ListNode* sort_list_node(ListNode* head);

    private:
    ListNode* reverse_list_node_helper(ListNode* head_);
    ListNode* merge_sorted_list_node_helper(ListNode* head_1, ListNode* head_2);
    ListNode* merge_sort(ListNode* head_);
    ListNode* split_list_node(ListNode* head_);
    ListNode* quick_sort(ListNode* head);
    void quick_sort_helper(ListNode* head_, ListNode* tail_);
    ListNode* partition(ListNode* head_, ListNode* tail_);
    ListNode* get_tail(ListNode* head_);
    private:
    ListNode* prev_ = nullptr;
    ListNode* curr_ = nullptr;
    ListNode* temp_ = nullptr;
    ListNode* new_head_ = nullptr;
};

}; // namespace list_node_algo