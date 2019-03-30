/*

 Rank	        Name	        Score	Finish Time 	Q1 (4)	        Q2 (4)	    Q3 (5)	    Q4 (5)
 2388 / 4456	claytonjwong 	4	    1:18:50	        1:03:50  *3

 Note to self: I over-complicated the first question and eventually pruned a DFS+BT to no longer TLE,
 but that consumed the first hour and fifteen minutes of the contest.  So I ended up with 3 bugs for each TLE,
 and I had no time left for the other questions.  Next time keep it simple!

 On a positive note, my original solution without additional pruning constraints would have worked for any arbitrary K.

 Q1: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
 A1: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/discuss/261248/C%2B%2B-and-Python3-solutions



*/

#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

/*
// complicated
class Solution {
public:

    using VI = vector< int >;

    bool canThreePartsEqualSum( VI& A ){
        VI S{ A };
        for( auto N = static_cast< int >( S.size() ), i{ N-2 }; i >=0; --i )
            S[ i ] += S[ i+1 ];
        return go( A, S );
    }

private:

    bool go( VI& A, VI& S, int target=0, int start=0, int K=3 ){
        for( auto N = static_cast< int >( A.size() ), i{ start }, sum{ 0 }; i <= N-K; ++i ){
            sum += A[ i ];
            if(( K == 3 )  &&  ( S[ i+1 ]%2 == 0 )  &&  ( S[ i+1 ]/2 == sum )  &&  ( go( A, S, sum, i+1, K-1 )))
                return true;
            if(( K == 2 )  &&  ( sum == target )  &&  ( sum == S[ i+1 ] ))
                return true;
        }
        return false;
    }
};


int main(){

    Solution solution;

//    Solution::VI A{ 0,2,1,-6,6,-7,9,1,2,0,1 };
//    Solution::VI A{0,2,1,-6,6,7,9,-1,2,0,1};
    Solution::VI A{ 6, 2, 4, 2, 4 };
//Solution::VI A{3,3,6,5,-2,2,5,1,-9,4};
    cout << solution.canThreePartsEqualSum( A ) << endl;

    return 0;
}
*/

// simple
class Solution {
public:
    bool canThreePartsEqualSum( vector< int >& A, int cur=0, int K=0 ) {
        auto target = accumulate( A.begin(), A.end(), 0 ) / 3;
        for( auto x: A ){
            cur += x;
            if( cur == target )
                cur = 0,
                ++K;
        }
        return K == 3;
    }
};

int main(){

    Solution solution;

    vector< int > A{ 0,2,1,-6,6,-7,9,1,2,0,1 };
//    Solution::VI A{0,2,1,-6,6,7,9,-1,2,0,1};
//    Solution::VI A{ 6, 2, 4, 2, 4 };
//Solution::VI A{3,3,6,5,-2,2,5,1,-9,4};
    cout << solution.canThreePartsEqualSum( A ) << endl;

    return 0;
}

/*
class Solution {
public:
    int smallestRepunitDivByK( int K ){
        for( auto N{ 0 }, i{ 1 }; i < 1e5; ++i )
            if(( N = ( N * 10 + 1 ) % K ) == 0 )
                return i;
        return -1;
    }
};

int main(){

    Solution solution;
    cout << solution.smallestRepunitDivByK( 1 ) << endl;
    cout << solution.smallestRepunitDivByK( 2 ) << endl;
    cout << solution.smallestRepunitDivByK( 3 ) << endl;

    return 0;
}
*/
