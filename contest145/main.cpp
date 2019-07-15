/*
 * https://leetcode.com/contest/weekly-contest-145/ranking
 *
 * Rank	        Name	        Score	Finish Time 	Q1 (3)	        Q2 (6)	    Q3 (7)  	Q4 (7)
 * 1343 / 4931	claytonjwong 	9	    0:52:51	        0:09:33  *1	    0:47:51
 *
 * Q1: https://leetcode.com/problems/relative-sort-array/
 * A1: https://leetcode.com/problems/relative-sort-array/discuss/334568/C%2B%2B-Solution
 *
 * Q2: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
 * A2: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/discuss/334579/C%2B%2B-Solution
 *
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    using VI = vector< int >;
    using Counter = unordered_map< int,int >;
    using Unique = multiset< int >;
    VI relativeSortArray( VI& A, VI& B, Counter cnt={}, VI ans={} ){
        for( auto x: A )
            ++cnt[ x ];
        Unique U{ A.begin(), A.end() };
        for( auto x: B ){
            fill_n( back_inserter( ans ), cnt[ x ], x );
            U.erase( x );
        }
        copy( U.begin(), U.end(), back_inserter( ans ) );
        return ans;
    }
};

int main() {
    Solution::VI arr1 = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31}, arr2 = {2,42,38,0,43,21};
    auto ans = Solution().relativeSortArray( arr1, arr2 );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ) );
    return 0;
}


/*
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val_) : val{ val_ }, left{ nullptr }, right{ nullptr } {}
};
class Solution {
public:
    using Node = TreeNode *;
    using Nodes = unordered_set< Node >;
    using Parent = unordered_map< int,Node >;
    using Depth = unordered_map< int,Nodes >;
    TreeNode* lcaDeepestLeaves( TreeNode* root, Parent P={}, Depth D={}, int maxd=0 ){
        go( root, P, D, maxd );
        Nodes cur = D[ maxd ];
        while( 1 < cur.size() ){
            Nodes next;
            for( auto x: cur )
                next.insert( P[ x->val ] );
            cur.swap( next );
        }
        return *cur.begin();
    }
private:
    void go( Node x, Parent& P, Depth& D, int& maxd, int d=0 ){
        if( maxd < d )
            maxd = d;
        D[ d ].insert( x );
        if( x->left ) P[ x->left->val ] = x, go( x->left, P, D, maxd, d+1 );
        if( x->right ) P[ x->right->val ] = x, go( x->right, P, D, maxd, d+1 );
    }
};

int main() {
    Solution S;
    TreeNode* root = new TreeNode( 1 );
    root->left = new TreeNode( 2 );
    root->right = new TreeNode( 3 );
    root->left->left = new TreeNode( 4 );
    root->left->right = new TreeNode( 5 );
    auto ans = S.lcaDeepestLeaves( root );

    return 0;
}
*/

// wrong algorithm
/*
class Solution {
public:
    using VI = vector< int >;
    int longestWPI( VI& A, int ans=0 ){
        return max( go({ A.begin(), A.end() }), go({ A.rbegin(), A.rend() }) );
    }
private:
    int go( VI&& A, int ans=0 ){
        auto N = static_cast< int >( A.size() );
        VI dp( N+1, 0 );
        for( auto i{ 1 }; i <= N; ++i )
            if( 8 < A[ i-1 ] )
                dp[ i ] = dp[ i-1 ] + 1;
            else
                dp[ i ] = max( 0, dp[ i-1 ] - 1 );
        for( auto i{ 1 }, cur{ 0 }; i <= N; ++i )
            if( dp[ i ] && ans < ++cur )
                ans = cur;
            else
                cur = 0;
        return ans;
    }
};

int main() {
    Solution S;
    Solution::VI A{ 6,9,9 };
    auto ans = S.longestWPI( A );
    cout << ans << endl;
    return 0;
}
*/
