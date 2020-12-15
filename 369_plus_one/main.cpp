/*
 * 369. Plus One Linked List
 *
 * Q: https://leetcode.com/problems/plus-one-linked-list/
 * A: https://leetcode.com/problems/plus-one-linked-list/discuss/973286/Kt-Js-Py3-Cpp-Recursive-solutions
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int val) : val{ val }, next{ nullptr } {}
};

class Solution {
public:
    using fun = function<bool(ListNode*)>;
    ListNode* plusOne(ListNode* head) {
        fun go = [&](auto node) {
            if (!node)
                return false;
            auto carry = go(node->next);
            if (carry || !node->next) {
                if (++node->val == 10) {
                    node->val = 0;
                    return true;
                }
            }
            return false;
        };
        if (go(head)) {
            auto pre = new ListNode(1);
            pre->next = head;
            return pre;
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
