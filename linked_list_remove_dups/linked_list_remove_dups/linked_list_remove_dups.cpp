/*
 
 Write code to remove duplicates from an unsorted linked list
 
 How would you solve this problem if a temporary buffer is not allowed?
 
 */

#include <iostream>
#include <set>

using namespace std;

struct node{
    int val;
    node* next;
};

class Solution{
public:
    
    node* remove_dups(node* list){
        
        //
        // O(n) with a buffer
        //
        
        // add unique values into a set
        set<int> unique;
        node* itr = list;
        while ( itr ){
            unique.insert(itr->val);
            itr = itr->next;
        }
        
        // create a new linked list populated with set values
        node* head = NULL;
        itr = NULL;
        for (auto val : unique){
            
            if (itr == NULL){
                itr = new node;
                head = itr;
            } else {
                itr->next = new node;
                itr = itr->next;
            }
            itr->val = val;
            itr->next = NULL;
        }
        
        
        return head;
    }
    
    node* remove_dups_without_buff(node* list){
        
        //
        // O(n^2) without a buffer
        //
        node* head = list;
        node* itr = head;
        while (itr) {
            
            // slide prev/curr right
            node* prev = itr;
            node* curr = itr->next;
            
            while (curr){
                
                // bypass duplicate
                if (itr->val == curr->val){
                    prev->next = curr->next;
                }
                
                prev = curr;
                curr = curr->next;
            }
            
            
            itr = itr->next;
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    
    //
    // input
    //
    node* test = NULL;
    node* itr = NULL;
    int val;
    
    cout << "Input linked list values: [ (-1) to END input ]" << endl;
    while ( true ){
        
        cin >> val;
        
        if (val == -1){
            break;
        }
        
        if (itr == NULL){
            itr = new node;
            itr->val = val;
            itr->next = NULL;
            
            test = itr;
        } else {
            itr->next = new node;
            itr = itr->next;
            itr->val = val;
            itr->next = NULL;
        }
        
        
    }
    
    //
    // output
    //
    Solution solution;
    node* result = solution.remove_dups_without_buff(test);
    
    cout << endl << "unique: " << endl;
    itr = result;
    while ( itr ){
        cout << itr->val << ", ";
        itr = itr->next;
    }
    cout << endl << endl;
    
    
    
    return 0;
}
