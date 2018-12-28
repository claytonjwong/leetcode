/*
 
 Implement an algorithm to find the kth to last element of a singly linked list
 
 */


#include <iostream>



using namespace std;


struct node {
    int val;
    node* next;
};


int main(int argc, const char * argv[]) {
    
    //
    // input
    //
    
    int k;
    node* head = NULL;
    node* itr = NULL;
    
    cout << "Input linked list: [-1 to END]" << endl;
    while ( true ){
        int val;
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
    cout << endl << "Input k: ";
    cin >> k;
    
    cout << endl << endl;
    
    
    //
    // output
    //
    
    // iterate ik forward by k, then follow ik with i ( k nodes away )
    // once ik is at the end of the list, i will be k away from the end
    node* i = head;
    node* ik = head;

    // 1->2->3->4   k=2
    // i  ik
    //    i  ik
    //       i  ik
    while ( k-1 > 0 ){ // substract 1 for 1-based indexing from the right
        
        if (ik->next){
            ik = ik->next;
        } else {
            break;
        }
        
        k--;
    }
    
    // k is > length of the linked list ( 1-based indexing from the right )
    if ( k != 1) {
        return NULL;
    }
    
    while ( ik && ik->next ){
        ik = ik->next;
        i = i->next;
    }
    
    cout << "Output: " << i->val << endl;
}
