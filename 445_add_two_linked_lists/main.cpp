/*
 * 445. Add Two Numbers II
 *
 * Q: https://leetcode.com/problems/add-two-numbers-ii/
 * A: https://leetcode.com/problems/add-two-numbers-ii/discuss/927269/Kt-Js-Py3-Cpp-Recursive-Reverse
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next = nullptr) : val{ val }, next{ next } {}
};

class Solution {
public:
    using fun = function<ListNode*(ListNode*, ListNode*)>;
    ListNode* addTwoNumbers(ListNode* A, ListNode* B, int carry = 0) {
        fun rev = [&](auto cur, auto pre) -> ListNode* {
            if (!cur->next) {
                cur->next = pre;
                return cur;
            }
            auto next = cur->next;
            cur->next = pre;
            return rev(next, cur);
        };
        auto a = rev(A, nullptr),
             b = rev(B, nullptr),
             ans = new ListNode(-1),
             cur = ans;
        while (a || b) {
            auto c = (a ? a->val : 0) + (b ? b->val : 0) + carry;
            carry = 10 <= c; c %= 10;
            cur->next = new ListNode(c);
            cur = cur->next;
            if (a) a = a->next;
            if (b) b = b->next;
        }
        if (carry)
            cur->next = new ListNode(1);
        return rev(ans->next, nullptr);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
