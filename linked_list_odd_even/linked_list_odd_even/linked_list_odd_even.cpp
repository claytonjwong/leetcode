/*
 
 328. Odd Even Linked List
 
 https://leetcode.com/problems/odd-even-linked-list/description/
 
 Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 
 You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 
 Example:
 Given 1->2->3->4->5->NULL,
 return 1->3->5->2->4->NULL.
 
 Note:
 The relative order inside both the even and odd groups should remain as it was in the input.
 The first node is considered odd, the second node even and so on ...
 
 */



#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{NULL} {}
};

class Solution{
public:
    ListNode* oddEvenList(ListNode* head){
        
        /*
         
         min len for swapping is 3:  i.e.  1, 2, 3  ==>  1, 3, 2
         
         */
        if (!head || !head->next || !head->next->next){
            return head;
        }

        /*
         
         iterate through the list
         set odd.next to odd.next.next, and set odd to odd.next to continue iterating forward
         set even.next to even.next.next, and set even to even.next to continue iterating forward
         
         head is the first odd
         head->next is the first even
         
         at the end of the list append the head of the even list onto the end of odd list
         and return the original odd head (head, since these changes are performed in-place)
         
        */
        
        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        
        while (odd->next && odd->next->next){
            
            odd = odd->next = odd->next->next;
            
            if (even->next->next){
                
                even = even->next = even->next->next;
                
            } else {
                even->next = NULL;
            }
        }
        
        odd->next = evenHead;
        
        return head;
    }
};


int main(int argc, const char * argv[]) {

    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(6);
    
    Solution solution;
    
    list = solution.oddEvenList(list);
    
    while (list){
        cout << list->val << ", ";
        list = list->next;
    }
    
    return 0;
}





