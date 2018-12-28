/*
 
 61. Rotate List
 
 Q: https://leetcode.com/problems/rotate-list/description/
 A: https://leetcode.com/problems/rotate-list/discuss/152985/C++-Lead-and-Follow-concise-solution-with-explanation
 
 */

#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val{x},next{nullptr}{}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int N=0; for (auto itr=head; itr; ++N,itr=itr->next);
        if (!head || (k%=N)==0) return head;
        auto L=head,F=head;
        for (; k-- && L->next; L=L->next);
        for (; L->next; F=F->next,L=L->next);
        auto new_head=F->next;
        F->next=nullptr;
        L->next=head;
        return new_head;
    }
};

int main(int argc, const char * argv[]) {
    
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    Solution s;
    auto res=s.rotateRight(head, 2);
    
    return 0;
}
