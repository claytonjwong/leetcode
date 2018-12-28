/*
 
 https://leetcode.com/contest/weekly-contest-82
 
 Rank           Name             Score    Finish Time     Q1 (4)     Q2 (5)       Q3 (7)    Q4 (8)
 113 / 2563     claytonjwong     16       0:42:23         0:09:05    0:24:37  1   0:37:23
 
 Q1: https://leetcode.com/contest/weekly-contest-82/problems/goat-latin/
 A1: https://leetcode.com/problems/goat-latin/discuss/126940/C++-stringstream
 
 Q2: https://leetcode.com/contest/weekly-contest-82/problems/friends-of-appropriate-ages/
 A2: https://leetcode.com/problems/friends-of-appropriate-ages/discuss/127014/C++-solution-with-explanation
 
 Q3: https://leetcode.com/contest/weekly-contest-82/problems/most-profit-assigning-work/
 A3: https://leetcode.com/problems/most-profit-assigning-work/discuss/126999/C++-map
 
 Q4: https://leetcode.com/problems/making-a-large-island/description/
 A4:
 
 */


#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;

/*
 //AC
class Solution {
public:
    string toGoatLatin(string S) {
        istringstream is(S); ostringstream os; string s,a="a";
        while (is >> s){
            if (s.substr(0,1).find_first_of("aeiouAEIOU"))
                os << s.substr(1) << s[0];
            else
                os << s;
            os << "ma" << a << (is.tellg()>0 ? " "  : "");
            a.push_back('a');
        }
        return os.str();
    }
};
*/

class Solution {
public:
    string toGoatLatin(string S, string s="", string a="a", ostringstream os=ostringstream()) {
        for (stringstream is(S); is >> s; a.push_back('a'))
            os << ((s.substr(0,1).find_first_of("aeiouAEIOU")) ? s.substr(1)+s[0] : s )
               << "ma" << a << (is.tellg()>0 ? " "  : "");
        return os.str();
    }
};


/*
 //AC
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> A(121);
        for (auto x: ages) ++A[x];
        int cnt=0; for (int i=15; i<121; ++i){
            if (i>0.5*i+7) cnt-=A[i];
            for (int j=i; j>0.5*i+7; --j)
                cnt+=A[i]*A[j];
        }
        return cnt;
    }
};
*/

/*
 //AC
class Solution {
public:
    int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
        map<int,int> M; M[0]=0;
        for (int i=0; i<D.size(); ++i)
            M[D[i]]=max(M[D[i]],P[i]);
        int maxp=0; for (auto& x: M)
            x.second=maxp=max(maxp,x.second);
        int ans=0; for (auto w: W)
            ans+=prev(M.upper_bound(w))->second;
        return ans;
    }
};
*/

/*
class Solution {
public:
    int largestIsland(vector<vector<int>>& G) {
        int ans=0,M=(int)G.size(),N=(int)G[0].size(); unordered_set<int> S;
        for (int i=0; i<M; ++i) for (int j=0; j<N; ++j){
            unordered_set<int> V;
            if (G[i][j]==0){
                G[i][j]=1;
                dfs(G,M,N,i,j,V);
                G[i][j]=0;
            } else if (S.find(key(i,j,N))==S.end()){
                dfs(G,M,N,i,j,V);
                S.insert(V.begin(),V.end());
            }
            ans=max(ans,(int)V.size());
        }
        return ans;
    }
private:
    vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& G, int M, int N, int i, int j, unordered_set<int>& V){
        if (i<0||j<0||i>=M||j>=N||G[i][j]==0||V.count(key(i,j,N))) return;
        V.insert(key(i,j,N)); for (auto d: dirs) dfs(G,M,N,i+d.first,j+d.second,V);
    }
    const int key(int i, int j, int N) const { return i*N+j; }
};
 */
 
int main(int argc, const char * argv[]) {
    
    string S="The quick brown fox jumped over the lazy dog";
    Solution s;
    cout << s.toGoatLatin(S) << endl;
    
    // Imaa peaksmaaa oatGmaaaa atinLmaaaaa
    // Imaa peaksmaaa oatGmaaaa atinLmaaaaa
    
    // "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa
    // "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
    
    
    /*
    vector<int> ages={16,16};
    Solution s;
    cout << s.numFriendRequests(ages) << endl;
    */
    
    /*
    vector<int> D = { 2, 4, 6, 8,10},
                P = {10,20,30,40,50}, W = {4,5,6,7};
    Solution s;
    cout << s.maxProfitAssignment(D, P, W) << endl;;
    */
    
    /*
    vector<vector<int>> G={
        {1,1},
        {1,1},
    };
    Solution s;
    cout << s.largestIsland(G) << endl;
    */
    return 0;
}



