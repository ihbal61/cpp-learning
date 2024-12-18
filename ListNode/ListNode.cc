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
    head = merge_sort(head);
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
ListNode* ListNodeHelper::merge_sort(ListNode* head_) {
    if (!head_ || !head_ -> next) {
        return head_;
    }
    ListNode* _second = split_list_node(head_);
    head_ = merge_sort(head_);
    _second = merge_sort(_second);
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

/*
 * Algorithm complexity: O(nlogn ~ n^2)
 * Space complexity: O(logn)
 */
ListNode* ListNodeHelper::quick_sort(ListNode* head) {
    ListNode* tail = get_tail(head);
    quick_sort_helper(head, tail);
    return head;
}

void ListNodeHelper::quick_sort_helper(ListNode* head_, ListNode* tail_) {
    if (!head_ || head_ == tail_) {
        return;
    }
    ListNode* pivot = partition(head_, tail_);
    quick_sort_helper(head_, pivot);
    quick_sort_helper(pivot -> next, tail_);

}

ListNode* ListNodeHelper::partition(ListNode* head_, ListNode* tail_) {
    ListNode* pivot = head_;
    prev_ = head_;
    curr_ = head_;
    while (curr_ != tail_-> next) {
        if (curr_ -> val < pivot -> val) {
            prev_ = prev_ -> next;
            std::swap(curr_ -> val, prev_ -> val);
        }
        curr_ = curr_ -> next;
    }
    std::swap(pivot -> val, prev_ -> val);
    return prev_;
}

ListNode* ListNodeHelper::get_tail(ListNode* head_) {
    while (head_ && head_ -> next) {
        head_ = head_ -> next;
    }
    return head_;
}


}; // namespace list_node_algo
