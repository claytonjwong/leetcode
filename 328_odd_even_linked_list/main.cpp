/*
 * 328. Odd Even Linked List
 *
 * Q: https://leetcode.com/problems/odd-even-linked-list/
 * A: https://leetcode.com/problems/odd-even-linked-list/discuss/635092/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
};

using namespace std;

namespace Concise {
    class Solution {
    public:
        ListNode* oddEvenList(ListNode* head, ListNode* evenHead = nullptr) {
            if (!head)
                return nullptr;
            auto odd = head,
                 even = evenHead = head->next;
            while (even && even->next)
                odd = odd->next = even->next,
                even = even->next = odd->next;
            odd->next = evenHead;
            return head;
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        ListNode* oddEvenList(ListNode* head, ListNode* oddTail = nullptr, ListNode* evenHead = nullptr) {
            if (!head)
                return nullptr;
            auto odd = oddTail = head,
                 even = evenHead = head->next;
            while (odd && even) {
                if (odd->next == even)
                    odd = odd->next = even->next,
                    oddTail = odd ? odd : oddTail;
                else if (even->next == odd)
                    even = even->next = odd->next;
            }
            oddTail->next = evenHead;
            return head;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
