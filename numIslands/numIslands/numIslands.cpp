/*
 
 200. Number of Islands
 
 https://leetcode.com/problems/number-of-islands/description/
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int cnt=0,m=(int)grid.size(),n=(int)grid[0].size();
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                cnt+=dfs(grid,m,n,i,j);
        return cnt;
    }
private:
    int dfs(vector<vector<char>>& grid, int m, int n, int i, int j){
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0') return 0;
        grid[i][j]='0';
        dfs(grid,m,n,i-1,j); dfs(grid,m,n,i,j-1);
        dfs(grid,m,n,i+1,j); dfs(grid,m,n,i,j+1);
        return 1;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> grid {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };
    Solution s;
    cout << s.numIslands(grid) << endl;
    
    return 0;
}


