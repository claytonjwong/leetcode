/*
 
 695. Max Area of Island
 
 Q: https://leetcode.com/problems/max-area-of-island/description/
 A: https://leetcode.com/problems/max-area-of-island/discuss/131185/C++-DFS
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& G, int ans=0) {
        for (int i=0,M=(int)G.size(); i<M; ++i){
            for (int j=0,N=(int)G[0].size(); j<N; ++j){
                unordered_set<int> V;
                go(G,M,N,i,j,V);
                ans=max(ans,(int)V.size());
            }
        }
        return ans;
    }
private:
    void go(vector<vector<int>>& G, int M, int N, int i, int j, unordered_set<int>& V) const {
        static vector<pair<int,int>> moves {{0,-1},{-1,0},{0,1},{1,0}};
        if (i<0||j<0||i==M||j==N || G[i][j]==0 || !V.insert(key(i,j,N)).second) return;
        G[i][j]=0;
        for (auto move: moves)
            go(G,M,N,i+move.first,j+move.second,V);
        
    }
    int key(int i, int j, int N) const { return i*N+j; }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<vector<int>> G{
        {0,1},
        {0,1},
        {1,1},
    };
    cout << s.maxAreaOfIsland(G) << endl;
    
    return 0;
}


