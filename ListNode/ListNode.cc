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

}; // namespace list_node_algo
