/*
 * 141. Linked List Cycle
 *
 * Q: https://leetcode.com/problems/linked-list-cycle/
 * A: https://leetcode.com/problems/linked-list-cycle/discuss/523398/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head,
                fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
