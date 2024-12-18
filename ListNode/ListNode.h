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

    private:
    ListNode* _reverse_list_node_helper(ListNode* _head);
    ListNode* _merge_sorted_list_node_helper(ListNode* head1, ListNode* head2);
    
    private:
    ListNode* _prev = nullptr;
    ListNode* _curr = nullptr;
    ListNode* _temp = nullptr;
}

}; // namespace list_node_algo