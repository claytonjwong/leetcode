/*
 * 876. Middle of the Linked List
 *
 * Q: https://leetcode.com/problems/middle-of-the-linked-list/
 * A: https://leetcode.com/problems/middle-of-the-linked-list/discuss/569337/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{ val }, next{ nullptr } {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto slow{ head },
             fast{ head };
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
