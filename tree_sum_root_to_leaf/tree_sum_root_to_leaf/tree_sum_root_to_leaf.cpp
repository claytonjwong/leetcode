/*
 
 129. Sum Root to Leaf Numbers
 
 https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 
 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 
 Find the total sum of all root-to-leaf numbers.
 
 For example,
 
  1
 / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 
 Return the sum = 12 + 13 = 25.
 
 
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};

class Solution{
public:
    
    
    int sumNumbers(TreeNode* root){
        
        return sumNumbersHelper(root, 0);
    }

    int sumNumbersHelper(TreeNode* root, int running_total){
        
        /*
         
         base case: NULL node or leaf node
         
         */
        if (!root){
            return 0;
        }
        if (!root->left && !root->right){
            return running_total + root->val;
        }
        
        /*
         
         recursive case: multiply running total by ten to make space for child value
         
         example:
         
         1        ==>   10 * (0+1) = 10      ( recursive case )
          \
           2        ==>   10 * (10+2) = 120  ( recursive case )
            \
             3        ==>    120 + 3         ( base case )
         
         */
        running_total = 10 * ( running_total + root->val );
        return
              sumNumbersHelper(root->right, running_total)
            + sumNumbersHelper(root->left, running_total);
        
        
    }
};


int main(int argc, const char * argv[]) {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    Solution solution;
    
    int result = solution.sumNumbers(root);
    
    cout << result << endl;
    
    return 0;
}




