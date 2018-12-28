/*

Rank            Name                    Score    Finish Time    Q1 (3)          Q2 (4)          Q3 (5)    Q4 (8)
1853 / 3236     claytonjwong Virtual    7        1:41:03        0:37:57  *4     1:16:03  *1

Q1: https://leetcode.com/problems/valid-mountain-array/
A1: https://leetcode.com/problems/valid-mountain-array/discuss/195385/Concise-C%2B%2B

Q2: https://leetcode.com/problems/delete-columns-to-make-sorted/
A2: https://leetcode.com/problems/delete-columns-to-make-sorted/discuss/195394/Concise-C%2B%2B

Q3: https://leetcode.com/problems/di-string-match/
A3: https://leetcode.com/problems/di-string-match/discuss/195399/Concise-C%2B%2B

*/


#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
 
        if( A.size() < 3 )
            return false;
 
        for( auto pre=A.cbegin(), cur=next(pre);  cur != A.cend();  ++pre,++cur ){
            if( *pre < *cur )
                continue;
            if( pre == A.cbegin() )
                return false;
            for( ;  cur != A.cend();  ++pre,++cur ){
                if( *pre <= *cur )
                    return false;
            }
            return true;
        }
        return false;
    }
};
*/

/*
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
    
        if( A.size() < 3  ||  is_sorted( A.cbegin(), A.cend() )  || is_sorted( A.crbegin(), A.crend() ))
            return false;
        
        auto pre = A.cbegin(), cur = next( pre );
        for( ;  cur != A.cend();  ++pre,++cur )
            if( *pre >= *cur )
                break;

        for( ; cur != A.cend();  ++pre,++cur )
            if( *pre <= *cur )
                return false;

        return true;
    }
};
*/

/*
class Solution {
public:
    bool validMountainArray( vector<int>& A ) {
        auto left = adjacent_find( A.cbegin(), A.cend(), greater_equal<int>() );
        auto right = adjacent_find( A.crbegin(), A.crend(), greater_equal<int>() );
        return left != A.cend() && right != A.crend() && distance( left, right.base() ) == 1;
    }
};
*/

/*
class Solution {
public:
    bool validMountainArray( vector<int>& A ){
        return 1 == distance(
            adjacent_find( A.cbegin(), A.cend(), greater_equal<int>() ),
            adjacent_find( A.crbegin(), A.crend(), greater_equal<int>() ).base() );
    }
};
*/


/*
class Solution {
public:
    int minDeletionSize(vector<string>& A, int del=0) {
        int M=(int)A.size(), N=(int)A[0].size();
        for( int j=0;  j < N; ++j )
            for( int i=1;  i < M;  ++i )
                if( A[ i-1 ][ j ] > A[ i ][ j ] ){
                    ++del;
                    break;
                }
        return del;
    }
};
*/

/*
class Solution {
public:
    int minDeletionSize(vector<string>& A, int del=0) {
        int M=(int)A.size(), N=(int)A[0].size();
        vector<string> B;
        for( int j=0;  j < N; ++j ){
            string s;
            for( int i=0;  i < M;  ++i )
                s.push_back( A[i][j] );
            B.push_back( s );
        }
        for( const auto b: B ){
            if( ! is_sorted( b.begin(), b.end(), []( char lhs, char rhs ){
                return lhs <= rhs;
            })){
                ++del;
            }
        }
        return del;
    }
};
*/

/*
class Solution {
public:
    int minDeletionSize(vector<string>& A ) {
        int M = static_cast< int >( A.size() ), N = static_cast< int >( A[0].size() );
        vector<string> T( N, string( M, '\0' ) );
        for( int i{ 0 };  i < M;  ++i )
            for( int j{ 0 };  j < N;  ++j )
                T[ j ][ i ] = A[ i ][ j ];
        return static_cast< int >(
            count_if( T.cbegin(), T.cend(), []( const auto& s ){
                return adjacent_find( s.cbegin(), s.cend(), greater<char>() ) != s.cend();
            })
        );
    }
};
*/

/*
class Solution {
public:
    int minDeletionSize(vector<string>& A ) {
        int M = static_cast< int >( A.size() ), N = static_cast< int >( A[0].size() );
        vector<string> T( N, string( M, '\0' ) );
        for( int i{ 0 };  i < M;  ++i )
            for( int j{ 0 };  j < N;  ++j )
                T[ j ][ i ] = A[ i ][ j ];
        return static_cast< int >(
            count_if( T.cbegin(), T.cend(), []( const auto& s ){
                return ! is_sorted( s.cbegin(), s.cend(), less<char>() );
            })
        );
    }
};
*/

// wrong answer
//class Solution {
//public:
//    int minDeletionSize(vector<string>& A, int del=0 ) {
//        for( int i = 0;  i < A[0].size();  ++i )
//            if( is_sorted( A.cbegin(), A.cend(), [=]( const auto& above, const auto& below ){
//                return above[ i ] < below[ i ];
//            })){
//                ++del;
//            }
//        return del;
//    }
//};

/*
class Solution {
public:
    vector<int> diStringMatch(string S, vector<int> ans={}) {
        int i=0, j=static_cast<int>(S.size());
        for ( const auto c: S )
            if( c == 'I' )
                ans.push_back( i++ );
            else
                ans.push_back( j-- );
        ans.push_back( i );
        return ans;
    }
};
*/

/*
class Solution {
public:
    vector<int> diStringMatch( string S, vector<int> ans={} ) {
        int i = 0, j = static_cast< int >( S.size() );
        for ( const auto c: S )
            ans.push_back( c == 'I' ? i++ : j-- );
        ans.push_back( i );
        return ans;
    }
};
*/

/*
class Solution {
public:
    vector<int> diStringMatch( string S, vector<int> ans={} ) {
        auto i = S.cbegin();
        auto j = S.crbegin();
        for ( const auto c: S )
                ans.push_back( c == 'I' ? distance(i++ : *j++ );
        ans.push_back( *i );
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    /*
    vector<int> A = {
        1,2,3,1
    };
    Solution s;
    
    cout << s.validMountainArray( A ) << endl;
    */
    
    
    Solution s;
    vector<string> A = {
        "rrjk",
        "furt",
        "guzm"
    };
    cout << s.minDeletionSize( A ) << endl;
    
    
    
    
    return 0;
}
