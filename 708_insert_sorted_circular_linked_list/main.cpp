/*
 * 708. Insert into a Sorted Circular Linked List
 *
 * Q: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/
 * A: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/discuss/859467/Javascript-Python3-C%2B%2B-Simple-solutions
 */

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int val) : val{ val }, next{ nullptr } {}
};

class Solution {
public:
    Node* insert(Node* head, int x) {
        auto alt = new Node(x); alt->next = alt;
        if (!head)
            return alt;
        auto pre = head,
             cur = head->next;
        auto max = head;
        auto ok = [&](auto x) { return pre->val <= x && x <= cur->val; };
        while (!ok(x) && cur != head) {
            if (max->val <= cur->val)
                max = cur;
            pre = pre->next;
            cur = cur->next;
        }
        if (!ok(x)) {
            pre = max;
            cur = max->next;
        }
        alt->next = cur;
        pre->next = alt;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
