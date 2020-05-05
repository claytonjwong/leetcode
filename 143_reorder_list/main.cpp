/*
 * 143. Reorder List
 *
 * Q: https://leetcode.com/problems/reorder-list/
 * A: https://leetcode.com/problems/reorder-list/discuss/523554/Javascript-and-C%2B%2B-solutions
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

namespace Solution1 {
    class Solution {
    public:
        using VL = vector<ListNode*>;
        void reorderList(ListNode* head, VL A = {}) {
            auto tail = head;
            while (tail)
                A.push_back(tail), tail = tail->next;
            if (A.size() < 3)
                return;
            int N = A.size(), i = 1, j = N - 1, k = 1;
            tail = head;
            while (i <= j) {
                if (k == 0) tail->next = A[i++];
                if (k == 1) tail->next = A[j--];
                tail = tail->next;
                k ^= 1;
            }
            tail->next = nullptr;
        }
    };
}
namespace Solution2 {
    class Solution {
    public:
        using Stack = stack<ListNode*>;
        void reorderList(ListNode* head, Stack S = {}) {
            for (auto cur{ head }; cur; cur = cur->next)
                S.push(cur);
            auto N = S.size();
            auto cur{ head };
            for (auto i{ 0 }; i < N / 2; ++i) {
                S.top()->next = cur->next;
                cur->next = S.top(); S.pop();
                cur = cur->next->next;
            }
            if (cur)
                cur->next = nullptr;
        }
    };
}

int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    Solution2::Solution solution;
    solution.reorderList(head);
    auto tail = head;
    while (tail)
        cout << tail->val << (tail->next ? ", " : ""), tail = tail->next;
    cout << endl;
    return 0;
}
