/*

 19. Remove Nth Node From End of List
 
 https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description
 
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
   struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
   };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int i=0;
        ListNode* itr = head;
        while(itr){
            itr=itr->next;
            i++;
        }
        
        // nothing to remove
        if (i < n){
            return head;
        }
        
        // remove head
        if (i==n){
            return head->next;
        }
        
        int j=0;
        itr = head;
        while(j < i - n - 1){
            itr=itr->next;
            j++;
        }
        itr->next = itr->next->next;
    
        return head;
    }
};


int main(int argc, const char * argv[]) {
    
    
    ListNode* p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    
    
    Solution solution;
    ListNode* r = solution.removeNthFromEnd(p, 2);
    
    cout << "[";
    do {
        cout << r->val << ",";
        r=r->next;
    } while (r != NULL);
    cout << "]";
        
    
    return 0;
}
