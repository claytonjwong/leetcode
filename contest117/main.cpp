/*
Rank	    Name	                Score	Finish Time 	Q1 (3)	    Q2 (5)	        Q3 (6)  	Q4 (8)
769 / 2770	claytonjwong Virtual	8	    0:40:15	        0:02:33	    0:35:15  *1

Q1: https://leetcode.com/problems/univalued-binary-tree/
A1: https://leetcode.com/problems/univalued-binary-tree/discuss/211600/1-liner-C%2B%2B

Q2: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
A2: https://leetcode.com/problems/numbers-with-same-consecutive-differences/discuss/211594/Concise-C%2B%2B

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <queue>


using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode( int val ) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

/*
class Solution
{
public:

    bool isUnivalTree( TreeNode* root )
    {
        if( ! root ) return true;
        if( root->left && root->left->val != root->val ) return false;
        if( root->right && root->right->val != root->val ) return false;
        return isUnivalTree( root->left ) && isUnivalTree( root->right );
    }
};
*/

#define L left
#define R right
class Solution
{
public:

    bool isUnivalTree( TreeNode* T )
    {
        return ( ! T )? true
            : ( T->L && T->L->val != T->val ) || ( T->R && T->R->val != T->val )? false
            : isUnivalTree( T->L ) && isUnivalTree( T->R );
    }

};

/*
using VI = vector< int >;
using Set = unordered_set< int >;
class Solution
{
public:

    VI numsSameConsecDiff( int N, int K, Set cur={ 1,2,3,4,5,6,7,8,9 } )
    {
        if( N == 1 ) cur.insert( 0 );

        for( auto d{ 1 }; d < N; ++d )
        {
            Set next;
            for( auto it{ cur.cbegin() }; it != cur.cend(); ++it )
            {
                auto num{ *it }, R{ num % 10 };
                if( R + K <= 9 ) next.insert( num * 10 + R + K );
                if( R - K >= 0 ) next.insert( num * 10 + R - K );
            }
            cur.swap( next );
        }

        return { cur.cbegin(), cur.cend() };
    }

};
*/


int main()
{
/*
    Solution s;
    auto result{ s.numsSameConsecDiff( 2, 1 ) };

    sort( result.begin(), result.end() );
*/

    TreeNode* root = new TreeNode( 1 );


    Solution s;

    return 0;
}