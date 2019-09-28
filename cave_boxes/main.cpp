/*

Question:

You are given a set of boxes and a cave with a single entrance. The boxes are of uniform width and variable height,
 and the cave is divided into segments of varying height, each of which is the same width as a box.

Determine the maximum number of boxes that you can slide into the cave along its floor (no stacking) from the entrance.
 Each box must clear the ceiling of all intermediate cave segments on the way to its destination.

For example if the cave segments are of heights {2, 3, 1} from entrance to back, and the boxes are of heights {1, 2, 3},
 then the maximum number of boxes that can be added is 2 (either {1,2} or {2,1}).


Answer:

strategy: greedy algorithm, try to fit the smallest boxes first

pseudo (naive):

sort set of boxes in increasing order
keep track of current cave segment
for each box
    while the box is <= current cave segment height
        go to next cave segment
    add the box onto the answer if <= current cave segment

pseudo (optimized):

sort set of boxes in increasing order
construct candidates by traversing the cave from left-to-right and tracking the current "bottleneck"
keep track of current right-most cave segment
if smallest box remaining fits in the current segment
    increment the answer by 1
decrement current right-most cave segment ( if less than 0, then break out of loop )

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using VI = vector< int >;

namespace Naive {
    class Solution {
    public:
        int boxesWhichFit( const VI& cave, VI boxes, int ans=0 ){
            if( cave.empty() || boxes.empty() )
                return 0;
            sort( boxes.begin(), boxes.end() );
            if( cave.size() < 2 )
                return boxes[ 0 ] < cave[ 0 ];
            auto N = static_cast< int >( cave.size() );
            for( const auto box: boxes ){
                auto cur{ 1 };
                for(; cur <= N && box < cave[ cur-1 ]; ++cur );
                if( cur > N )
                    cur = N;
                if( box <= cave[ cur-1 ] ){
                    ++ans;
                    N = cur-1;
                }
            }
            return ans;
        }
    };
}
namespace Optimized {
    class Solution {
    public:
        int boxesWhichFit( const VI& cave, VI boxes, int ans=0 ){
            if( cave.empty() || boxes.empty() )
                return 0;
            sort( boxes.begin(), boxes.end() );
            if( cave.size() < 2 )
                return boxes[ 0 ] < cave[ 0 ];
            auto N = static_cast< int >( cave.size() );
            VI candidate( N );
            candidate[ 0 ] = cave[ 0 ];
            for( auto i{ 1 }; i < N; ++i )
                candidate[ i ] = min( candidate[ i-1 ], cave[ i ] );
            auto i{ N-1 };
            for( const auto box: boxes ){
                for(; 0 <= i && candidate[ i ] < box; --i );
                if( --i < 0 )
                    break;
                ++ans;
            }
            return ans;
        }
    };
}

int main() {
    VI cave{ 1,4,3,2,1 }, boxes{ 1,2,3,4,5 };
    Naive::Solution naive;
    Optimized::Solution optimized;
    auto ans1 = naive.boxesWhichFit( cave, boxes ),
         ans2 = optimized.boxesWhichFit( cave, boxes );
    assert( ans1 == ans2 );
    cout << ans1 << " == " << ans2 << endl;
    return 0;
}

/*
N = 3

cur = 3
cur-1 = 2

ans = 1

N = 2


cave{ 1, 2, 3 }

cave{}

boxes{}


cave{ 1 }
boxes{ 1,2,3 }

cave{ 3 }
boxes{ 1,2,3 }

cave{ 5,4,3,2,1 }
boxes{ 1,2,3,4,5 }

N = boxes
M = cave segments

    O( N * M )

---------------- optimization using map ---------------------

basic idea: track the right-most index as the value of map
    key of map is height of cave segment

5,4,4,3,2,2,1
0 1 2 3 4 5 6 7

300, 50, 1

m[ 1 ] =


original optimization idea:

using vector

300  300  300

300  1   1

O( M + N )

*/
