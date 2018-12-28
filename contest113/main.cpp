/*

https://leetcode.com/contest/weekly-contest-113/ranking/

Rank	        Name	        Score	Finish Time 	Q1 (4)	        Q2 (5)	    Q3 (5)	    Q4 (8)
756 / 3549	    claytonjwong 	14	    1:33:15	         0:25:31  *2	1:00:15	    1:23:15

Q1: https://leetcode.com/problems/largest-time-for-given-digits/
A1: https://leetcode.com/problems/largest-time-for-given-digits/discuss/200498/C%2B%2B-max-valid-permutation

Q2: https://leetcode.com/problems/flip-equivalent-binary-trees/
A2: https://leetcode.com/problems/flip-equivalent-binary-trees/discuss/200496/Concise-C%2B%2B

Q3: https://leetcode.com/problems/reveal-cards-in-increasing-order/
A3: https://leetcode.com/problems/reveal-cards-in-increasing-order/discuss/200489/Concise-C%2B%2B

Q4: https://leetcode.com/problems/largest-component-size-by-common-factor/submissions/
A4: https://leetcode.com/problems/largest-component-size-by-common-factor/discuss/204260/Concise-C%2B%2B

*/


#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

/*
using VI = vector< int >;
using OS = ostringstream;
using Iter = ostream_iterator< int >;
class Solution {
    string to_time( const VI& A ){
        int hour = A[0] * 10  +  A[1], minute = A[2] * 10 + A[3];
        return ( 0 <= hour && hour <= 23  &&  0 <= minute && minute <= 59 )
            ? string{ to_char(A[0]), to_char(A[1]), ':', to_char(A[2]), to_char(A[3]) } : "";
    }
    char to_char( int x ){  return char( '0' + x );  }
public:
    string largestTimeFromDigits( vector<int>& A, string ans = "" ){
        sort( A.begin(), A.end() );
        do{
            auto next = to_time( A );
            if( ans < next )
                ans = next;
        }while( next_permutation( A.begin(), A.end() ) );

        return ans;
    }
};
*/

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode( int x ) : val{ x }, left{ nullptr }, right{ nullptr } {}
};




/*
using T = TreeNode * ;
class Solution {
public:
    bool flipEquiv( T t1, T t2 ){
        if( ! t1  &&  ! t2 )
            return true;
        if( ! t1  ||  ! t2  ||  t1->val != t2->val )
            return false;
        if( flipEquiv( t1->left, t2->left ) && flipEquiv( t1->right, t2->right ) )
            return true;
        return flipEquiv( t1->right, t2->left ) && flipEquiv( t1->left, t2->right );
    }
};

#define L left
#define R right
using TN = TreeNode * ;
class Solution {
    bool go( TN t1, TN t2 ){
        if( ! t1  &&  ! t2 )
            return true;
        if( ! t1  ||  ! t2  ||  t1->val != t2->val )
            return false;
        if( go( t1->L, t2->L ) && go( t1->R, t2->R ) )
            return true;
        return go( t1->R, t2->L ) && go( t1->L, t2->R );
    }
public:
    bool flipEquiv( TN t1, TN t2 ){
        return go( t1, t2 );
    }
};


#define L left
#define R right
using T = TreeNode * ;
class Solution {
    bool go( T _1, T _2 ){
        if( ! _1  &&  ! _2 )
            return true;
        if( ! _1  ||  ! _2  ||  _1->val != _2->val )
            return false;
        if( go( _1->L, _2->L ) && go( _1->R, _2->R ) )
            return true;
        return go( _1->R, _2->L ) && go( _1->L, _2->R );
    }
public:
    bool flipEquiv( T _1, T _2 ){
        return go( _1, _2 );
    }
};
*/

