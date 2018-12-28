/*
 
 Implement a function to check if a linked list is a palindrome
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val = 0;
    ListNode* next = NULL;
};

class Solution{
public:
    
    bool isPalindrome(ListNode* list){
        
        vector<int> stack;
        ListNode* slow=list; // move 1 node at a time
        ListNode* fast=list; // move 2 nodes at a time
        
        // len < 2
        if ( ! (list && list->next) ){
            return true;
        }
        
        // len == 2
        if ( ! (list->next->next) ){
            if (list->val == list->next->val){
                return true;
            } else {
                return false;
            }
        }
        
        
        // len > 2
        
        // once fast reaches the end, slow will be at the middle
        // push onto a stack until the middle
        // then start popping off the stack and check for equality
        
        while (true) {
            
            // fast has reached the end of even length list
            if (fast->next && !fast->next->next){
                
                stack.push_back(slow->val);
                slow = slow->next;
                break;
            }
            
            // fast has reached the end of odd length list
            if (!fast->next){
                
                slow = slow->next;
                break;
            }

            // begin/middle of the list, push onto stack and increment forwards
            if (fast->next && fast->next->next){
                
                stack.push_back(slow->val);
                
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        
        
        // iterate through the second half, pop off, and check for equality
        while(slow){
            if (slow->val == stack.back()){
                stack.pop_back();
                slow = slow->next;
            } else {
                return false;
            }
        }
        
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    ListNode* head = NULL;
    ListNode* itr = NULL;
    
    cout << "Input: [-1 to END]:" << endl;
    
    int val;
    while (true){
        cin >> val;
        
        if (val==-1){
            break;
        }
        
        if (!itr){
            itr = new ListNode;
            itr->val = val;
            itr->next = NULL;
            head = itr;
        } else {
            itr->next = new ListNode;
            itr = itr->next;
            itr->val = val;
            itr->next = NULL;
        }
    }
    
    Solution solution;
    cout << "is_palindrome: " << to_string( solution.isPalindrome(head) ) << endl << endl;

    
    return 0;
}






