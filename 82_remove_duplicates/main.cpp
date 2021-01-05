/*
 * 82. Remove Duplicates from Sorted List II
 *
 * Q: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * A: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/590900/Kt-Js-Py3-Cpp-Single-Pass
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val{ val }, next{ next } {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto sentinel = new ListNode(-123, head),
             ans = sentinel,
             pre = head,
             cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val)
                cur = cur->next;
            if (pre == cur)
                ans->next = cur, ans = ans->next;
            pre = cur = cur->next;
        }
        ans->next = nullptr;
        return sentinel->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
