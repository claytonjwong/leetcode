/*

    yay!  got 4 out of 4!  lucky contest #127

    https://leetcode.com/contest/weekly-contest-127

    Rank	        Name	        Score	Finish Time 	Q1 (4)	        Q2 (4)	    Q3 (5)	    Q4 (6)
    1119 / 4033	    claytonjwong 	19	    1:14:00	        0:20:51  2	    0:37:04	    0:53:00	    1:04:00

    Q1: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
    A1: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/discuss/252205/Concise-C%2B%2B

    Q2: https://leetcode.com/problems/clumsy-factorial/
    A2: https://leetcode.com/problems/clumsy-factorial/discuss/252210/Concise-C%2B%2B

    Q3: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
    A3: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/252219/Concise-C%2B%2B

    Q4: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
    A4: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252236/Concise-C%2B%2B

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>


using namespace std;


/*
//class Solution {
//public:
//
//    int largestSumAfterKNegations( vector<int>& A, int K, int i=0 )
//    {
//        sort( A.begin(), A.end() );
//        for(; i < K && i < A.size() && A[ i ] < 0; ++i, A[ i ] = -A[ i ] );
//        K -= i;
//        if( K - i > 0 ){
//            sort( A.begin(), A.end() );
//            if( A[ 0 ] > 0 && K - i % 2 == 1 ){
//                A[ 0 ] = -A[ 0 ];
//            }
//        }
//        return accumulate( A.begin(), A.end(), 0 );
//    }
//};

//class Solution {
//public:
//
//    int largestSumAfterKNegations( vector<int>& A, int K )
//    {
//        sort( A.begin(), A.end() );
//        for( auto i{ 0 }; K > 0 && i < A.size() && A[ i ] < 0; A[ i ] = -A[ i ], ++i, --K );
//        for( auto it = min_element( A.begin(), A.end() ); *it > 0 && K > 0 && K % 2 == 1; *it = -*it );
//        return accumulate( A.begin(), A.end(), 0 );
//    }
//};

class Solution {
public:

    int largestSumAfterKNegations( vector<int>& A, int K, int ans=0 )
    {
        priority_queue< int, vector< int >, greater< int >> q{ A.begin(), A.end() };
        for( auto top{ 0 }; K--; top = -1 * q.top(), q.pop(), q.push( top ) );
        for(; ! q.empty(); ans += q.top(), q.pop() );
        return ans;
    }
};



int main()
{
    vector<int> A = {-2,9,9,8,4};
    int K = 5;
    Solution s;
    cout << s.largestSumAfterKNegations( A, K ) << endl;


    return 0;
}
*/


/*
class Solution {
public:

    int clumsy( int N )
    {
        vector<int> A{ N };
        for( auto i{ N-1 }, j{ 0 }; i > 0; --i, ++j )
            if(      j % 4 == 0 ) A.back() *= i;
            else if( j % 4 == 1 ) A.back() /= i;
            else if( j % 4 == 2 ) A.push_back(  i );
            else if( j % 4 == 3 ) A.push_back( -i );
        return static_cast< int >( accumulate( A.begin(), A.end(), 0 ) );
    }

};

int main(){

    Solution s;
    cout << s.clumsy( 10 ) << endl;

    return 0;
}
*/

/*
class Solution {
public:

    static constexpr auto INF = numeric_limits< int >::max();
    using VI = vector< int >;

    int minDominoRotations( VI& A, VI& B ) {
        return min( minR( A,B ), minR( B,A ) );
    }

private:

    int minR( VI& A, VI& B, int ans=INF )
    {
        for( auto target{ 1 }, swap{ 0 }, ok{ 1 }; target < 7; ++target, swap=0, ok=1 ){
            for( auto j{ 0 }; j < A.size() && ok; ++j )
                if( A[ j ] == target )
                    continue;
                else if( B[ j ] == target )
                    ++swap;
                else
                    ok = 0;
            if( ans > swap && ok )
                ans = swap;
        }
        return ans < INF ? ans : -1;
    }
};

int main(){
    vector<int> A={3,5,1,2,3}, B={3,6,3,3,4};
    Solution s;
    cout << s.minDominoRotations(A,B) << endl;
}
*/


struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode( int val ) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:

    TreeNode* bstFromPreorder( vector<int>& A )
    {
        TreeNode* root = new TreeNode( A[0] );
        for( auto x: A )
            go( root, x );
        return root;
    }

private:

    void go( TreeNode* root, int x )
    {
        if( x < root->val ){
            if( ! root->left )
                root->left = new TreeNode( x );
            else
                go( root->left, x );
        }
        if( x > root->val ){
            if( ! root->right )
                root->right = new TreeNode( x );
            else
                go( root->right, x );
        }
    }

};

int main(){
    vector<int> A={8,5,1,7,10,12};
    Solution s;
    auto root = s.bstFromPreorder(A);
    return 0;
}
