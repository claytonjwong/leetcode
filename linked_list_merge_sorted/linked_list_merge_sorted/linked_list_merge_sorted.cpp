/*
 
 21. Merge Two Sorted Lists
 
 https://leetcode.com/problems/merge-two-sorted-lists/description/
 
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 */


#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *res=nullptr, *itr=nullptr, *min=nullptr;
        while (l1 && l2){
            if (l1->val < l2->val) {
                min=l1;
                l1=l1->next;
            } else {
                min=l2;
                l2=l2->next;
            }
            if (res==nullptr){
                itr=res=min;
            } else {
                itr->next=min;
                itr=itr->next;
            }
        }
        while (l1){
            itr->next=l1;
            itr=itr->next;
            l1=l1->next;
        }
        while (l2){
            itr->next=l2;
            itr=itr->next;
            l2=l2->next;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    ListNode* a=new ListNode(1);
    a->next=new ListNode(2);
    //    a->next->next=new ListNode(3);
    
    ListNode* b=new ListNode(2);
    b->next=new ListNode(4);
    b->next->next=new ListNode(6);
    
    ListNode* c=solution.mergeTwoLists(nullptr, b);
    
    
    return 0;
}







