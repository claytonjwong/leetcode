/*
 * 147. Insertion Sort List
 *
 * Q: https://leetcode.com/problems/insertion-sort-list/
 * A: https://leetcode.com/problems/insertion-sort-list/discuss/920698/Kt-Js-Py3-Cpp-Sentinel-%2B-Last
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val = -1, ListNode* next = nullptr) : val{ val }, next{ next } {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        auto sentinel = new ListNode(-1, head);
        auto last{ head };
        while (last && last->next) {
            // ✅ case 1: last.next is already in sorted order
            if (last->val < last->next->val) {
                last = last->next;
                continue;
            }
            // ❌ case 2: insert last.next somewhere after sentinel and before last
            auto pre{ sentinel };
            while (pre->next->val < last->next->val)
                pre = pre->next;
            auto tmp = last->next->next;
            last->next->next = pre->next;
            pre->next = last->next;
            last->next = tmp;
        }
        return sentinel->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
