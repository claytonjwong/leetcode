/*
 * 382. Linked List Random Node
 *
 * Q: https://leetcode.com/problems/linked-list-random-node/
 * A: https://leetcode.com/problems/linked-list-random-node/discuss/752830/Javascript-Python3-C%2B%2B-random-solutions
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
};

class Solution {
    ListNode* head;
    int N;
public:
    Solution(ListNode* head) : head{ head }, N{ 0 } {
        auto cur = head;
        while (cur)
            cur = cur->next, ++N;
    }
    int getRandom() {
        auto cur = head;
        auto hops = rand() % N;
        while (hops--)
            cur = cur->next;
        return cur->val;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
