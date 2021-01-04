/*
 * 21. Merge Two Sorted Lists
 *
 * Q: https://leetcode.com/problems/merge-two-sorted-lists/
 * A: https://leetcode.com/problems/merge-two-sorted-lists/discuss/505426/Kt-Js-Py3-Cpp-Cherry-Pick-Minimum
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val{ val }, next{ nullptr } {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
        auto sentinel = new ListNode(-1),
             tail = sentinel;
        while (A && B) {
            if (A->val < B->val)
                tail->next = A, A = A->next;
            else
                tail->next = B, B = B->next;
            tail = tail->next;
        }
        if (A) tail->next = A;
        if (B) tail->next = B;
        return sentinel->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
