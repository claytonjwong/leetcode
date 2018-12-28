/*
 
 Rank           Name            Score   Finish Time  Q1 (2)    Q2 (5)       Q3 (7)    Q4 (9)
 1062 / 4508    claytonjwong    7       1:08:48      0:04:58   1:03:48  *1
 
 Q1: https://leetcode.com/problems/transpose-matrix/description/
 A1: https://leetcode.com/problems/transpose-matrix/discuss/146769/Straightforward-C++
 
 Q2: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
 A2: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/146768/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    VVI transpose(VVI& A) {
        int M=(int)A.size(),N=(int)A[0].size();
        VVI ans(N,VI(M,0));
        for (int i=0; i<M; ++i)
            for (int j=0; j<N; ++j)
                ans[j][i]=A[i][j];
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    VVI A{
        {1,2,3},
        {4,5,6},
    };
    Solution s;
    auto r=s.transpose(A);
    
    return 0;
}
*/

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val{x},left{nullptr},right{nullptr} {}
};

/*
class Solution {
public:
    TreeNode* ans;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxd=max_depth(root);
        go(root,maxd);
        return ans;
    }
private:
    int max_depth(TreeNode* root, int d=0){
        int l=(root->left) ? max_depth(root->left,d+1) : d;
        int r=(root->right) ? max_depth(root->right,d+1) : d;
        return max(l,r);
    }
    int go(TreeNode* root, const int maxd, int d=0){
        if (!root)
            return d-1;
        int l=go(root->left,maxd,d+1);
        int r=go(root->right,maxd,d+1);
        if (l==maxd && r==maxd)
            ans=root;
        return max(l,r);
    }
};
*/

/*
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        go(root);
        return ans;
    }
private:
    TreeNode* ans;
    int go(TreeNode* root, int&& maxd=0, int d=0){
        if (!root){
            maxd=max(maxd,d-1);
            return d-1;
        }
        int L=go(root->left,std::move(maxd),d+1);
        int R=go(root->right,std::move(maxd),d+1);
        if (L==maxd && R==maxd)
            ans=root;
        return max(L,R);
    }
};
 */

/*
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root, TreeNode** ans=new TreeNode*) {
        return go(root,ans).first;
    }
private:
    pair<TreeNode*,int> go(TreeNode* root, TreeNode** ans, int&& maxd=0, int d=0){
        maxd=max(maxd,d);
        int L=(root->left) ? go(root->left,ans,std::move(maxd),d+1).second : d,
            R=(root->right) ? go(root->right,ans,std::move(maxd),d+1).second : d;
        if (L==maxd && R==maxd) *ans=root;
        return {*ans,max(L,R)};
    }
};
*/

/*
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root, TreeNode* ans=new TreeNode{-1}) {
        return go(root,ans).first;
    }
private:
    pair<TreeNode*,int> go(TreeNode* root, TreeNode*& ans, int&& maxd=0, int d=0){
        maxd=max(maxd,d);
        int L=(root->left) ? go(root->left,ans,std::move(maxd),d+1).second : d,
            R=(root->right) ? go(root->right,ans,std::move(maxd),d+1).second : d;
        if (L==maxd && R==maxd) *ans=*root;
        return {ans,max(L,R)};
    }
};
 */


class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return go(root).first;
    }
private:
    pair<TreeNode*,int> go(TreeNode* root, TreeNode*&& ans=nullptr, int&& maxd=0, int d=0){
        if (!root->left && !root->right) maxd=max(maxd,d);
        int L=(root->left) ? go(root->left,move(ans),move(maxd),d+1).second : d,
            R=(root->right) ? go(root->right,move(ans),move(maxd),d+1).second : d;
        if (L==maxd && R==maxd) ans=root;
        return {ans,max(L,R)};
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    auto r=s.subtreeWithAllDeepest(root);
    
    return 0;
}
