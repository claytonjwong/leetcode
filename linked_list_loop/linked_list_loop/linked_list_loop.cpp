/*
 
 Given a linked list, check if there is a loop
 
 
 */

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

class Solution{
public:
    
    bool is_loop(Node* list){
        Node* slow=list;
        Node* fast=list;
        
        while (fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if ( slow == fast ){
                return true;
            }
        }
        return false;
        
    }
    
};

int main(int argc, const char * argv[]) {
    
    Node* head = NULL;
    
    
    head = new Node;
    head->val = 1;
    head->next = new Node;
    head->next->val = 2;
    head->next->next = new Node;
    head->next->next->val = 3;
    head->next->next->next = NULL;
    
    Solution solution;
    cout << "is_loop: " << to_string( solution.is_loop(head) ) << endl << endl;
    
    return 0;
}
