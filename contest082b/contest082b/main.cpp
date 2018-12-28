/*
 
 https://leetcode.com/contest/weekly-contest-82
 
 Rank       Name            Score   Finish Time     Q1 (4)      Q2 (5)      Q3 (7)      Q4 (8)
 20 / 2564  claytonjwong    24      0:44:04         0:04:55     0:10:45     0:20:35     0:44:04
 
 */



#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    string toGoatLatin(string S) {
        istringstream is(S); ostringstream os;
        string a="a",s,V="aeiouAEIOU";
        while (is >> s){
            if (V.find(s[0])==string::npos)
                os << s.substr(1) + s[0];
            else
                os << s;
            os << "ma" << a << " ";
            a.push_back('a');
        }
        string ans=os.str();
        ans.pop_back();
        return ans;
    }
};
 */

/*
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> A(121);
        for (auto x: ages) ++A[x];
        int cnt=0;
        for (int i=1; i<121; ++i){
            if (i>0.5*i+7) cnt-=A[i];
            for (int j=i; j>0.5*i+7; --j){
                cnt+=A[i]*A[j];
            }
        }
        return cnt;
    }
};
 */

/*
class Solution {
public:
    int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
        int N=(int)D.size();
        map<int,int> M = {{0,0}};
        for (int i=0; i<N; ++i){
            M[D[i]]=max(M[D[i]],P[i]);
        }
        int maxp=0; for (auto& x: M) x.second=maxp=max(maxp,x.second);
        int ans=0; for (auto w: W) ans+=prev(M.upper_bound(w))->second;
        return ans;
    }
};
*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& G) {
        unordered_set<int> S;
        int ans=0,M=(int)G.size(),N=(int)G[0].size();
        for (int i=0; i<M; ++i){
            for (int j=0; j<N; ++j){
                unordered_set<int> V;
                if (G[i][j]==0){
                    G[i][j]=1;
                    dfs(G,M,N,i,j,V);
                    G[i][j]=0;
                } else if (S.find(key(i,j,N))==S.end()) {
                    dfs(G,M,N,i,j,V);
                    S.insert(V.begin(),V.end());
                }
                ans=max(ans,(int)V.size());
            }
        }
        return ans;
    }
private:
    vector<pair<int,int>> dirs={{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(vector<vector<int>>& G, int M, int N, int i, int j, unordered_set<int>& V){
        if (i<0||j<0||i>=M||j>=N||G[i][j]==0||V.count(key(i,j,N))) return;
        V.insert(key(i,j,N));
        for (auto& dir: dirs) dfs(G,M,N,i+dir.first,j+dir.second,V);
    }
    int key(int i, int j, int N){
        return i+N*j;
    }
};


int main(int argc, const char * argv[]) {

    /*
    Solution s;
    string S="The quick brown fox jumped over the lazy dog";
    cout << s.toGoatLatin(S) << endl;
*/
    
    /*
    Solution s;
    vector<int> ages={20,30,100,110,120};
    cout << s.numFriendRequests(ages) << endl;
    */
    
    /*
    Solution s;
    vector<int> D {2,4,6,8,10}, P = {10,20,30,40,50}, W = {4,5,6,7};
    cout << s.maxProfitAssignment(D, P, W) << endl;
    */
    
    Solution s;
    vector<vector<int>> V={
        {1,1},
        {1,1},
    };
    cout << s.largestIsland(V) << endl;
    
    return 0;
}
