/*
 
 Clone a linked list comprised of nodes related to other nodes in the linked list.
 A node is related to another node in the linked list when its value
 points towards that node.  Every node is guaranteed to be related to another node in the list.
 A node may be related to itself.
 
 For example: the following linked list contains 3 nodes: 1,2,3
 
 ---------------
 |     ---     |
 |     | |     |
 V     | V     V
 1 ---> 2 ---> 3 ---> NULL
 
 Each "next" node in the linked list is denoted above as --->
 
 Each node's relationships are as follows:
 
 node 1 is related to node 3
 node 2 is related to node 2 ( itself )
 node 3 is related to node 1
 
 The cloned linked list should contain the same relative values
 in separate and distinct memory.
 
 ---------------
 |     ---     |
 |     | |     |
 V     | V     V
 1 ---> 2 ---> 3 ---> NULL
 
 */

#pragma once

#include <unordered_map>

struct ListNode {
    ListNode *val,*next;
    ListNode(ListNode* x) : val{x},next{nullptr} {}
};
class Solution {
public:
    ListNode* clone(ListNode* head) {
        if (head==nullptr)
            return nullptr;
        std::unordered_map<ListNode*,ListNode*> m;
        auto sentinel=new ListNode(nullptr);
        for (auto in=head,out=sentinel; in; in=in->next,out=out->next)
            m[in]=out->next=new ListNode(in->val);
        for (auto out=sentinel->next; out; out=out->next)
            out->val=m[out->val];
        return sentinel->next;
    }
};

