/*
 
 You have two numbers represented by a linked list, where each node contains a single digit.  The digits are stored in reverse order, such that the 1's digit is at the head of the list.  Write a function that adds the two numbers and returns the sum as a linked list.
 
 example:
 
 list1 = 7->1->6
 list2 = 5->9->2
 
 sum = 2->1->9
 
   617
 + 295
 
 = 912
 
 
 */

#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

class Solution{
public:

    node* sum_lists(node* one, node* two){
        node* sum = NULL;
        node* itr = NULL;
        
        bool carry = false;
        while (one || two) {
            
            int csum = 0;
            
            if (one){
                csum += one->val;
            }
            
            if (two){
                csum += two->val;
            }
            
            if (carry){
                csum += 1; // add one for carry over from previous calc
            }
            carry = false;
            
            if (csum/10 >= 1){
                carry = true;
            }
            
            if (!itr){
                itr = new node;
                itr->val = csum % 10;
                itr->next = NULL;
                sum = itr;
            } else {
                itr->next = new node;
                itr = itr->next;
                itr->val = csum % 10;
                itr->next = NULL;
            }
            
            if (one){
                one = one->next;
            }
            if (two){
                two = two->next;
            }
        }
        
        if (carry){
            itr->next = new node;
            itr = itr->next;
            itr->val = 1;
            itr->next = NULL;
        }
        
        return sum;
    }
};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    node* first = new node;
    first->val = 7;
    first->next = new node;
    first->next->val = 1;
    first->next->next = new node;
    first->next->next->val = 6;
    first->next->next->next = NULL;

    node* second = new node;
    second->val = 5;
    second->next = new node;
    second->next->val = 9;
    second->next->next = new node;
    second->next->next->val = 2;
    second->next->next->next = NULL;
    
    node* result = solution.sum_lists(first, second->next->next);
    
    cout << "Output: ";
    while (result){
        
        cout << result->val << ", ";
        
        result = result->next;
    }
    cout << endl << endl;
    
    return 0;
}
