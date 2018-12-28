/*
 
 663. Equal Tree Partition
 
 https://leetcode.com/problems/equal-tree-partition/description/
 
 Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.
 
 Example 1:
 Input:
 5
 / \
 10 10
 /  \
 2   3
 
 Output: True
 Explanation:
 5
 /
 10
 
 Sum: 15
 
 10
 /  \
 2    3
 
 Sum: 15
 Example 2:
 Input:
 1
 / \
 2  10
 /  \
 2   20
 
 Output: False
 Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
 Note:
 The range of tree node value is in the range of [-100000, 100000].
 1 <= n <= 10000
 
 */

#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val{x}, left{NULL}, right{NULL} {}
};

class Solution{
public:
    bool checkEqualTree(TreeNode* root){
        set<int> s{};
        int sum=sums(root, s, true);
        return !s.empty() && sum%2==0 && s.find(sum/2)!=s.end();
    }
private:
    int sums(TreeNode* root, set<int>& s, bool isRoot){
        if (!root) { return 0; }
        int sum=root->val+sums(root->left,s,false)+sums(root->right,s,false);
        if (!isRoot) { s.insert(sum); }
        return sum;
    }
};


int main(int argc, const char * argv[]) {
    
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(1);

    
    Solution solution;
    cout << solution.checkEqualTree(root) << endl;
    
    
    
    return 0;
}





