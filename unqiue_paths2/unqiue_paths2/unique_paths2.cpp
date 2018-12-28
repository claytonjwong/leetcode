/*
 
 63. Unique Paths II
 
 Q: https://leetcode.com/problems/unique-paths-ii/description/
 A: https://leetcode.com/problems/unique-paths-ii/discuss/153003/C++-DP-concise-solution-with-explanation
 
 */

#include <iostream>
#include <vector>

using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    int uniquePathsWithObstacles(VVI& G) {
        int M=(int)G.size(),N=(M>0) ? (int)G[0].size() : 0;
        if (M<2 || N<2) return !G[M-1][N-1];
        VVI dp(M,VI(N));
        dp[0][0]=1;
        for (int i=1; i<M; ++i) if (!G[i][0] && dp[i-1][0]) dp[i][0]=1;
        for (int j=1; j<N; ++j) if (!G[0][j] && dp[0][j-1]) dp[0][j]=1;
        for (int i=1; i<M; ++i){
            for (int j=1; j<N; ++j){
                if (G[i][j])
                    continue;
                else if (dp[i-1][j] && dp[i][j-1])
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else if (dp[i-1][j] || dp[i][j-1])
                    dp[i][j]=dp[i-1][j] ^ dp[i][j-1];
            }
        }
        return dp[M-1][N-1];
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
//    VVI G{
//        {0,0,0},
//        {0,1,0},
//        {0,0,0},
//    };
    VVI G{{0,1}};
    auto res=s.uniquePathsWithObstacles(G);
    cout << res << endl;
    return 0;
}



