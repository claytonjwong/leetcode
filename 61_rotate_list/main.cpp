/*
 * 61. Rotate List
 *
 * Q: https://leetcode.com/problems/rotate-list/
 * A: https://leetcode.com/problems/rotate-list/discuss/152985/Javascript-Python3-C%2B%2B-Self-Documented
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val = 0, ListNode* next = nullptr) : val{ val }, next{ next } {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* oldHead, int K, int N = 0) {
        for (auto it{ oldHead }; it; ++N, it = it->next);
        auto rotate = N ? K % N : 0;
        if (!rotate)
            return oldHead;
        auto tail = new ListNode(-1, oldHead);
        for (auto pivot{ N - rotate }; pivot--; tail = tail->next);
        auto newHead = tail->next; tail->next = nullptr;
        for (tail = newHead; tail->next; tail = tail->next);
        tail->next = oldHead;
        return newHead;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
