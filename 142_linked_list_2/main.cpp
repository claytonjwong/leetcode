/*
 * 142. Linked List Cycle II
 *
 * Q: https://leetcode.com/problems/linked-list-cycle-ii/
 * A: https://leetcode.com/problems/linked-list-cycle-ii/discuss/523559/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

class Solution {
public:
    using Set = unordered_set<ListNode*>;
    ListNode *detectCycle(ListNode *head, Set seen = {}) {
        while (head) {
            if (!seen.insert(head).second)
                return head;
            head = head->next;
        }
        return nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
