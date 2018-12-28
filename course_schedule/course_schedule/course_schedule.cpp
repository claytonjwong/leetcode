/*
 
 207. Course Schedule
 
 Q: https://leetcode.com/problems/course-schedule/description/
 
 A: https://leetcode.com/problems/course-schedule/discuss/126917/C++-Topological-Sort-and-DFS-solutions-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

/*
// topological sort
class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& preqs) {
        queue<int> q; vector<unordered_set<int>> G(N); vector<int> P(N);
        for (auto& p: preqs){
            G[p.second].insert(p.first);
            ++P[p.first];
        }
        for (int i=0; i<N; ++i) if (P[i]==0)
            q.push(i);
        int cnt=0;
        while (!q.empty()){
            int i=q.front(); q.pop(); ++cnt;
            for (auto nei: G[i]) if (--P[nei]==0)
                q.push(nei);
        }
        return cnt==N;
    }
};
 */

// dfs + recursion
class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& preqs) {
        vector<unordered_set<int>> G(N); for (auto& p: preqs) G[p.second].insert(p.first);
        unordered_set<int> T,P; // TEMP (visiting) & PERM (visited)
        for (int i=0; i<N; ++i) if (!go(i,G,T,P))
            return false;
        return true;
    }
private:
    bool go(int i, vector<unordered_set<int>>& G,
            unordered_set<int>& T, unordered_set<int>& P){
        if (P.count(i)) return true;
        if (T.count(i)) return false;
        T.insert(i);
        bool ans=true;
        for (auto nei: G[i])
            ans&=go(nei,G,T,P);
        T.erase(i);
        P.insert(i);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    int N=4; vector<pair<int,int>> vp { {1,0}, {2,1}, {2,0} };
    
    cout << s.canFinish(N, vp) << endl;
    
    return 0;
}