/*
#define L left
#define R right
using T = TreeNode * ;
class Solution{
    bool go( T _1, T _2 ){
        return
              ( ! _1  &&  ! _2 )                            ?  true   // base case 1: both null
            : ( ! _1  ||  ! _2  ||  _1->val != _2->val )    ?  false  // base case 2: one-or-the-other is null  OR  values differ
            : ( go( _1->L, _2->L ) && go( _1->R, _2->R ) )  ?  true   // recursive step 1: "as is"
            : ( go( _1->R, _2->L ) && go( _1->L, _2->R ) );           // recursive step 2: swapped ( i.e. swap( _1->left, _1->right )
    }                                                                 //                             xor  swap( _2->left, _2->right ) )
public:
    bool flipEquiv( T _1, T _2 ){
        return go( _1, _2 );
    }
};
*/

/*
#define L left
#define R right
using T = TreeNode * ;
class Solution{
    bool go( T _1, T _2 ){
        return
              ( ! _1  &&  ! _2 )                            ?  true
            : ( ! _1  ||  ! _2  ||  _1->val != _2->val )    ?  false
            : ( go( _1->L, _2->L ) && go( _1->R, _2->R ) )  ?  true
            : ( go( _1->L, _2->R ) && go( _1->R, _2->L ) ); // <---  i.e.  swap( _2->left, _2->right )
    }
public:
    bool flipEquiv( T _1, T _2 ){
        return go( _1, _2 );
    }
};
*/

/*
#define L left
#define R right
using T = TreeNode * ;
class Solution{
    bool go( T _1, T _2 ){
        return
              ( ! _1  &&  ! _2 )                            ?   true
            : ( ! _1  ||  ! _2  ||  _1->val != _2->val )    ?   false
            : ( go( _1->L, _2->L ) && go( _1->R, _2->R ) )  ||  ( go( _1->L, _2->R ) && go( _1->R, _2->L ) );
    }
public:
    bool flipEquiv( T _1, T _2 ){
        return go( _1, _2 );
    }
};
*/

//        if( t1->left == t2->left )
//            cout << "left equal" << endl;
//
//        if( t1->right == t2->right )
//            cout << "right equal" << endl;
//
//        if( t1->left == t2->right )
//            cout << "left mirror equal" << endl;
//
//        if( t1->right == t2->left )
//            cout << "righjt mirror equal" << endl;


void print(deque<int> d){
    for( auto x: d ){
        cout << x << ",";
    }

}

/*
#define push push_front
#define pop pop_back
using VI = vector< int >;
using DI = deque< int >;
class Solution {
public:
    VI deckRevealedIncreasing( VI& deck, DI ans={} ){
        if( deck.size() == 1 )
            return deck;
        sort( deck.begin(), deck.end() );
        ans.push( deck.back() ), deck.pop();
        ans.push( deck.back() ), deck.pop();
        while( ! deck.empty() ){
            ans.push( ans.back() ), ans.pop();
            ans.push( deck.back() ), deck.pop();
        }
        return { ans.cbegin(), ans.cend() };
    }
};
*/

/*
#define push push_front
#define pop pop_back
using VI = vector< int >;
using DI = deque< int >;
class Solution {
public:
    VI deckRevealedIncreasing( VI& deck, DI ans={} ){
        if( deck.size() == 1 )
            return deck;
        sort( deck.begin(), deck.end() );
        for( ans.push( deck.back() ), deck.pop(),
             ans.push( deck.back() ), deck.pop();  ! deck.empty();  ans.push( ans.back() ), ans.pop(),
                                                                    ans.push( deck.back() ), deck.pop() );
        return { ans.cbegin(), ans.cend() };
    }
};
*/

/*
#define push push_front
#define pop pop_back
using VI = vector< int >;
using DI = deque< int >;
class Solution {
public:
    VI deckRevealedIncreasing( VI& deck ){
        if( deck.size() == 1 )
            return deck;
        sort( deck.begin(), deck.end() );
        DI ans({ deck.end()[ -2 ], deck.end()[ -1 ] });  deck.resize( deck.size() - 2 );
        while( ! deck.empty() ){
            ans.push( ans.back() ), ans.pop();
            ans.push( deck.back() ), deck.pop();
        }
        return { ans.cbegin(), ans.cend() };
    }
};
*/



