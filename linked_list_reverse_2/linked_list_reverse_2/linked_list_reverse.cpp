/*
 
 Reverse a linked list.  This can be tricky and easy to mess up.
 Remember a handful of key points about this algorithm, and its easy.
 
 1) A linked list can be reversed only if it has 2 or more nodes
 2) Use prev/curr to travese the linked list, initially prev=head, curr=head->next
 3) For each iteration through the loop, curr is pulled out and made the new head
 4) prev never changes, since prev is originally the head, in the reverse list, prev will be the tail
 5) the list is reversed when curr is NULL
 
 */

#include <iostream>
#include <string>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{NULL} {}
};

class Solution{
public:
    ListNode* reverse(ListNode* head){
        
        // 1) A linked list can be reversed only if it has 2 or more nodes
        
        if (!head) { return NULL; }
        if (!head->next) { return head; }
        
        
        // 2) Use prev/curr to travese the linked list, initially prev=head, curr=head->next
        
        ListNode* prev=head, *curr=prev->next;
        do {
            
            // 3) For each iteration through the loop, curr is pulled out and made the new head
            // 4) prev never changes, since prev is originally the head,
            //    in the reverse list, prev will be the tail
            
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            curr = prev->next;
            
        } while (curr); // 5) the list is reversed when curr is NULL
        
        return head;
    }
    
    void print(ListNode* head, string str){
        cout << str;
        while(head){
            cout << head->val << ",";
            head = head->next;
        }
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    Solution solution;
    solution.print(head, "Before: ");
    head = solution.reverse(head);
    solution.print(head, "After: ");
    
    
    return 0;
}




