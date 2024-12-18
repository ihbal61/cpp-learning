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
    head = _reverse_list_node_helper(head);
    return head;
}

ListNode* ListNodeHelper::merge_sorted_list_node(ListNode* head1,
            ListNode* head2) {
    return _merge_sorted_list_node_helper(head1, head2);
}

ListNode* ListNodeHelper::sort_list_node(ListNode* head) {
    head = _sort_list_node_merge(head);
    return head;
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::_reverse_list_node_helper(ListNode* _head) {
    if (_head || _head -> next) {
        return _head;
    }
    _curr = _head;
    while (_curr) {
        _temp = _curr -> next;
        _curr -> next = _prev;
        _prev = _curr;
        _curr = _temp;
    }
    return _prev;
}

/*
 * Algorithm complexity: O(m+n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::_merge_sorted_list_node_helper(ListNode* _head1,
                ListNode* _head2) {
    ListNode* _head = new ListNode();
    _curr = _head;
    while (_head1 && _head2) {
        if (_head1 -> val < _head2 -> val) {
            _curr -> next = _head1;
            _head1 = _head1 -> next;
        } else {
            _curr -> next = _head2;
            _head2 = _head2 -> next;
        }
        _curr = _curr -> next;
    }
    if (!_head1) {
        _curr -> next = _head2;
    }
    if (!_head2) {
        _curr -> next = _head1;
    }
    return _head -> next;
}

/*
 * Algorithm complexity: O(nlogn)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::_sort_list_node_merge(ListNode* _head) {
    if (!_head || !_head -> next) {
        return _head;
    }
    ListNode* _second = _split_list_node(_head);
    _head = _sort_list_node_merge(_head);
    _second = _sort_list_node_merge(_second);
    return _merge_sorted_list_node_helper(_head, _second);
}

/*
 * Algorithm complexity: O(n)
 * Space complexity: O(1)
 */
ListNode* ListNodeHelper::_split_list_node(ListNode* _head) {
    ListNode* _fast = _head, *_slow = _head;
    while (_fast && _fast -> next) {
        _fast = _fast -> next -> next;
        if (_fast) {
            _slow = _slow -> next;
        }
    }
    _temp = _slow -> next;
    _slow -> next = nullptr;
    return _temp;
}

}; // namespace list_node_algo
