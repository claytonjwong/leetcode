/*
 
 Implement an algorithm to delete a node in the middle (i.e. any node but head/tail )
 
 given access only to that node
 
 Example:

 input: 1->2->3->4   and remove node at index 2
 output: 1->2->4
 
 */

#include <iostream>

using namespace std;

struct node{
    int val;
    node* next;
};

class Solution{
public:
    void remove_node(node* n){
        
        node* itr = n;
        while ( itr && itr->next && itr->next->next ){
            itr->val = itr->next->val;
            itr = itr->next;
        }
        itr->val = itr->next->val;
        itr->next = NULL;
        
        
    }
};

int main(int argc, const char * argv[]) {
    
    
    cout << "input node values [-1 to END]: " << endl;
    
    node* head = NULL;
    node* itr = NULL;
    
    int val;
    while ( true ) {
        cin >> val;
        
        if (val == -1){
            break;
        }
        
        if (!itr){
            itr = new node;
            itr->val = val;
            itr->next = NULL;
            head = itr;
        } else {
            itr->next = new node;
            itr = itr->next;
            itr->val = val;
            itr->next = NULL;
        }
    }

    cout << "Before: ";
    itr = head;
    while ( itr ) {
        
        cout << itr->val << ", ";
        
        itr = itr->next;
    }
    cout << endl << endl;

    
    int index;
    node* remove = head;
    cout << "Input 0-based index to remove: ";
    cin >> index;
    
    cout << endl << endl;
    
    while ( index > 0 && remove->next->next != NULL ){
        remove = remove->next;
        index--;
    }
    if (index > 0){
        cout << "Index provided is NOT in the middle of head/tail.  Removing the node before tail instead..." << endl << endl;
    }
    
    
    Solution solution;
    solution.remove_node(remove);
    
    cout << "After: ";
    itr = head;
    while ( itr ) {
        
        cout << itr->val << ", ";
        
        itr = itr->next;
    }
    cout << endl << endl;
    
    
    
    
    return 0;
}
