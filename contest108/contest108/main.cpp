/*
 
 Rank           Name            Score    Finish Time    Q1 (4)    Q2 (5)    Q3 (5)          Q4 (6)
 1440 / 3645    claytonjwong    9        1:19:02        0:15:36             1:09:02  2
 
*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int numUniqueEmails(vector<string>& emails, unordered_set<string> unique={} ) {
        for( const auto& email: emails ){
            auto pivot = email.find_first_of('@'); auto name = email.substr( 0, pivot ), domain = email.substr( pivot );
            name.erase( remove_if( name.begin(), name.end(), [&]( const auto& c ){ return c == '.'; }), name.end() );
            unique.insert( name.erase( name.find_first_of('+') ) + domain );
        }
        return static_cast<int>( unique.size() );
    }
};


// TLE
/*
using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
    int M{ 0 }, N{ 0 }, mini{ numeric_limits<int>::max() };
    int dfs( const VVI& A, int prevCol, int row=0, int sum=0 ){
        if( row == A.size() )
            return sum;
        int beg=max(0,prevCol-1), end=min(N-1,prevCol+1);
        for( int col = beg;  col <= end;  ++col ){
            sum += A[row][col];
            mini = min( mini, dfs( A, col, row + 1, sum ) );
            sum -= A[row][col];
        }
        return mini;
    }
public:
    int minFallingPathSum( VVI& A, int ans=0 ) {
        M = static_cast<int>( A.size() ), N = static_cast<int>( A[0].size() );
        for( int col=0; col < N; ++col ){
            dfs( A, col );
        }
        return mini;
    }
};
*/

/*
using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    int minFallingPathSum( VVI& A, int ans=0 ) {
        auto M = static_cast<int>( A.size() ), N = static_cast<int>( A[0].size() );
        VVI dp( M, VI(N) );
        for( int j=0; j < N; ++j )
            dp[0][j] = A[0][j];
        for( int i=1; i < M; ++i ){
            for( int j=0; j < N; ++j ){
                int L=( j-1 < 0 ) ? 0 : j-1, R=( j+1 < N ) ? j+1 : N-1;
                auto cur = A[i][j], left = cur+dp[i-1][L], middle = cur+dp[i-1][j], right = cur+dp[i-1][R];
                dp[i][j] = min({ left, middle, right });
            }
        }
        return *min_element( dp.back().begin(), dp.back().end() );
    }
};
*/

/*
using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    int minFallingPathSum( VVI& A, int ans=0 ) {
        for( int i=1, M=static_cast<int>( A.size() ); i < M; ++i )
            for( int j=0, N=static_cast<int>( A[0].size() ); j < N; ++j )
                A[i][j] = min({ A[i][j]+A[ i-1 ][max( 0, j-1 )], A[i][j]+A[i-1][j], A[i][j]+A[i-1][min( j+1, N-1 )] });
        return *min_element( A.back().begin(), A.back().end() );
    }
};
*/



int main(int argc, const char * argv[]) {
    
    
    Solution s;
    vector<string> A={"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    cout << s.numUniqueEmails(A) << endl;
    
    /*
    VVI A = {
        {1,2,3},
        {4,5,6},
        {7,8,-9}
    };
    Solution s;
    cout << s.minFallingPathSum( A ) << endl;
    */
    return 0;
}
