/*

    654. Maximum Binary Tree

    Q: https://leetcode.com/problems/maximum-binary-tree/
    A: https://leetcode.com/problems/maximum-binary-tree/discuss/106218/easy-to-understand-python-and-c-using-recursion/246310

 */

#include <iostream>
#include <vector>


using namespace std;


struct TreeNode;
using HTreeNode = TreeNode*;
struct TreeNode
{
    int val;
    HTreeNode left, right;
    TreeNode( int val ) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:

    using VI = vector< int >;
    using Iter = VI::iterator;

    TreeNode* constructMaximumBinaryTree( VI& A )
    {
        return go( A.begin(), A.end() );
    }

private:

    TreeNode* go( Iter begin, Iter end )
    {
        if( begin == end )
            return nullptr;
        auto pivot = max_element( begin, end );
        auto root = new TreeNode( *pivot );
        root->left = go( begin, pivot );
        root->right = go( pivot + 1, end );
        return root;
    }

};

int main()
{
    Solution s;
    Solution::VI A{ 3,2,1,6,0,5 };
    auto root = s.constructMaximumBinaryTree( A );

    return 0;
}