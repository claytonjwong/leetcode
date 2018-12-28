/*
 
 Implement a find function in a Skip List.  A Skip List is a linked list with nodes which may contain multiple "next" elements.  The Skip List is sorted in ascending order, and all "next" nodes can be assumed to be pointing towards nodes which are also sorted in ascending order.
 
 Example 1: a Skip List where the root has several "next" nodes, and all other nodes have a single "next" node, with the exception of the list node, which has "next" as NULL.
 
    1 -> 2 -> 3 -> 4 -> NULL
    |    ^    ^    ^
    |    |    |    |
    ----------------
 
    Use the find function to most efficiently find the node with value 4.
 
 */



#include <iostream>
#include <vector>


using namespace std;

class ListNode{
public:
    ListNode(int val) : val{val} {}
    
    int val;
    int hops;
    vector<ListNode*> children;
};

class SkipList{
public:
    
    ListNode* root;
    
    SkipList() : root{NULL} {}
    
    ListNode* find(int val){
        
        int hops=0;
        ListNode* curr = root;
        while (curr){
            
            if (curr->val == val){ // target found
                curr->hops = hops;
                return curr;
            }
            
            if (curr->children.empty()){ // no children to further check, and target value NOT found
                return NULL;
            }
            
            //
            // check children in reverse order to go as far as possible first,
            // this allows us to use the skip property of the SkipList more efficiently
            // and reduce redundant checks if forward iteration was used instead of reverse iteration
            //
            vector<ListNode*>& children = curr->children; // use ref to avoid copying vector
            vector<ListNode*>::iterator i=children.end()-1; // i is the last child
            while (true){

                //
                // from above check curr->children.empty(),
                // we know there is at least one node, if there is only one node,
                // then next == children.begin() == children.end()-1
                // and so the iterative exit condition is on children.begin() below
                //
                ListNode* next = *(i);
                
                if (next->val <= val ){ // target found or found a max val less than the target
                    curr = next;
                    break;
                }
                
                if (i == children.begin()){ // end of list iterating from back to front
                    
                    //
                    // target NOT found, and all next values are > target
                    // since the SkipList is in ascending order,
                    // we know target does NOT exist
                    //
                    return NULL;
                }
                
                i--; // iterate to next child
            }
            
            hops++; // curr is set to next, increment hop count, and process curr again
        }
        
        return NULL; // target NOT found
    }



    
};


int main(int argc, const char * argv[]) {
   
    
    // NULL input
    SkipList list = SkipList();
    ListNode* result = list.find(10);
    
    cout << "NULL input: ";
    if (result == NULL){
         cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl << endl << endl;
    
    
    // root is target
    list.root = new ListNode(10);
    result = list.find(10);
    
    cout << "Root is target: ";
    if (result && result->val == 10){
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl << endl << endl;
    
    
    // optimal hop (last node is target): 10->15->20 or 10->20
    ListNode* twenty = new ListNode(20);
    list.root->children.push_back(new ListNode(15));
    list.root->children[0]->children.push_back(twenty);
    
    cout << "10->15->20 -- 2 hops: ";
    result = list.find(20);
    if (result && result->val == 20 && result->hops == 2){
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl << endl << endl;
    
    
    // add new next from 10 directly to 20
    list.root->children.push_back(twenty);
    result = list.find(20);
    cout << "10->15->20 -- 1 hop: ";
    if (result && result->val == 20 && result->hops == 1){
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl << endl << endl;
    
    
    // test without the value found, value larger than all available
    cout << "Value NOT available, value too big: ";
    result = list.find(21);
    if (!result){
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl << endl << endl;
    
    // test without the value found, value smaller than all available
    cout << "Value NOT available, value too small: ";
    result = list.find(5);
    if (!result){
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl << endl << endl;
    
    
    // test without the value found, value in between but NOT available
    cout << "Value NOT available, value in middle: ";
    result = list.find(17);
    if (!result){
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl << endl << endl;
    
    
    return 0;
}

/* OUTPUT
 
 NULL input: PASS
 
 
 Root is target: PASS
 
 
 10->15->20 -- 2 hops: PASS
 
 
 10->15->20 -- 1 hop: PASS
 
 
 Value NOT available, value too big: PASS
 
 
 Value NOT available, value too small: PASS
 
 
 Value NOT available, value in middle: PASS
 
 
 Program ended with exit code: 0
 
 */


