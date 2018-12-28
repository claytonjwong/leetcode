/*
 
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
 
 */

#include <stdio.h>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (!headA || !headB){
            return NULL;
        }
        
        int lenA = 1;
        int lenB = 1;
        
        ListNode* itrA = headA;
        ListNode* itrB = headB;
        
        // find the lengths of A and B by iterating to the last node in each list
        while(itrA && itrA->next){
            lenA++;
            itrA = itrA->next;
        }
        while(itrB && itrB->next){
            lenB++;
            itrB = itrB->next;
        }
        
        // if the last node does NOT match, then there is no intersection
        if (itrA != itrB){
            return NULL;
        }
        
        // start iterating through A and B at the same node distance from the last node in each list
        itrA = headA;
        itrB = headB;
        while (lenA > lenB){ // if A is longer, then move A ahead
            lenA--;
            itrA=itrA->next;
        }
        while (lenB > lenA){ // if B is longer, then move B ahead
            lenB--;
            itrB=itrB->next;
        }
        
        // move A and B forward together to find first node itersection
        while (itrA && itrB){
            
            if (itrA == itrB){
                return itrA;
            }
            
            itrA=itrA->next;
            itrB=itrB->next;
        }
        
        return NULL;
    }
};


int main(){
    
    ListNode* listB = new ListNode(1);
    listB->next = new ListNode(2);
    listB->next->next = new ListNode(3);
    
    ListNode* listA = new ListNode(1);
    listA->next = new ListNode(2);
    listA->next->next = new ListNode(3);
    
    ListNode* listC = new ListNode(1);
    listC->next = new ListNode(2);
    listC->next->next = new ListNode(3);
    
    listA->next->next->next = listC;
    listB->next->next->next = listC;
    
    
    
    Solution solution;
    ListNode* result = solution.getIntersectionNode(listA, listB);
    
    
    return 0;
}









