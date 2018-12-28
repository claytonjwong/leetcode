/*
 
 323. Number of Connected Components in an Undirected Graph
 
 Q: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
 
 A: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/discuss/125628/Concise-C++-(-union-find-BFS-DFS-)
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

/*
class Solution {
public:
    int countComponents(int N, vector<pair<int, int>>& E) {
        P.resize(N);
        for (int i=0; i<N; ++i) P[i]=i;
        for (auto& e: E) u(e.first,e.second);
        for (auto& p: P) p=f(p);
        return (int)set<int>(P.begin(),P.end()).size();
    }
private:
    vector<int> P;
    void u(int a, int b){
        int pa=f(a),pb=f(b);
        if (pa==pb) return;
        P[pa]=pb;
    }
    int f(int x){
        while (x!=P[x]) x=P[x];
        return x;
    }
};
 */

/*
class Solution {
public:
    int countComponents(int N, vector<pair<int, int>>& E) {
        vector<unordered_set<int>> G(N);
        for (auto& e: E){
            G[e.first].insert(e.second);
            G[e.second].insert(e.first);
        }
        queue<int> q;
        vector<bool> V(N);
        int cnt=0;
        for (int i=0; i<N; ++i){
            if (V[i]) continue;
            q.push(i);
            while (!q.empty()){
                int curr=q.front(); q.pop();
                V[curr]=true;
                for (int nei: G[curr])
                    if (!V[nei])
                        q.push(nei);
            }
            ++cnt;
        }
        return cnt;
    }
};
*/

class Solution {
public:
    int countComponents(int N, vector<pair<int, int>>& E) {
        vector<unordered_set<int>> G(N);
        for (auto& e: E){
            G[e.first].insert(e.second);
            G[e.second].insert(e.first);
        }
        stack<int> q;
        vector<bool> V(N);
        int cnt=0;
        for (int i=0; i<N; ++i){
            if (V[i]) continue;
            q.push(i);
            while (!q.empty()){
                int curr=q.top(); q.pop();
                V[curr]=true;
                for (int nei: G[curr])
                    if (!V[nei])
                        q.push(nei);
            }
            ++cnt;
        }
        return cnt;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<pair<int,int>> E={
        {0,1},
        {1,2},
        //{2,3},
        {3,4},
    };
    int N=5;
    cout << s.countComponents(N, E) << endl;
    
    return 0;
}


