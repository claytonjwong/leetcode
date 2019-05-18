/*
 *
 * Q: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor
 *
 * A: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/discuss/292557/modern-C%2B%2B-solution
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode;
using HTreeNode = TreeNode*;
struct TreeNode {
    int val;
    HTreeNode left, right;
    TreeNode( int val ) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:
    int maxAncestorDiff( TreeNode* root, int ans=0 ){
        go( root, ans );
        return ans;
    }
private:
    using MinMax = pair< int,int >;
    MinMax go( TreeNode* root, int& ans ){
        MinMax same{ root->val, root->val };
        if( ! root->left && ! root->right )
            return same;
        auto[ minL, maxL ] = root->left?  go( root->left, ans )  : same;
        auto[ minR, maxR ] = root->right? go( root->right, ans ) : same;
        ans = max({ ans,
                    abs( root->val - minL ),
                    abs( root->val - minR ),
                    abs( root->val - maxL ),
                    abs( root->val - maxR ),
        });
        return{ min({ minL, minR, root->val }), max({ maxL, maxR, root->val }) };
    }
};

int main() {
    auto root = new TreeNode( 8 );
    root->left = new TreeNode( 3 );
    root->left->left = new TreeNode( 1 );
    root->left->right = new TreeNode( 6 );
    root->left->right->left = new TreeNode( 4 );
    root->left->right->right = new TreeNode( 7 );
    root->right = new TreeNode( 10 );
    root->right->right = new TreeNode( 14 );
    root->right->right->left = new TreeNode( 13 );
//    auto root = new TreeNode( 0 );
//    root->right = new TreeNode( 1 );
//    root->right->right = new TreeNode( 2 );
    Solution solution;
    auto ans = solution.maxAncestorDiff( root );
    cout << ans << endl;
    return 0;
}