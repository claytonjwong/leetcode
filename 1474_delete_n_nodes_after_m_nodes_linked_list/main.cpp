/*
 * 1474. Delete N Nodes After M Nodes of a Linked List
 *
 * Q: https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/
 * A: https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/discuss/685649/Javascript-and-C%2B%2B-solutions
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
    ListNode* deleteNodes(ListNode* head, int save, int skip) {
        auto pre = new ListNode(-1, head);
        for (;;) {
            for (auto i{ save }; i-- && pre; pre = pre->next); // save ✅ previous i nodes
            if (!pre)
                break;
            auto cur{ pre->next };
            for (auto j{ skip }; j-- && cur; cur = cur->next); // skip ❌ current j nodes
            pre->next = cur; // "remove" current j nodes
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
