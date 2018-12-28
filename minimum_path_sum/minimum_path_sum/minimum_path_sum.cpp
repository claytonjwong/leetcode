/*
 
 64. Minimum Path Sum
 
 https://leetcode.com/problems/minimum-path-sum/description/
 https://leetcode.com/problems/minimum-path-sum/discuss/23460/c-top-down-recursion-and-bottom-up-dp
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 // AC
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M=(int)grid.size(),N=(int)grid[0].size();
        vector<vector<int>> memo(M,vector<int>(N,-1));
        return go(grid,M-1,N-1,memo);
    }
private:
    int go(vector<vector<int>>& g, int i, int j, vector<vector<int>>& m){
        if (i==0 && j==0) return m[0][0]=g[0][0];
        if (i==0) return m[i][j-1]=g[i][j]+go(g,i,j-1,m);
        if (j==0) return m[i-1][j]=g[i][j]+go(g,i-1,j,m);
        return m[i][j]>=0 ? m[i][j] : m[i][j]=g[i][j]+min(go(g,i-1,j,m),go(g,i,j-1,m));
    }
};
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int M=(int)g.size(),N=(int)g[0].size();
        vector<vector<int>> dp(M,vector<int>(N));
        dp[0][0]=g[0][0];
        for (int j=1; j<N; ++j) dp[0][j]=g[0][j]+dp[0][j-1];
        for (int i=1; i<M; ++i) dp[i][0]=g[i][0]+dp[i-1][0];
        for (int i=1; i<M; ++i)
            for (int j=1; j<N; ++j)
                dp[i][j]=g[i][j]+min(dp[i-1][j],dp[i][j-1]);
        return dp[M-1][N-1];
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<vector<int>> grid {
        { 1,2,3 },
        { 4,0,6 },
        { 7,0,9 },
    };
    cout << s.minPathSum(grid) << endl;
    
    return 0;
}


