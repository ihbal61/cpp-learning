/*
 * 
 */
#include <iostream>

#include "ListNode.h"

using namespace list_node_algo;

int main() {
    // demo for list node
    ListNodeHelper list_node_helper;
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);
    // ListNode* node = head -> next -> next -> next -> next;
    // node -> next = head -> next -> next;
    head = list_node_helper.reverse_list_node(head);
    // bool res = list_node_helper.has_cycle(head);
    while (head) {
        std::cout << head -> val << " ";
        head = head -> next;
    }
    std::cout << std::endl;
    // std::cout << "the bool is : " << res << std::endl;
    return 0;
}
