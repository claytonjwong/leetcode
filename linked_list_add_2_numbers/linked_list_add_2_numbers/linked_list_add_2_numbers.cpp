/*
 
 2. Add Two Numbers
 
 https://leetcode.com/problems/add-two-numbers/description/
 
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 */


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{NULL} {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; }
        if (!l2) { return l1; }
        ListNode *head=nullptr, *curr=nullptr;
        bool carry=false;
        while (l1 || l2){
            int sum=0;
            if (l1) { sum+=l1->val; l1=l1->next; }
            if (l2) { sum+=l2->val; l2=l2->next; }
            if (carry) { ++sum; }
            if (sum > 9){ carry=true; sum%=10; }
            else        { carry=false;         }
            if (!curr){
                curr=new ListNode(sum);
                head=curr;
            } else {
                curr->next=new ListNode(sum);
                curr=curr->next;
            }
        }
        if (carry) { curr->next=new ListNode(1); }
        return head;
    }
};

int main(int argc, const char * argv[]) {

    
    ListNode* one = new ListNode(3);
    ListNode* curr = one;
    
    int n = 9;
    while ( n > 0){
        
        curr->next = new ListNode(9);
        curr = curr->next;
        n--;
    }
    
    
    
    ListNode* two = new ListNode(7);
    
    Solution solution;
    ListNode* result = solution.addTwoNumbers(one, two);
    
    cout << "Result: ";
    while ( result ){
        cout << result->val << ",";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}
