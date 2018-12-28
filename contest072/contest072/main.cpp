/*
 
 https://leetcode.com/contest/weekly-contest-72/ranking/39/
 
 Rank           Name            Score   Finish Time     Q1 (4)          Q2 (6)    Q3 (8)    Q4 (8)
 968 / 2382     claytonjwong    4       0:46:26         0:36:26  *2
 
 */

using namespace std;

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

/*
 // TLE
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        set<string> v;
        queue<string> q({S});
        while (!q.empty()){
            auto curr=q.front(); q.pop();
            v.insert(curr);
            for (int i=0; i<curr.size(); ++i){
                if (isalpha(curr[i])){
                    auto next=curr;
                    next[i]=isupper(next[i]) ? tolower(next[i]) : toupper(next[i]);
                    if (!v.count(next)){
                        q.push(next);
                    }
                }
            }
        }
        return vector<string>(v.begin(),v.end());
    }
};
*/

/*
 // AC
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        unordered_set<string> v;
        int sz=min(12,(int)S.size());
        for (int i=0; i<=(2<<sz)-1; ++i){
            string next(S);
            for (int j=sz-1; j>=0; --j)
                if (i&(1<<j) && isalpha(S[j]))
                    next[j]=isupper(next[j]) ? tolower(next[j]) : toupper(next[j]);
            v.insert(next);
        }
        return vector<string>(v.begin(),v.end());
    }
};
 */

/*
 // AC
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        unordered_set<string> res;
        go(res,S,0);
        return vector<string>(res.begin(),res.end());
    }
private:
    void go(unordered_set<string>& res, string s, int i){
        if (i==s.size()){
            res.insert(s);
            return;
        }
        s[i]=toupper(s[i]);
        go(res,s,i+1);
        s[i]=tolower(s[i]);
        go(res,s,i+1);
    }
};
*/

/*
 // AC
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res{""};
        go(res, S, 0, (int)S.size());
        return res;
    }
private:
    void go(vector<string>& res, const string& s, int i, int n){
        if (i==n) return;
        for (auto& r: res)
            r.push_back(tolower(s[i]));
        if (isalpha(res.back().back())){
            vector<string> upper(res);
            for (auto& u: upper)
                u.back()=toupper(u.back());
            res.insert(res.end(),upper.begin(),upper.end());
        }
        go(res,s,i+1,n);
        return;
    }
};
*/

/*
 
 // Wrong Answer
 
 // maybe correct solution, but to the wrong problem,
 // i assumed this was the same as the "train station"
 // problem in the DP book
 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> c(n,vector<int>(n,10001)),dp(n,vector<int>(n,0));
        for (auto& flight: flights){
            int src=flight[0],dst=flight[1],cost=flight[2];
            c[src][dst]=cost;
        }
        for (int j=0; j<n; ++j){
            dp[0][j]=c[0][j];
            dp[j][j]=0;
        }
        for (int i=1; i<n-1; ++i){
            for (int j=i+1; j<n; ++j){
                dp[i][j]=min(dp[i-1][j-1]+c[i][j],dp[i-1][j]);
            }
        }
        int mini=10001;
        for (int i=src,j=dst; i-src<=K && i<n; ++i){
            mini=min(mini,dp[i][j]);
        }
        return mini==10001 ? -1 : mini;
    }
};
*/

/*
 // AC
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int beg, int end, int K) {
        unordered_map<int,vector<pair<int,int>>> umap;
        for (const auto& flight: flights){
            int src=flight[0],dst=flight[1],cost=flight[2];
            umap[src].push_back({dst,cost});
        }
        vector<int> curr(n,INT_MAX);
        curr[beg]=0;
        while (K-- >= 0){
            vector<int> next(curr);
            for (int src=0; src<n; ++src){
                if (curr[src]==INT_MAX) continue;
                for (const auto& flight: umap[src]){
                    int dst=flight.first,cost=flight.second;
                    next[dst]=min(next[dst],curr[src]+cost);
                }
            }
            curr.swap(next);
        }
        return curr[end]==INT_MAX ? -1 : curr[end];
    }
};
*/

#include <stack>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        stack<int> s;
        int n=(int)graph.size();
        vector<int> v(n,INIT);
        for (int i=0; i<n; ++i){
            if (v[i]!=INIT) continue; // skip already visited nodes
            s.push(i);
            while (!s.empty()){
                int node=s.top(),curr=v[node]==INIT ? 0 : v[node],next=curr^1; s.pop();
                v[node]=curr;
                for (int nei: graph[node]){
                    if (v[nei]==curr) return false;
                    if (v[nei]==INIT)
                        s.push(nei);
                    v[nei]=next;
                }
            }
        }
        return true;
    }
private:
    const int INIT=-1;
};

int main(int argc, const char * argv[]) {
    
    /*
    string str="12345a";
    Solution s;
    auto res=s.letterCasePermutation(str);
    */
    
    /*
    int n=4, src=0, dst=2, K=0;
    vector<vector<int>> v{
        {0,1,100},
        {1,2,100},
        {0,2,500},
    };
     
    Solution s;
    cout << s.findCheapestPrice(n,v,src,dst,K) << endl;
    */
    
    
    /*
     10
     [[3,4,4],[2,5,6],[4,7,10],[9,6,5],[7,4,4],[6,2,10],[6,8,6],
     [7,9,4],[1,5,4],[1,0,4],[9,7,3],[7,0,5],[6,5,8],[1,7,6],
     [4,0,9],[5,9,1],[8,7,3],[1,2,6],[4,1,5],[5,2,4],[1,9,1],[7,8,10],[0,4,2],[7,2,8]]
     6
     0
     7
     */
    
    vector<vector<int>> v {
        {1,2,3},
        {0,2},
        {0,1,3},
        {0,2},
    };
    
    Solution s;
    cout << s.isBipartite(v) << endl;
    
    return 0;
}





