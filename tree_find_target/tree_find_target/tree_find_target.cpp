/*
 
 
 
 
 */



#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    
    /*
     
     pre-order traversal for each node a in the tree,
     try to find node b in the tree, where a+b = k
     
     */
    
    bool findTarget(TreeNode* root, int k) {
     
        start = root; // start node when searching for nodeB
        
        return findTargetHelper(root, k);
    }
    
    bool findTargetHelper(TreeNode* nodeA, int k) {
        
        //
        // base case
        //
        if (!nodeA) { return false; }
        
        //
        // recursive case: return true if two distinct nodes nodeA and nodeB are found,
        //                 where val of A+B=k, otherwise continue pre-order traversal
        //
        TreeNode* nodeB = findNodeB(start, nodeA->val, k);
        if (nodeB && (nodeB != nodeA) ){ return true; }
        
        return findTargetHelper(nodeA->left, k) || findTargetHelper(nodeA->right, k);
    }
    
    TreeNode* findNodeB(TreeNode* node, int a, int k){
        
        /*
         
         with each move through the tree to find nodeB, try to reach the value B
         using the BST property:
            * values to the left are smaller
            * values to the right are larger
         
         */
        
        if (!node) { return NULL; }
        
        int b = k-a; // derived from k=a+b
        
        if (node->val < b) { return findNodeB(node->right, a, k); } // make node val bigger towards b
        
        else if (node->val == b){ return node; } // match
        
        else if (node->val > b){ return findNodeB(node->left, a, k); } // make node val smaller towards b

        else { return NULL; } // should never get here
    }
private:
    TreeNode* start;
};

int main(int argc, const char * argv[]) {
    
    
    /*
     
     Input:
        5
       / \
      3   6
     / \   \
    2   4   7
     
     Target = 9
     
     Output: True
     
     */
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    Solution solution;
    
    cout << solution.findTarget(root, 9) << endl;
    cout << solution.findTarget(root, 28) << endl;
    
    
    TreeNode* test = new TreeNode(2);
    test->left = new TreeNode(1);
    test->right = new TreeNode(3);
    
    cout << solution.findTarget(test, 4) << endl;
    
    
    TreeNode* test2 = new TreeNode(1);
    
    cout << solution.findTarget(test2, 2) << endl;
    
    return 0;
}





