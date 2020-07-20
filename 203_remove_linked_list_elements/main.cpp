/*
 * 203. Remove Linked List Elements
 *
 * Q: https://leetcode.com/problems/remove-linked-list-elements/
 * A: https://leetcode.com/problems/remove-linked-list-elements/discuss/745857/Javascript-Python3-C%2B%2B-iterative-with-sentinel
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val{ val }, next{ next } {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int T) {
        auto sentinel = new ListNode(-1, head);
        auto pre = sentinel,
             cur = head;
        for (;;) {
            while (cur && cur->val == T)
                cur = cur->next; // 🚫 remove cur val == target T 🎯
            pre = pre->next = cur;
            if (!cur)
                break;
            cur = cur->next;
        }
        return sentinel->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
