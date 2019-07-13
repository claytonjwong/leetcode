/*
 * https://leetcode.com/contest/weekly-contest-144/ranking
 *
 * Rank	        Name	        Score	Finish Time 	Q1 (1)	    Q2 (4)	    Q3 (6)	    Q4 (6)
 * 2362 / 4358	claytonjwong 	1	    0:02:07	        0:02:07
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

/*
class Solution {
public:
    string defangIPaddr( string s ){
        ostringstream os;
        for( auto c: s )
            if( c == '.' )
                os << "[.]";
            else
                os << c;
        return os.str();
    }
};
*/

// TLE
/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Deque = deque< int >;
    VI corpFlightBookings( VVI& B, int N ){
        Deque ans( N+1 );
        for( auto& b: B ){
            auto[ i,j,k ] = tie( b[ 0 ],b[ 1 ],b[ 2 ] );
            for(; i <= j; ans[ i++ ] += k );
        }
        ans.pop_front();
        return{ ans.begin(), ans.end() };
    }
};
*/

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Map = unordered_map< int,int >;
    VI corpFlightBookings( VVI& B, int N, Map M={}, VI ans={} ){
        for( auto& b: B ){
            auto[ i,j,k ] = tie( b[ 0 ],b[ 1 ],b[ 2 ] );
            M[ i ] += k;
            M[ j+1 ] -= k;
        }
        for( auto i{ 1 }, k{ 0 }; i <= N; ++i ){
            k += M[ i ];
            ans.push_back( k );
        }
        return ans;
    }
};
*/

/*
class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Map = unordered_map< int,int >;
    VI corpFlightBookings( VVI& B, int N, Map M={}, VI ans={} ){
        for( auto& b: B ){
            auto[ i,j,k ] = tie( b[ 0 ],b[ 1 ],b[ 2 ] );
            M[ i ] += k;
            M[ j+1 ] -= k;
        }
        generate_n( back_inserter( ans ), N, [ &M, i=1, k=0 ]() mutable { return k += M[ i++ ]; });
        return ans;
    }
};
*/

class Solution {
public:
    using VI = vector< int >;
    using VVI = vector< VI >;
    using Deque = deque< int >;
    using Map = unordered_map< int,int >;
    using Memo = unordered_map< int,int >;
    VI corpFlightBookings( VVI& B, int N, Map M={} ){
        for( auto& b: B ){
            auto[ i,j,k ] = tie( b[ 0 ],b[ 1 ],b[ 2 ] );
            M[ i ] += k;
            M[ j+1 ] -= k;
        }
        Deque ans( N+1 );
        go( N, M, ans );
        ans.pop_front();
        return{ ans.begin(), ans.end() };
    }
private:
    int go( int i, Map& M, Deque& ans, Memo&& memo={{ 0,0 }} ){
        return ans[ i ] = memo[ i ] = ( memo.find( i ) != memo.end() )? memo[ i ] : M[ i ] + go( i-1, M, ans, move( memo ) );
    }
};

int main() {
    Solution::VVI B = {{1,2,10},{2,3,20},{2,5,25}};
    auto ans = Solution().corpFlightBookings( B, 5 );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ) ); cout << endl;
    return 0;
}


/*
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode( int val_ ) : val{ val_ }, left{ nullptr }, right{ nullptr } {}
};
class Solution {
public:
    using Delete = unordered_set< int >;
    using Parent = unordered_map< int,TreeNode* >;
    using Result = vector< TreeNode* >;
    using VI = vector< int >;
    Result delNodes( TreeNode* root, VI& del, Result R={} ){
        Delete D{ del.begin(), del.end() };
        Parent P{{ root->val, nullptr }};
        go( root, P );
        go( root, D, P, R );
        return R;
    }
private:
    void go( TreeNode* node, Parent& P ){
        if( node->left  ) P[ node->left->val  ] = node, go( node->left,  P );
        if( node->right ) P[ node->right->val ] = node, go( node->right, P );
    }
    void go( TreeNode* node, const Delete& D, Parent& P, Result& R ){
        auto parent = P[ node->val ];
        if( ( ! parent || D.find( parent->val ) != D.end() ) && D.find( node->val ) == D.end() )
            R.push_back( node );
        if( node->left  ) go( node->left,  D, P, R );
        if( node->right ) go( node->right, D, P, R );
        if( node->left  && D.find( node->left->val  ) != D.end() ) node->left  = nullptr;
        if( node->right && D.find( node->right->val ) != D.end() ) node->right = nullptr;
    }
};

int main() {

    Solution solution;
    TreeNode* root = new TreeNode( 1 );
    root->left = new TreeNode( 2 );
    root->right = new TreeNode( 3 );
    root->left->left = new TreeNode( 4 );
    root->left->right = new TreeNode( 5 );
    root->right->left = new TreeNode( 6 );
    root->right->right = new TreeNode( 7 );
    vector< int > toDelete{ 3,5 };
    auto ans = solution.delNodes( root, toDelete );

    return 0;
}
*/
