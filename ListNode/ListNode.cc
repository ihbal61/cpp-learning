/*
 * Copyright (c) 2024 yikebaer·aizezi
 * @date: 2024-12-19 11:27
 * @author: yikebaer·aizezi
 * @file: ListNode.cc
 * @brief: ListNode related algorithm
*/
#include "ListNode.h"

namespace list_node_algo {

ListNode* ListNodeHelper::reverse_list_node(ListNode* head) {
    head = reverse_list_node_helper(head);
    return head;
}

ListNode* ListNodeHelper::merge_sorted_list_node(ListNode* head1,
            ListNode* head2) {
    return merge_sorted_list_node_helper(head1, head2);
}

ListNode* ListNodeHelper::sort_list_node(ListNode* head) {
    head = sort_list_node_merge(head);
    return head;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::reverse_list_node_helper(ListNode* head_) {
    if (head_ || head_ -> next) {
        return head_;
    }
    curr_ = head_;
    while (curr_) {
        temp_ = curr_ -> next;
        curr_ -> next = prev_;
        prev_ = curr_;
        curr_ = temp_;
    }
    return prev_;
}

/*
 * Algorithm complexity: O(m+n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::merge_sorted_list_node_helper(ListNode* head_1,
                ListNode* head_2) {
    ListNode* head_ = new ListNode();
    curr_ = head_;
    while (head_1 && head_2) {
        if (head_1 -> val < head_2 -> val) {
            curr_ -> next = head_1;
            head_1 = head_1 -> next;
        } else {
            curr_ -> next = head_2;
            head_2 = head_2 -> next;
        }
        curr_ = curr_ -> next;
    }
    if (!head_1) {
        curr_ -> next = head_2;
    }
    if (!head_2) {
        curr_ -> next = head_1;
    }
    return head_ -> next;
}

/*
 * Algorithm complexity: O(nlogn)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::sort_list_node_merge(ListNode* head_) {
    if (!head_ || !head_ -> next) {
        return head_;
    }
    ListNode* _second = split_list_node(head_);
    head_ = sort_list_node_merge(head_);
    _second = sort_list_node_merge(_second);
    return merge_sorted_list_node_helper(head_, _second);
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::split_list_node(ListNode* head_) {
    ListNode* fast = head_, *slow = head_;
    while (fast && fast -> next) {
        fast = fast -> next -> next;
        if (fast) {
            slow = slow -> next;
        }
    }
    temp_ = slow -> next;
    slow -> next = nullptr;
    return temp_;
}

}; // namespace list_node_algo
