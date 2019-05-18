#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    using VS = vector< string >;
    using Ans = vector< bool >; // (Ans)wer
    Ans camelMatch( VS& queries, string target, Ans ans={} ){
        for( auto q: queries ){

        }
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VS queries{ "FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack" };
    auto ans = solution.camelMatch( queries, "FoBaT" );
    copy( ans.begin(), ans.end(), ostream_iterator< int >( cout, "," ));
    return 0;
}
