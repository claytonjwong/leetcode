/*
 * 24. Swap Nodes in Pairs
 *
 * Q: https://leetcode.com/problems/swap-nodes-in-pairs/
 * A: https://leetcode.com/problems/swap-nodes-in-pairs/discuss/759536/Javascript-Python3-C%2B%2B-sliding-window%3A-a-b-c
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val, ListNode* next) : val{ val }, next{ next } {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto a = new ListNode(-1, head),
             b = head,
             c = head ? head->next : nullptr;
        if (!c)
            return head;
        head = c;
        for (;;) {
            auto d = c->next; // ⭐️ d is the beginning of the next pair to swap
            a->next = c;
            b->next = c->next;
            c->next = b;
            if (!d || !d->next) // ❌ nothing left to swap
                break;
            a = b;
            b = d;
            c = d->next;
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
