/*
 * 430. Flatten a Multilevel Doubly Linked List
 *
 * Q: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 * A: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/615199/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head)
            go(head);
        return head;
    }
private:
    Node* go(Node* node) {
        auto cur = node,
             pre = cur;
        while (cur) {
            auto next = cur->next;
            if (!cur->child) {
                pre = cur, cur = cur->next;
                continue;
            }
            cur->child->prev = cur, cur->next = cur->child; // head of child list
            auto last = go(cur->child);
            if (next)
                next->prev = last, last->next = next; // tail of child list
            cur->child = nullptr;
            pre = cur = last;
        }
        return pre; // return the tail
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
