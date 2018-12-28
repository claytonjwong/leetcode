/*
 
 256. Paint House
 
 https://leetcode.com/problems/paint-house/description/
 
 There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 
 The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
 
 Note:
 All costs are positive integers.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs){
        if (costs.empty()) return 0;
        const int R=0,G=1,B=2;
        int n=(int)costs.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0]=costs[0];
        for (int i=1; i<costs.size(); ++i){
            int j=i-1;
            vector<int> prev{dp[j][R],dp[j][G],dp[j][B]};
            vector<int> curr{costs[i][R],costs[i][G],costs[i][B]};
            dp[i][R]=curr[R]+min(prev[G],prev[B]);
            dp[i][G]=curr[G]+min(prev[R],prev[B]);
            dp[i][B]=curr[B]+min(prev[R],prev[G]);
        }
        return min({dp[n-1][R],dp[n-1][G],dp[n-1][B]});
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<vector<int>> costs {
        {7,11,100},
        {1,2,3},
        {100,1,100},
    };
    cout << s.minCost(costs) << endl;
    
    return 0;
}



