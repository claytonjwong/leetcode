/*
 
 449. Serialize and Deserialize BST
 
 https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 
 Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 
 Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
 
 The encoded string should be as compact as possible.
 
 Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
 
 */

#include <iostream>
#include <string>
#include <deque>

using namespace std;



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val{x}, left{NULL}, right{NULL} {}
};

class Codec {
public:
    
    string serialize(TreeNode* root){
        /*
         push each tree node (including NULL leaf nodes) into a FIFO queue
         */
        deque<int*> q;
        serialize_helper(root, q);
        
        /*
         dequeue from queue to construct a space " " delimited string of TreeNode values
         */
        string result = "";
        while ( !q.empty() ){
            
            if ( !q.front() ) { result += "NULL"; } // NULL TreeNode
            
            else { result += to_string( *(q.front() )); } // non-NULL TreeNode
            
            result += " "; // delimiter
            
            q.pop_front(); // FIFO dequeue
        }
        return result;
    }
    
    TreeNode* deserialize(string key){
        
        /*
         construct a queue from the whitespace " " delimited string
         */
        deque<int*> q;
        while (key.find(" ") != string::npos){

            /*
             find token and remove token from string
             */
            string token = key.substr(0,key.find(" "));
            key.erase(0,key.find(" ")+1); // add 1 to remove trailing whitespace as well
            
            /*
             push token onto q
             */
            if (token=="NULL") { q.push_back(NULL); } // NULL TreeNode
            
            else { q.push_back(new int( stoi(token) )); } // non-NULL TreeNode
        }
        
        /*
         construct a TreeNode from the queue
         */
        return deserialize_helper(q);
    }
    
private:
    
    void serialize_helper(TreeNode* node, deque<int*>& q){
        
        /*
         base case, node is NULL, push NULL onto the queue
         this NULL is needed to keep track of the tree structure
         */
        if (!node) { q.push_back(NULL); return; }
        
        /*
         recursive case, pre-order traversal
         */
        q.push_back(&node->val);
        serialize_helper(node->left, q);
        serialize_helper(node->right, q);
    }
    
    TreeNode* deserialize_helper(deque<int*>& q){
        
        /*
         base case, q.front() == NULL, return NULL
         */
        if (!q.front() && q.size() > 0) {
            q.pop_front();
            return NULL;
        }
        
        /*
         recursive case, create a new tree node
         and recursively dequeue to create left/right sub-trees
         */
        TreeNode* node = new TreeNode( *(q.front()) );
        q.pop_front();
        node->left = deserialize_helper(q);
        node->right = deserialize_helper(q);
        
        return node;
    }
};

int main(int argc, const char * argv[]) {
    
    Codec solution;
    
    TreeNode* root = new TreeNode(69);
    root->left = new TreeNode(13);
    root->right = new TreeNode(123);
    
    
    string result = "";
    
    
    deque<int*> queue;
    string ss = solution.serialize(root);
    TreeNode* new_root = solution.deserialize(ss);
    
    return 0;
}
