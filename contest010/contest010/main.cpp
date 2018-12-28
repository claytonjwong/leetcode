//
//  main.cpp
//  contest010
//
//  Created by CLAYTON WONG on 6/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/*
using VVI=vector<vector<int>>;
class Solution {
    vector<pair<int,int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
    int water(VVI& G, int M, int N, int i, int j, int ans=0){
        for (auto& dir: dirs){
            if (!valid(G,M,N,i+dir.first,j+dir.second))
                ++ans;
        }
        return ans;
    }
    int valid(VVI& G, int M, int N, int i, int j){
        return (!(i<0||j<0||i>=M||j>=N) && G[i][j]==1);
    }
public:
    int islandPerimeter(VVI& G, int ans=0) {
        if (G.empty()) return 0;
        if (G[0].empty()) return 0;
        for (int i=0,M=(int)G.size(); i<M; ++i){
            for (int j=0,N=(int)G[0].size(); j<N; ++j){
                if (G[i][j])
                    ans+=water(G,M,N,i,j);
            }
        }
        return ans;
    }
};
 */

class Solution {
public:
    int minMoves2(vector<int>& nums, int ans=0) {
        queue<int>
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    VVI G{{0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}};
    cout << s.islandPerimeter(G) << endl;
    */
    
    Solution s;
    
    
    
    return 0;
}
