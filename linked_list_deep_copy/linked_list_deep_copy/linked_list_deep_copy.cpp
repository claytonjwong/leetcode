/*
 
 138. Copy List with Random Pointer
 
 https://leetcode.com/problems/copy-list-with-random-pointer/description/
 
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
 Return a deep copy of the list.
 
 */


#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int label) : label{label}, next{NULL}, random{NULL} {}
};


class Solution{
public:
    RandomListNode* copyRandomList(RandomListNode* head){
        
        if (!head) { return NULL; }
        
        //
        // create copy and interweave into the existing linked list
        // so that every other odd node is the original list
        // and every other even node is the copy of the original list
        //
        // example:
        //
        // original = 1->3->5;
        //
        // let 2 be a copy of 1,
        //     4 be a copy of 3,
        //     6 be a copy of 5
        //
        // original with copy interweaved = 1->2->3->4->5->6
        //
        
        RandomListNode* orig=head, *copy=NULL;
        
        while (orig){
            
            //
            // create and insert copy after each orig node
            //
            copy = new RandomListNode(orig->label);
            copy->next = orig->next;
            orig->next = copy;
            
            //
            // skip over newly inserted copied node (orig->next),
            // and iterate to original's next (orig->next->next)
            //
            orig = orig->next->next;
        }
        
        //
        // now update the random pointers,
        // the copy's random will be the original random's "next" node,
        // since every other node is a copy of the original node
        //
        orig = head;
        
        while (orig){
            
            copy = orig->next; // every other node is a copy of the original
            
            //
            // set copy's random to original random's next,
            // since copy is original offset by 1 next
            //
            if (orig->random){
                copy->random = orig->random->next;
            }
            
            //
            // skip over copied node (itr->next),
            // and move onto original's next (orig->next->next)
            //
            orig = orig->next->next;
        }
        
        
        //
        // take all originals (odd nodes) and link them back together,
        // take all copies (even nodes) and link them together,
        // then return the head of this copied list
        //
        orig = head;
        RandomListNode* copyHead = head->next; // head is odd, head->next is even
        copy = copyHead;

        while (copy && copy->next){
            
            orig->next = orig->next->next; // odd
            copy->next = copy->next->next; // even
            
            //
            // iterate forward
            //
            orig = orig->next;
            copy = copy->next;
        }
        
        //
        // one last update needed to remove the last copied node
        // from the original list
        //
        orig->next = NULL;
        
        
        return copyHead;
    }
};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    RandomListNode* test = new RandomListNode(1);
    test->next = new RandomListNode(3);
    test->next->next = new RandomListNode(5);
    
    //
    // set random to previous node for testing/verification
    //
    test->next->random = test;
    test->next->next->random = test->next;
    
    solution.copyRandomList(test);
    
    
    
    return 0;
}







