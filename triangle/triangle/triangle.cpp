/*
 
 120. Triangle
 
 https://leetcode.com/problems/triangle/description/
 
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 
 For example, given the following triangle
 [
 [2],
 [3,4],
 [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 
 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 
 */

#include <iostream>
#include <vector>

using namespace std;

/* top-down recursive solution O(n^2) time and O(n^2) space */
class SolutionRC {
public:
    int minimumTotal(vector<vector<int>>& t){
        int n=(int)t.size();
        vector<vector<int>> memo(n,vector<int>(n,INT_MAX));
        return helper(t,n,0,0,memo);
    }
private:
    int helper(vector<vector<int>>& t, int n, int i, int j, vector<vector<int>>& memo){
        if (i==n-1) return t[i][j];
        if (memo[i][j]!=INT_MAX) return memo[i][j];
        return memo[i][j]=t[i][j]+min(helper(t,n,i+1,j,memo),helper(t,n,i+1,j+1,memo));
    }
};

/* bottom-up DP solution O(n^2) time and O(n^2) space */
class SolutionDP {
public:
    int minimumTotal(vector<vector<int>>& t){
        int n=(int)t.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for (int i=n-1, j=0; j<n; ++j) dp[i][j]=t[i][j];
        for (int i=n-2; i>=0; --i)
            for (int j=0; j<=i; ++j)
                dp[i][j]=t[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    
    SolutionRC rc;
    SolutionDP dp;
    vector<vector<int>> t {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    
    cout << "rc: " << rc.minimumTotal(t) << endl;
    cout << "dp: " << dp.minimumTotal(t) << endl;
    
    return 0;
}





