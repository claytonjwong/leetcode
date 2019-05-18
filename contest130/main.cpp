

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

/*
class Solution {
public:
    using VB = vector< bool >;
    using VI = vector< int >;
    VB prefixesDivBy5( VI& bits, int N=0, VB ans={} ){
        for( auto bit: bits )
            N = (( N << 1 ) + bit ) % 5,
            ans.push_back( N == 0 );
        return ans;
    }
};
*/


class Solution {
public:
    using VB = vector< bool >;
    using VI = vector< int >;
    VB prefixesDivBy5( VI& A, int N=0, VB ans={} ) {
        transform( A.begin(), A.end(), back_inserter( ans ), [&]( auto bit ){ N = (( N << 1 ) + bit ) % 5; return N == 0; });
        return ans;
    }
};


/*
int main() {
    Solution solution;
    vector<int> A{ 0,1,1,1,1,1 };
    auto ans = solution.prefixesDivBy5( A );
    copy( ans.begin(), ans.end(), ostream_iterator< bool >( cout, " " ));
    cout << endl;
    return 0;
}
*/

//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode( int val ) : val{ val }, next{ nullptr } {}
//};

// TLE
//class Solution {
//public:
//    vector<int> nextLargerNodes(ListNode* head, vector<int> ans={} ){
//        vector< int > A;
//        multimap< int,int > map;
//        auto i{ 0 };
//        for( auto it{ head }; it; A.push_back( it->val ), map.insert({ it->val, i++ }), it=( it->next ));
//        for( auto i{ 0 }; i < A.size(); ++i ){
//            auto next_pair = map.upper_bound( A[ i ] );
//            set<int> S;
//            for(; next_pair != map.end(); ++next_pair ){
//                cout << "A[ " << i << " ] = " << A[ i ] << "    next_pair->first = " << next_pair->first << "    next_pair->second = " << next_pair->second << endl;
//                S.insert( next_pair->second );
//            }
//            cout << endl << "S: ";
//            copy( S.begin(), S.end(), ostream_iterator< int >( cout, " " ));
//            cout << endl;
//            auto next_index = S.upper_bound( i );
//            cout << "X: " << (( next_index != S.end() )? A[ *next_index ] : 0 ) << endl;
//            cout << endl;
//            cout << endl;
//
//
//            ans.push_back(( next_index != S.end() )? A[ *next_index ] : 0 );
//        }
//        return ans;
//    }
//};

// TLE
//class Solution {
//public:
//    const static auto INF = numeric_limits< int >::max();
//    vector<int> nextLargerNodes(ListNode* head, vector<int> ans={} ){
//        vector< int > A;
//        multimap< int,int > map;
//        auto i{ 0 };
//        for( auto it{ head }; it; A.push_back( it->val ), map.insert({ it->val, i++ }), it=( it->next ));
//        for( auto i{ 0 }; i < A.size(); ++i ){
//            auto next_pair = map.upper_bound( A[ i ] );
//            auto best{ INF };
//            for(; next_pair != map.end(); ++next_pair ){
//                cout << "A[ " << i << " ] = " << A[ i ] << "    next_pair->first = " << next_pair->first << "    next_pair->second = " << next_pair->second << endl;
//                if( best > next_pair->second && next_pair->second > i ) {
//                    best = next_pair->second;
//                    cout << "best = " << best << "    A[ best ] = " << A[ best ] << endl;
//                }
//            }
//            cout << endl;
//            cout << "X: " << (( best != INF )? A[ best ] : 0 ) << endl;
//            cout << endl;
//            cout << endl;
//
//
//            ans.push_back(( best != INF )? A[ best ] : 0 );
//        }
//        return ans;
//    }
//};
//
//int main() {
//    Solution solution;
//    auto head = new ListNode( 9 );
//    head->next = new ListNode( 8 );
//    head->next->next = new ListNode( 1 );
//    head->next->next->next = new ListNode( 4 );
//    head->next->next->next->next = new ListNode( 2 );
//    head->next->next->next->next->next = new ListNode( 5 );
//    head->next->next->next->next->next->next = new ListNode( 7 );
//    head->next->next->next->next->next->next->next = new ListNode( 5 );
//    auto ans = solution.nextLargerNodes( head );
//    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, " " ));
//    return 0;
//}


//Input:
//[9,8,1,4,2,5,7,5]
//Output:
//[0,0,4,7,7,7,0,0]
//Expected:
//[0,0,4,5,5,7,0,0]


class Solution {
public:
    using VI = vector< int >; using VVI = vector< VI >; using PII = pair< int,int >;
    struct cmp{ size_t operator()( const PII& p ) const { return 501 * p.first + p.second; }};
    using Seen = unordered_set< PII, cmp >;
    int numEnclaves( VVI& A, Seen seen={}, int ans=0 ){
        auto M{ A.size() }, N{ A[ 0 ].size() };
        for( auto i{ 0 }; i < M; ++i ) for( auto j{ 0 }, cnt{ 0 }, off{ 0 }; j < N; ++j, cnt=( 0 ), off=( 0 ))
            dfs( A, M, N, i, j, cnt, off, seen ),
            ans += ( ! off )? cnt : 0;
        return ans;
    }
private:
    VVI D = {{ -1,0 }, { 0,1 }, { 1,0 }, { 0,-1 }};
    void dfs( VVI& A, int M, int N, int i, int j, int& cnt, int& off, Seen& seen ){
        if(   A[ i ][ j ] && ( i == 0 || j == 0 || i == M-1 || j == N-1 )){ off = true; return; }
        if( ! A[ i ][ j ] || ! seen.insert({ i,j }).second ) return;
        ++cnt; for( auto dir: D ) dfs( A, M, N, ( i + dir[ 0 ] ), ( j + dir[ 1 ] ), cnt, off, seen );
    }
};

int main() {
    Solution solution;
    Solution::VVI A = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    cout << solution.numEnclaves( A ) << endl;
    return 0;
}








