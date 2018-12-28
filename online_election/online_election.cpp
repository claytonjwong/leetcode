/*

 911. Online Election

 Q: https://leetcode.com/problems/online-election/
 A: https://leetcode.com/problems/online-election/discuss/182699/Straightforward-C%2B%2B

*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class TopVotedCandidate{
public:
    TopVotedCandidate( vector<int> votes, vector<int> times, unordered_map<int, int> voteCount={} ){
        struct TopSoFar{
            int vote{ -1 }, count{ 0 };
        } topSoFar;
        for( auto index{ 0 };  index < static_cast<int>(votes.size());  ++index ){
            auto vote{ votes[index] }, time{ times[index] }, count{ ++voteCount[vote] };
            topSoFar = ( count >= topSoFar.count ) ? TopSoFar{ vote, count } : topSoFar;
            top_[ time ] = topSoFar.vote;
        }
    }
    int q( int time ){
        auto it{ top_.upper_bound( time ) };
        return prev( it )->second;
    }
private:
    map<int, int> top_;
};

int main() {

    vector<int>
            votes{  0, 1, 0, 1, 1 },
            times{ 24,29,31,76,81 };
//    [28],[24],[29],[77],[30],[25],[76],[75],[81],[80]
//      0    0    1    1    1    0    1    0    1    1

    TopVotedCandidate tvc{ votes, times };

    assert( tvc.q( 28 ) == 0 );
    assert( tvc.q( 24 ) == 0 );
    assert( tvc.q( 29 ) == 1 );
    assert( tvc.q( 77 ) == 1 );
    assert( tvc.q( 30 ) == 1 );
    assert( tvc.q( 25 ) == 0 );
    assert( tvc.q( 76 ) == 1 );
    assert( tvc.q( 75 ) == 0 );
    assert( tvc.q( 81 ) == 1 );
    assert( tvc.q( 80 ) == 1 );

    return 0;
}