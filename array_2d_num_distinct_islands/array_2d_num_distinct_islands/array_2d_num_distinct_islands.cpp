/*

 694. Number of Distinct Islands
 
 https://leetcode.com/contest/leetcode-weekly-contest-53/problems/number-of-distinct-islands/
 
 Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
 
 Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
 
 Example 1:
 11000
 11000
 00011
 00011
 Given the above grid map, return 1.
 Example 2:
 11011
 10000
 00001
 11011
 Given the above grid map, return 3.
 
 Notice that:
 11
 1
 and
 1
 11
 are considered different island shapes, because we do not consider reflection / rotation.
 Note: The length of each dimension in the given grid does not exceed 50.
 
 */



#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<set<pair<int,int>>> islands;
        for (int r=0; r < grid.size(); ++r){
            for (int c=0; c < grid[0].size(); ++c){
                if (grid[r][c]){
                    set<pair<int,int>> curr{};
                    dfs(grid,r,c,curr,make_pair(r,c));
                    islands.insert(curr);
                }
            }
        }
        return (int)islands.size();
    }
    
    void dfs(vector<vector<int>>& grid, const int& r, const int& c,
                set<pair<int,int>>& island, const pair<int,int>& start){
        if (!(0<=r&&r<grid.size() && 0<=c&&c<grid[0].size())) return;
        if (!grid[r][c]) return;
        island.insert(make_pair(r-start.first,c-start.second));
        grid[r][c]=0;
        dfs(grid,r-1,c,island,start); // top
        dfs(grid,r,c+1,island,start); // right
        dfs(grid,r+1,c,island,start); // bottom
        dfs(grid,r,c-1,island,start); // left
    }
};


int main(int argc, const char * argv[]) {
    
    vector<vector<int>> grid{
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1},
    };
    
    Solution solution;
    cout << solution.numDistinctIslands(grid) << endl;
    
    
    return 0;
}




