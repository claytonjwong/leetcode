/*

 207. Course Schedule
 
 Q: https://leetcode.com/problems/course-schedule/description/
 A: https://leetcode.com/problems/course-schedule/discuss/151640/Concise-C++-BFS-and-DFS-solutions
 
 */


#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/*
class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& pre) {
        unordered_set<int> visiting,visited;
        vector<vector<int>> G(N);
        for (const auto& x: pre){
            G[x.second].push_back(x.first);
        }
        for (int i=0; i<N; ++i){
            if (!dfs(G, i, visiting, visited))
                return false;
        }
        return true;
    }
private:
    bool dfs(const vector<vector<int>>& G, int i, unordered_set<int>& visiting, unordered_set<int>& visited){
        visiting.insert(i);
        for (const auto nei: G[i]){
            if (visiting.find(nei)!=visiting.end())
                return false;
            if (visited.find(nei)==visited.end())
                if (!dfs(G,nei,visiting,visited))
                    return false;
        }
        visiting.erase(i);
        visited.insert(i);
        return true;
    }
};
*/

/*
class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& pre) {
        G.resize(N); U.clear(); V.clear();
        for (const auto& x: pre)
            G[x.second].push_back(x.first);
        for (int i=0; i<N; ++i) if (!dfs(i))
            return false;
        return true;
    }
private:
    vector<vector<int>> G;
    unordered_set<int> U,V; //  U==visiting  V==visited
    bool dfs(int i){
        if (V.find(i)!=V.end())
            return true;
        U.insert(i);
        for (const auto nei: G[i]) if (U.find(nei)!=U.end() || !dfs(nei))
            return false;
        U.erase(i);
        V.insert(i);
        return true;
    }
};
*/

class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& pre) {
        G.resize(N); V.clear();
        for (const auto& x: pre)
            G[x.second].push_back(x.first);
        for (int i=0; i<N; ++i) if (!dfs(i))
            return false;
        return true;
    }
private:
    vector<vector<int>> G;
    unordered_set<int> V; //  U==visiting  V==visited
    bool dfs(int i, unordered_set<int>&& U={}){
        if (V.find(i)!=V.end())
            return true;
        U.insert(i);
        for (const auto nei: G[i]) if (U.find(nei)!=U.end() || !dfs(nei,move(U)))
            return false;
        U.erase(i);
        V.insert(i);
        return true;
    }
};


/*
class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& pre, queue<int> q={}, int cnt=0) {
        vector<vector<int>> G(N); vector<int> D(N);
        for (const auto& x: pre){
            G[x.second].push_back(x.first);
            ++D[x.first];
        }
        for (int i=0; i<N; ++i) if (D[i]==0)
            q.push(i);
        for (; !q.empty(); ++cnt){
            int curr=q.front(); q.pop();
            for (const auto nei: G[curr])
                if (--D[nei]==0)
                    q.push(nei);
        }
        return cnt==N;
    }
};
*/




int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<pair<int,int>> pre{
        {0,1},
        {1,0},
    };
    cout << s.canFinish(3, pre) << endl;
    return 0;
}


