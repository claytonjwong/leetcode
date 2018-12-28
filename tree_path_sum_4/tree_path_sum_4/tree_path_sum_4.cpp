/*
 
 666. Path Sum IV
 
 If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.
 
 For each integer in this list:
 The hundreds digit represents the depth D of this node, 1 <= D <= 4.
 The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
 The units digit represents the value V of this node, 0 <= V <= 9.
 Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.
 
 Example 1:
 Input: [113, 215, 221]
 Output: 12
 Explanation:
 The tree that the list represents is:
 3
 / \
 5   1
 
 The path sum is (3 + 5) + (3 + 1) = 12.
 Example 2:
 Input: [113, 221]
 Output: 4
 Explanation:
 The tree that the list represents is:
 3
 \
 1
 
 The path sum is (3 + 1) = 4.
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val{-1}, left{NULL}, right{NULL} {}
};

class Solution {
public:
    
    Solution() {
        createTree();
    }
    
    int pathSum(vector<int>& nums) {
        
        initTree();
        for (auto num : nums){
            
            int depth = (int)(num / 100) - 1;
            int pos = ((int)(num/10) % 10) - 1;
            int val = (int)num % 10;
            
            table[depth][pos]->val = val;
        }
        
        int total_sum = 0;
        helper(root, 0, total_sum);
        return total_sum;
    }
    
    
private:
    
    void helper(TreeNode* node, int curr_sum, int& total_sum){
        
        if (!node) { return; }
        if (node->val==-1) { return; }

        curr_sum += node->val;
        
        bool left = true;
        if (!node->left) { left=false; }
        if (node->left && node->left->val == -1) { left=false; }
        
        bool right = true;
        if (!node->right) { right=false; }
        if (node->right && node->right->val == -1) { right=false; }
        
        if (!left && !right){
            total_sum += curr_sum;
        }
        
        helper(node->left, curr_sum, total_sum);
        helper(node->right, curr_sum, total_sum);
    }
    
    void initTree(){
        for (auto row : table){
            for (auto col : row){
                col->val = -1;
            }
        }
    }
    
    void createTree(){
        root = new TreeNode();
        table.push_back(vector<TreeNode*>{root});
        
        root->left = new TreeNode();
        root->right = new TreeNode();
        table.push_back(vector<TreeNode*>{root->left});
        table[1].push_back(root->right);
        
        root->left->left = new TreeNode();
        root->left->right = new TreeNode();
        root->right->left = new TreeNode();
        root->right->right = new TreeNode();
        table.push_back(vector<TreeNode*>{root->left->left});
        table[2].push_back(root->left->right);
        table[2].push_back(root->right->left);
        table[2].push_back(root->right->right);
        
        root->left->left->left = new TreeNode();
        root->left->left->right = new TreeNode();
        root->left->right->left = new TreeNode();
        root->left->right->right = new TreeNode();
        root->right->left->left = new TreeNode();
        root->right->left->right = new TreeNode();
        root->right->right->left = new TreeNode();
        root->right->right->right = new TreeNode();
        table.push_back(vector<TreeNode*>{root->left->left->left});
        table[3].push_back(root->left->left->right);
        table[3].push_back(root->left->right->left);
        table[3].push_back(root->left->right->right);
        table[3].push_back(root->right->left->left);
        table[3].push_back(root->right->left->right);
        table[3].push_back(root->right->right->left);
        table[3].push_back(root->right->right->right);
    }
    

    TreeNode* root;
    vector<vector<TreeNode*>> table;
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> input {
        115,215,224,325,336,446,458
    };
    cout << solution.pathSum(input) << endl;
    
    return 0;
}




