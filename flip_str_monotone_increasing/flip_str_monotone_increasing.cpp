#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S, int ans=20001 ) {
        int N = static_cast<int>( S.size() );
        vector<int> dp( N+1, 0 );
        for( auto i = 1;  i <= N;  ++i )
            dp[ i ] = dp[ i-1 ] + S[ i-1 ] - '0';
        for( auto i = 1;  i < N;  ++i )
            ans = min( ans, dp[ i ] + dp[ i ] == dp[ N ] ? 0 : ( N - i - ( dp[ N ] - dp[ i ] )) );
        return ans;
    }
};

int main() {



    return 0;
}