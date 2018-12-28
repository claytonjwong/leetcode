/*
 
 Mock IV sessions:
 
 https://leetcode.com/mockinterview/session/result/ojkxq3m/
 https://leetcode.com/mockinterview/session/result/ojkrm02/
 
 
 160. Intersection of Two Linked Lists
 
 https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 
 Write a program to find the node at which the intersection of two singly linked lists begins.
 
 
 For example, the following two linked lists:
 
 A:          a1 → a2
 ↘
 c1 → c2 → c3
 ↗
 B:     b1 → b2 → b3
 begin to intersect at node c1.
 
 
 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
 Credits:
 Special thanks to @stellari for adding this problem and creating all test cases.
 
 
 206. Reverse Linked List
 
 https://leetcode.com/problems/reverse-linked-list/description/
 
 Reverse a singly linked list.
 
 */

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        ListNode* itrA=headA;
        while (itrA && itrA->next){
            ++n;
            itrA=itrA->next;
        }
        ListNode* itrB=headB;
        while (itrB && itrB->next){
            ++m;
            itrB=itrB->next;
        }
        if (itrA != itrB){
            return NULL;
        }
        
        itrA=headA;
        while (n>m){
            itrA=itrA->next;
            --n;
        }
        
        itrB=headB;
        while(m>n){
            itrB=itrB->next;
            --m;
        }
        
        while(itrA && itrA->next && itrB && itrB->next && itrA!=itrB){
            itrA=itrA->next;
            itrB=itrB->next;
        }
        return itrA;
    }
};


class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) { return head; }
        ListNode* prev=head;
        ListNode* curr=prev->next;
        while(curr){
            prev->next=curr->next;
            curr->next=head;
            head=curr;
            curr=prev->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    
    
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next=new ListNode(3);
    
    
    
    
    
    Solution2 solution;
    ListNode* d=solution.reverseList(a);
    
    
    return 0;
}
