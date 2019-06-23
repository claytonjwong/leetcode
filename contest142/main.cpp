/*
 * https://leetcode.com/contest/weekly-contest-142/ranking
 *
 * Rank	        Name	        Score	Finish Time 	Q1 (5)	        Q2 (5)	    Q3 (8)	    Q4 (8)
 * 1531 / 4504	claytonjwong 	10	    1:20:05	        1:15:05  *1	    0:54:04
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

// too much memory consumed for counting sort
/*
using VI = vector< int >;
using VD = vector< double >;
class Solution {
public:
    VD sampleStats( VI& cnt ){
        double mind{ 256.0 }, maxd{ -1.0 }, mode{ 0.0 }, sum{ 0.0 }, median{ 0.0 };
        const auto N = cnt.size();
        auto totalCnt{ 0 }, modeCnt{ 0 };
        for( auto i{ 0 }; i < N; ++i ){
            if( cnt[ i ] == 0 )
                continue;
            if( mind > i ) mind = i;
            if( maxd < i ) maxd = i;
            if( modeCnt < cnt[ i ] ){
                modeCnt = cnt[ i ];
                mode = i;
            }
            sum += i * cnt[ i ];
            totalCnt += cnt[ i ];
        }
        auto mean = sum / totalCnt;
        auto A = countingSort( cnt );
        auto M = A.size();
        if( M == 1 ){
            median = A.back();
        } else if( M > 1 ){
            if( M % 2 == 0 )
                median = static_cast< double >( A[ M/2 - 1 ] + A[ M/2 ] ) / 2.0;
            else
                median = A[ M/2 ];
        }
        return{ mind, maxd, mean, median, mode };
    }
private:
    VI countingSort( const VI& cnt, VI A={} ){
        A.reserve( 256 );
        const auto N = cnt.size();
        for( auto i{ 0 }; i < N; ++i )
            generate_n( back_inserter( A ), cnt[ i ], [=](){ return i; });
        return A;
    }
};
*/

/*
using VI = vector< int >;
using VD = vector< double >;
class Solution {
public:
    VD sampleStats( VI& cnt ){
        double mind{ 256.0 }, maxd{ -1.0 }, mode{ 0.0 }, sum{ 0.0 };
        const auto N = cnt.size();
        auto totalCnt{ 0 }, modeCnt{ 0 };
        for( auto i{ 0 }; i < N; ++i ){
            if( cnt[ i ] == 0 )
                continue;
            if( mind > i ) mind = i;
            if( maxd < i ) maxd = i;
            if( modeCnt < cnt[ i ] ){
                modeCnt = cnt[ i ];
                mode = i;
            }
            sum += i * cnt[ i ];
            totalCnt += cnt[ i ];
        }
        auto mean = sum / totalCnt;
        auto median = getMedian( cnt, totalCnt );
        return{ mind, maxd, mean, median, mode };
    }
private:
    double getMedian( const VI& cnt, int totalCnt, double median=0.0 ){
        auto T1 = totalCnt / 2,
             T2 = T1 + 1;
        auto isEven = totalCnt % 2 == 0;
        totalCnt = 0;
        auto i{ 0 };
        const auto N = cnt.size();
        for(; i < N; ++i ){
            totalCnt += cnt[ i ];
            if( totalCnt >= T1 ){
                median = i;
                break;
            }
        }
        if( isEven ){
            if( totalCnt >= T2 ){
                median += i;
                median /= 2.0;
            } else {
                for( ++i; i < N; ++i ){
                    totalCnt += cnt[ i ];
                    if( totalCnt >= T2 ){
                        median += i;
                        median /= 2.0;
                        break;
                    }
                }
            }
        }
        return median;
    }
};

int main() {
    Solution solution;
//    VI cnt = { 0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    VI cnt = {0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    assert( cnt.size() == 256 );
    auto result = solution.sampleStats( cnt );
    copy( result.begin(), result.end(), ostream_iterator< double >( cout, ", " ) );
    return 0;
}
*/



using VI = vector< int >;
using VVI = vector< VI >;
using Passengers = unordered_map< int,int >;
class Solution {
public:
    bool carPooling( VVI& trips, int capacity, Passengers P={} ){
        for( auto& t: trips ){
            auto[ cnt, beg, end ] = tie( t[ 0 ], t[ 1 ], t[ 2 ] );
            for( auto j{ beg }; j < end; ++j )
                if(( P[ j ] += cnt ) > capacity )
                    return false;
        }
        return true;
    }
};



int main() {
    VVI trips = { {3,2,7},{3,7,9},{8,3,9} };
    auto capacity{ 11 };
    cout << Solution().carPooling( trips, capacity ) << endl;
    return 0;
}











