/*
 * 2. Add Two Numbers
 *
 * Q: https://leetcode.com/problems/add-two-numbers/
 * A: https://leetcode.com/problems/add-two-numbers/discuss/1093/Kt-Js-Py3-Cpp-Concise-solutions
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* A, ListNode* B, bool carry = false) {
        auto ans = new ListNode(-1),
             cur = ans;
        while (A || B || carry) {
            auto a = A ? A->val : 0,
                 b = B ? B->val : 0,
                 c = a + b + int(carry);
            carry = 10 <= c, c %= 10;
            cur->next = new ListNode(c), cur = cur->next;
            A = A ? A->next : nullptr;
            B = B ? B->next : nullptr;
        }
        return ans->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
