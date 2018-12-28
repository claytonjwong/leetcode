/*
 
 62. Unique Paths
 
 https://leetcode.com/problems/unique-paths/description/
 
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 
 How many possible unique paths are there?
 
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/* recursive solution O(n^2) time and O(n^2) space*/
class SolutionRC {
public:
    int uniquePaths(int m, int n) {
        map<pair<int,int>,int> memo{};
        return helper(m,n,0,0,memo);
    }
private:
    int helper(const int& m, const int& n, int i, int j, map<pair<int,int>,int>& memo){
        if (memo.find({i,j})!=memo.end()) return memo[{i,j}];
        if (i==m-1 || j==n-1) return memo[{i,j}]=1;
        return memo[{i,j}]=helper(m,n,i+1,j,memo)+helper(m,n,i,j+1,memo);
    }
};

/* DP solution O(n^2) time and O(n^2) space*/
class SolutionDP {
public:
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i=0; i<m; ++i) dp[i][n-1]=1;
        for (int j=0; j<n; ++j) dp[m-1][j]=1;
        for (int i=m-2; i>=0; --i)
            for (int j=n-2; j>=0; --j)
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {

    SolutionDP dp;
    SolutionRC rc;
    while (true){
        int m,n;
        cout << "m: "; cin >> m;
        cout << "n: "; cin >> n;
        cout << "rc: " << rc.uniquePaths(m,n) << endl;
        cout << "dp: " << dp.uniquePaths(m,n) << endl;
    }
    
    
    
    return 0;
}