/*
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> ans;
        if( deck.size() == 1 )
            return deck;
        sort( deck.begin(), deck.end() );
        ans.push_front( deck.back() );
        deck.pop_back();
        ans.push_front( deck.back() );
        deck.pop_back();
        while( ! deck.empty() ){
            ans.push_front( ans.back() );
            ans.pop_back();
            ans.push_front(deck.back());
            deck.pop_back();
        }
        return { ans.begin(), ans.end() };
    }
};
*/

/*
using VI = vector< int >;
using Counter = unordered_map< int, int >;
class Solution {
    VI P;
    VI getFactors( const int x ) const {
        VI factors;
        for( int d{ 2 }; d <= sqrt( x ); ++d )
            if( x % d == 0 )
                factors.push_back( d ), factors.push_back( x / d );
        return factors;
    }
    void Union( int a, int b ){
        a = Find( a ), b = Find( b );
        P[ a ] = b;
    }
    int Find( const int x ){
        if( P[ x ] != x )
            P[ x ] = Find( P[ x ] );
        return P[ x ];
    }
public:
    Solution() : P{ VI( 100001 ) } { for( size_t x{ 0 }; x < P.size(); ++x ) P[ x ] = x; }
    int largestComponentSize( VI& A, Counter count={}, int ans=0 ){
        for( const auto num: A ){
            const auto factors = getFactors( num );
            for( const auto factor: factors )
                Union( num, factor );
        }
        for( const auto num: A ){
            const auto parent = Find( num );
            ans = max( ans, ++count[ parent ] );
        }
        return ans;
    }
};
*/

/*
using VI = vector< int >;
using Counter = unordered_map< int, int >;
class Solution {
    VI P;
    VI getFactors( const int x, VI factors={} ) const {
        for( int d{ 2 }; d <= sqrt( x ); ++d ) if( x % d == 0 ) factors.push_back( d ), factors.push_back( x / d );
        return factors;
    }
    void Union( const int a, const int b ){ P[ Find( a ) ] = Find( b ); }
    int Find( const int x ){ return P[ x ] = ( P[ x ] == x )? x : Find( P[ x ] ); }
public:
    Solution() : P{ VI( 100001 ) } { for( size_t x{ 0 }; x < P.size(); ++x ) P[ x ] = x; }
    int largestComponentSize( VI& A, Counter count={}, int ans=0 ){
        for( const auto num: A ) for( const auto factor: getFactors( num ) ) Union( num, factor );
        for( const auto num: A ) ans = max( ans, ++count[ Find( num ) ] );
        return ans;
    }
};
*/

using VI = vector< int >;
using Counter = unordered_map< int, int >;
class Solution {
    VI P;
    VI getFactors( int x, VI factors={} ){
        for( auto d{ 2 }; d <= sqrt( x ); ++d ) if( x % d == 0 ) factors.push_back( d ), factors.push_back( x / d );
        return factors;
    }
    void Union( int a, int b ){ P[ Find( a ) ] = Find( b ); }
    int Find( int x ){ return P[ x ] = ( P[ x ] == x )? x : Find( P[ x ] ); }
public:
    Solution() : P{ VI( 100001 ) } { for( size_t x{ 0 }; x < P.size(); ++x ) P[ x ] = x; }
    int largestComponentSize( VI& A, Counter count={}, int ans=0 ){
        for( auto num: A ) for( auto factor: getFactors( num ) ) Union( num, factor );
        for( auto num: A ) ans = max( ans, ++count[ Find( num ) ] );
        return ans;
    }
};

int main() {

//    Solution s;
//    VI A{1,9,6,0};
//    cout << s.largestTimeFromDigits(A) << endl;

//    TreeNode* t1 = new TreeNode(0);
//    t1->left = new TreeNode(1);
//    t1->left->left = new TreeNode(2);
//    TreeNode* t2 = new TreeNode(0);
//    t2->right = new TreeNode(1);
//    t2->right->right = new TreeNode(3);
//
//    Solution s;
//    cout << s.flipEquiv(t1,t2) << endl;

//    Solution s;
//    vector<int> A{17,13,11,2,3,5,7};
//    auto r = s.deckRevealedIncreasing(A);

    Solution s;

    VI A{ 20,50,9,63 };
    cout << s.largestComponentSize( A ) << endl;

    return 0;
}








