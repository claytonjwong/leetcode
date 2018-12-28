/*
 
 654. Maximum Binary Tree
 
 https://leetcode.com/problems/maximum-binary-tree/description/
 
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
 
 The root is the maximum number in the array.
 The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
 The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
 Construct the maximum tree by the given array and output the root node of this tree.
 
 Example 1:
 Input: [3,2,1,6,0,5]
 Output: return the tree root node representing the following tree:
 
    6
  /   \
 3     5
  \    /
   2  0
    \
     1
 
 Note:
 The size of the given array will be in the range [1,1000].
 
 
 */


#include <iostream>
#include <vector>

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
     
     Using recursion, find the maximum value and split the array into two sub-problems at the index of the maximum value. The array to the left is the left child's tree created by that sub-array. The array to the right is the right child's tree created by that sub-array.
     
     The helper method uses iterators for the sub-array begin and end positions. When begin == end, then the sub-array is "empty".
     
     */
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return constructMaximumBinaryTreeHelper( nums.begin(), nums.end() );
    }

    typedef typename vector<int>::iterator itr;
    TreeNode* constructMaximumBinaryTreeHelper(itr begin, itr end) {
        
        TreeNode* root = NULL;
        
        if (begin == end){
            return NULL;
        }
        
        itr max_itr = max_element(begin,end);
        int max_int = *max_itr;
        
        root = new TreeNode(max_int);
        root->left = constructMaximumBinaryTreeHelper( begin, max_itr);
        root->right = constructMaximumBinaryTreeHelper( ++max_itr, end);
        
        return root;
    }
};

int main(int argc, const char * argv[]) {
   
    
    vector<int> nums { 3,2,1,6,0,5 };
    Solution solution;
    TreeNode* result = solution.constructMaximumBinaryTree(nums);
    
    return 0;
}
