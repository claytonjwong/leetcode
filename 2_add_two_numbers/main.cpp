/*
 * 2. Add Two Numbers
 *
 * Q: https://leetcode.com/problems/add-two-numbers/
 * A: https://leetcode.com/problems/add-two-numbers/discuss/1093/a-few-solutions...
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

class Solution {
public:
    ListNode* addTwoNumbers( ListNode* a, ListNode* b, int carry = 0) {
        auto ans = new ListNode{-1}, head = ans;
        for (;;) {
            head->val = (a ? a->val : 0) + (b ? b->val : 0) + carry;
            carry = head->val / 10;
            head->val %= 10;
            if (a) a = a->next;
            if (b) b = b->next;
            if (!a && !b && !carry)
                break;
            head = head->next = new ListNode{-1};
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
