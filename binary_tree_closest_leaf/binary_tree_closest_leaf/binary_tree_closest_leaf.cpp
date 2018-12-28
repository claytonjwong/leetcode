/*
 
 Q: https://leetcode.com/problems/closest-leaf-in-a-binary-tree/description/
 
 A: https://leetcode.com/problems/closest-leaf-in-a-binary-tree/discuss/126557/C++-Graph-and-BFS
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val{val},left{nullptr},right{nullptr} {}
};

class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        if (!root) return 0;
        if (!root->left && !root->right) return k;
        G.clear(); G.resize(1001); go(root);
        return bfs(root->val,k);
    }
private:
    vector<vector<int>> G;
    void go(TreeNode* root){
        if (root->left){ link(root,root->left); go(root->left); }
        if (root->right){ link(root,root->right); go(root->right); }
    }
    void link(TreeNode* parent, TreeNode* child){
        G[parent->val].push_back(child->val);
        G[child->val].push_back(parent->val);
    }
    int bfs(int root, int target){
        unordered_set<int> v({target});
        queue<int> q({target});
        while (!q.empty()){
            auto curr=q.front(); q.pop();
            if (curr!=root && G[curr].size()==1) return curr; // leaf node has 1 neighbor (except root)
            for (auto nei: G[curr])
                if (v.find(nei)==v.end()){ q.push(nei); v.insert(nei); }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    //root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->left->left=new TreeNode(5);
    Solution s;
    auto r=s.findClosestLeaf(root,2);
    cout << r << endl;
    
    
    return 0;
}


