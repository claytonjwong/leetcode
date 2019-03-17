/*

Rank	        Name	        Score	Finish Time 	Q1 (2)	        Q2 (4)	           Q3 (6)   	Q4 (8)
2189 / 5164	    claytonjwong 	6	    1:03:23	        0:07:31  *1	    0:48:23  *2

https://leetcode.com/contest/weekly-contest-128

Q1: https://leetcode.com/problems/complement-of-base-10-integer/
A1: https://leetcode.com/problems/complement-of-base-10-integer/discuss/256767/Concise-C%2B%2B

Q2: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
A2: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/256716/Concise-C%2B%2B

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <bitset>
#include <numeric>
//bitset< 32 > B( N );

using namespace std;

/*
class Solution {
public:
    int bitwiseComplement( int N ){
        if( N == 0 )
            return 1;
        for( int i{ 30 }, flip{ 0 }; i >= 0; --i ){
            if ( ! flip && N & (1 << i))
                flip = 1;
            if( flip )
                N ^= 1 << i;
        }
        return N;
    }
};
*/

/*
class Solution {
public:
    int bitwiseComplement( int N ){
        for( auto i{ 30 }; i >= 0; --i ){
            if( N & ( 1 << i )){
                auto mask{( 1 << ( i+1 )) - 1 };
                return N ^ mask;
            }
        }
        return 1;
    }
};

int main()
{
    Solution solution;

    cout << solution.bitwiseComplement( 5 ) << endl;
    cout << solution.bitwiseComplement( 7 ) << endl;
    cout << solution.bitwiseComplement( 10 ) << endl;

    return 0;
}
*/

//class Solution {
//public:
//    int numPairsDivisibleBy60(vector<int>& A, int ans=0 ) {
//        auto N{ A.size() };
//        for( int i{ 0 }; i < N-1; ++i )
//            for( int j{ i+1 }; j < N; ++j )
//                if(( A[ i ] + A[ j ] ) % 60 == 0 )
//                    cout << A[ i ] << ", " << A[ j ] << endl;
//        return ans;
//    }
//};


class Solution {
public:

    using Collection = vector< int >;
    using Counter = unordered_map< int, int >;

    int numPairsDivisibleBy60( Collection& times, Counter C={} ){
        for( auto t: times )
            ++C[ t % 60 ];
        auto M{ C[ 0 ] },
             N{ C[ 30 ] },
             P{ N * ( N-1 ) / 2 +
                M * ( M-1 ) / 2 };
        for( auto t{ 1 }; t < 30; ++t )
            P += C[ t ] * C[ 60 - t ];
        return P;
    }

};


int main(){
    Solution solution;
    vector< int > A{ 15,63,451,213,37,209,343,319 };
    cout << solution.numPairsDivisibleBy60( A ) << endl;
}

// incorrect solution
/*
class Solution {
public:
    int shipWithinDays(vector<int>& W, int D) {
        vector< int > bucket( D, 0 );
        auto sum = accumulate( W.begin(), W.end(), 0 );
        auto avg = sum / D;
        auto it = W.begin();
        for( int i{ 0 }; i < D; ++i ){
            for(; bucket[ i ] < avg && it != W.end(); bucket[ i ] += *it++ );
        }
        return *max_element( bucket.begin(), bucket.end() );
    }
};

int main(){
    Solution solution;
    vector<int> W{ 1,2,3,4,5,6,7,8,9,10 };
    int D{ 5 };
    cout << solution.shipWithinDays( W, D ) << endl;
    return 0;
}
*/
