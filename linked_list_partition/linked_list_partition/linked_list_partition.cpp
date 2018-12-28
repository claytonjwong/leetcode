/*
 
 Write code to partition a linked list around a value x, suchj that all nodes less than x come before all nodes greater than or equal to x.  If x is contained within the list, the values of x only need to be after the elements less than x (see below).  The partition element x can appear anywhere in the "right partition" it does not need to appear between the left and right partitions
 
 */

#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

class Solution{
public:
    
    node* partition(node* n, int mid){
        
        // create 2 linked lists, list1 <= mid < list2
        
        node* lte = NULL; // less than or equal
        node* gt = NULL; // greater than
        
        node* lte_itr = NULL;
        node* gt_itr = NULL;
        
        node* itr = n;
        while (itr){
            if (itr->val <= mid){
                if(!lte_itr){
                    lte_itr = new node;
                    lte_itr->val = itr->val;
                    lte_itr->next = NULL;
                    lte = lte_itr;
                } else {
                    lte_itr->next = new node;
                    lte_itr = lte_itr->next;
                    lte_itr->val = itr->val;
                    lte_itr->next  = NULL;
                }
            } else { // ( itr->val > mid )
                if(!gt_itr){
                    gt_itr = new node;
                    gt_itr->val = itr->val;
                    gt_itr->next = NULL;
                    gt = gt_itr;
                } else {
                    gt_itr->next = new node;
                    gt_itr = gt_itr->next;
                    gt_itr->val = itr->val;
                    gt_itr->next = NULL;
                }
            }
            itr=itr->next;
        }
        
        // append gt onto the end of lte and return the head of lte
        lte_itr = lte;
        while(lte_itr && lte_itr->next){
            lte_itr=lte_itr->next;
        }
        lte_itr->next = gt;
        return lte;
    }
};

int main(int argc, const char * argv[]) {

    node* head = NULL;
    node* itr = NULL;
    
    cout << "input [-1 to END]:" << endl;
    while ( true ){
        
        int val;
        cin >> val;
        
        if (val==-1){
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
    cout << endl << endl;
    
    int target;
    cout << "input target partition: ";
    cin >> target;
    
    Solution solution;
    node* result = solution.partition(head, target);
    
    cout << "output: ";
    while (result){
        cout << result->val << ", ";
        result = result->next;
    }
    
    return 0;
}
