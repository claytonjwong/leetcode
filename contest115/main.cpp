/*
 *
 * Q1: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
 * A1: https://leetcode.com/problems/check-completeness-of-a-binary-tree/discuss/210148/Concise-and-Idiomatic-C%2B%2B
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>


using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode( int val ) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

using Sequence = set< int >;
using Difference = deque< int >;
using Unique = unordered_set< int >;
class Solution
{
    void go( TreeNode* root, Sequence& s, int&& d=0 )
    {
        if( ! root )
            return;

        s.insert( d++ ), go( root->left, s, 2 * d - 1 ), go( root->right, s, 2 * d );
    }

public:

    bool isCompleteTree( TreeNode* root, Sequence seq={}, Difference diff={} )
    {
        go( root, seq );
        adjacent_difference( seq.cbegin(), seq.cend(), back_inserter( diff ) ), diff.pop_front();
        Unique unique{ diff.cbegin(), diff.cend() };
        return diff.empty() || ( unique.size() == 1 && unique.find( 1 ) != unique.end() );
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode( 1 );
//    root->left = new TreeNode( 2 );
//    root->right = new TreeNode( 3 );
//    root->left->left = new TreeNode( 4 );
//    root->left->right = new TreeNode( 5 );
//    root->right->right = new TreeNode( 7 );

    cout << s.isCompleteTree( root ) << endl;

    return 0;
}


