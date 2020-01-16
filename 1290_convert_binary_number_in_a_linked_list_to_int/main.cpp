/*
 * 1290. Convert Binary Number in a Linked List to Integer
 *
 * Q: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 * A: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/discuss/454225/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val{x}, next{nullptr} {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head, int ans = 0) {
        while (head) {
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        return ans;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    Solution solution;
    auto ans = solution.getDecimalValue(head);
    cout << ans << endl;
    return 0;
}
