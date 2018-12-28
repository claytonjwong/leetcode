/*
 
 64. Minimum Path Sum
 
 https://leetcode.com/problems/minimum-path-sum/description/
 
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 
 Note: You can only move either down or right at any point in time.
 
 Example 1:
 [[1,3,1],
  [1,5,1],
  [4,2,1]]
 Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
 
 */

#include <iostream>
#include <vector>

using namespace std;

/* top-down recursive solution O(n^2) time and O(n^2) space */
class SolutionRC {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m=(int)grid.size(),n=(int)grid[0].size();
        vector<vector<int>> memo(m,vector<int>(n,0));
        return helper(grid,m,n,0,0,memo);
    }
private:
    int helper(vector<vector<int>>& g, const int& m, const int& n,
               int i, int j, vector<vector<int>>& memo){
        if (i==m-1 && j==n-1) return memo[i][j]=g[i][j];
        if (i==m-1) return memo[i][j]=g[i][j]+helper(g,m,n,i,j+1,memo);
        if (j==n-1) return memo[i][j]=g[i][j]+helper(g,m,n,i+1,j,memo);
        return memo[i][j]>=0 ? memo[i][j] : memo[i][j]=g[i][j]+min(helper(g,m,n,i,j+1,memo),helper(g,m,n,i+1,j,memo));
    }
};

/* bottom-up DP solution O(n^2) time and O(n^2) space */
class SolutionDP {
public:
    int minPathSum(vector<vector<int>>& grid){
        if (grid.empty()) return 0;
        int m=(int)grid.size()-1,n=(int)grid[0].size()-1;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[m][n]=grid[m][n];
        for (int i=m-1; i>=0; --i) dp[i][n]=grid[i][n]+dp[i+1][n];
        for (int j=n-1; j>=0; --j) dp[m][j]=grid[m][j]+dp[m][j+1];
        for (int i=m-1; i>=0; --i)
            for (int j=n-1; j>=0; --j)
                dp[i][j]+=grid[i][j]+min(dp[i][j+1],dp[i+1][j]);
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    SolutionRC rc;
    SolutionDP dp;
    vector<vector<int>> grid {
        {1,0,1,1},
        {1,0,0,0},
        {1,1,1,1},
    };
    cout << "rc: " << rc.minPathSum(grid) << endl;
    cout << "dp: " << dp.minPathSum(grid) << endl;
    
    return 0;
}




