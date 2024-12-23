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
 * Leetcode: 141
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
bool ListNodeHelper::has_cycle(ListNode* head) {
    if (!head) {
        return false;
    }
    ListNode* slow = head, *fast = head;
    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

/*
 * Leetcode: 876
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::find_middle(ListNode* head) {
    if (!head) {
        return head;
    }
    ListNode* slow = head, *fast = head;
    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

/*
 * Leetcode: 19
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::remove_nth_from_end(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy, *fast = dummy;
    for (int i = 0; i < n; i++) {
        fast = fast -> next;
    }
    while (fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }
    slow -> next = slow -> next -> next;
    return dummy -> next;
}

/*
 * Leetcode: 234
 * Algorithm complexity: O(n)
 * Space complexity: O(n)
 */
bool ListNodeHelper::is_palindrome_stack(ListNode* head) {
    if (!head || !head -> next) {
        return true;
    }
    ListNode* slow = head, *fast = head;
    std::stack<int> stk;
    while (fast && fast -> next) {
        stk.push(slow -> val);
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if (fast) {
        slow = slow -> next;
    }
    while (slow) {
        int val = stk.top();
        stk.pop();
        if (val != slow -> val) {
            return false;
        }
        slow = slow -> next;
    }
    return true;
}

/*
 * Leetcode: 234
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
bool ListNodeHelper::is_palindrome(ListNode* head) {
    if (!head || !head -> next) {
        return true;
    }
    ListNode* middle = find_middle(head);
    ListNode* second = reverse_list_node(middle -> next);
    ListNode* first = head;
    while (second) {
        if (first -> val != second -> val) {
            return false;
        }
        first = first -> next;
        second = second -> next;
    }
    return true;
}

/*
 * Leetcode: 160
 * Algorithm complexity: O(m+n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::get_intersection_node(ListNode* head1, ListNode* head2) {
    if (!head1 || !head2) {
        return nullptr;
    }
    ListNode* first = head1, *second = head2;
    while (first != second) {
        if (first) {
            first = first -> next;
        } else {
            first = head2;
        }
        if (second) {
            second = second -> next;
        } else {
            second = head1;
        }
    }
    return first;
}

/*
 * Leetcode: 206
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
 * Leetcode: 21
 * Algorithm complexity: O(m+n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::merge_sorted_list_node_helper(ListNode* head1_,
                ListNode* head2_) {
    ListNode* head_ = new ListNode();
    curr_ = head_;
    while (head1_ && head2_) {
        if (head1_ -> val < head2_ -> val) {
            curr_ -> next = head1_;
            head1_ = head1_ -> next;
        } else {
            curr_ -> next = head2_;
            head2_ = head2_ -> next;
        }
        curr_ = curr_ -> next;
    }
    if (!head1_) {
        curr_ -> next = head2_;
    }
    if (!head2_) {
        curr_ -> next = head1_;
    }
    return head_ -> next;
}

/*
 * Leetcode: 148
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
 * Leetcode: 148
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
