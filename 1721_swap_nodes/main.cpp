/*
 * 1721. Swapping Nodes in a Linked List
 *
 * Q: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 * A: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1009772/Kt-Js-Py3-Cpp-Swap-based-upon-length-N
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int K) {
        auto N = 0; for (auto cur{ head }; cur; cur = cur->next, ++N);
        auto i = K - 1,
             j = N - K;
        auto a = head,
             b = head;
        while (i--) a = a->next;
        while (j--) b = b->next;
        swap(a->val, b->val);
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
