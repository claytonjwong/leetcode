/*
 * 143. Reorder List
 *
 * Q: https://leetcode.com/problems/reorder-list/
 * A: https://leetcode.com/problems/reorder-list/discuss/523554/Javascript-Python3-C%2B%2B-Stack-solutions
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

class Solution {
public:
    using Stack = stack<ListNode*>;
    void reorderList(ListNode* head, Stack s = {}) {
        for (auto beg{ head }; beg; beg = beg->next)
            s.push(beg);
        int half = s.size() / 2;
        auto beg{ head };
        while (half--) {
            auto end = s.top(); s.pop();
            end->next = beg->next;
            beg->next = end;
            beg = end->next;
        }
        if (beg)
            beg->next = nullptr;
    }
};

int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    Solution solution;
    solution.reorderList(head);
    auto tail = head;
    while (tail)
        cout << tail->val << (tail->next ? ", " : ""), tail = tail->next;
    cout << endl;
    return 0;
}
