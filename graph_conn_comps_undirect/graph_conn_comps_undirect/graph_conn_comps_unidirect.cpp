/*
 
 https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countComponents(int N, vector<pair<int, int>>& E) {
        vector<unordered_set<int>> G(N);
        for (auto e: E){
            G[e.first].insert(e.second);
            G[e.second].insert(e.first);
        }
        unordered_set<int> V;
        int cnt=0; for (int i=0; i<N; ++i)
            if (dfs(G,V,i)) ++cnt;
        return cnt;
    }
private:
    bool dfs(vector<unordered_set<int>>& G, unordered_set<int>& V, int i){
        if (V.count(i)) return false;
        V.insert(i);
        for (auto nei: G[i])
            dfs(G,V,nei);
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<pair<int,int>> E={
        {0,1},
        {2,3},
        {0,3},
    };
    cout << s.countComponents(4, E) << endl;
    
    return 0;
}
