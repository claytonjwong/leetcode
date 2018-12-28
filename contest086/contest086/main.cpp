/*
 
 Rank          Name            Score   Finish Time     Q1 (3)       Q2 (5)    Q3 (8)    Q4 (8)
 572 / 2323    claytonjwong    8       0:49:32         0:23:03  *2  0:49:32
 
 Q1: https://leetcode.com/problems/magic-squares-in-grid/description/
 A1: https://leetcode.com/problems/magic-squares-in-grid/discuss/134420/Simple-and-Straightforward-C++
 
 Q2: https://leetcode.com/problems/keys-and-rooms/description/
 A2: https://leetcode.com/problems/keys-and-rooms/discuss/134422/Concise-C++-BFS-DFS-Solutions
 
 Q3: https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/
 A3: https://leetcode.com/problems/split-array-into-fibonacci-sequence/discuss/134428/DFS-+-Backtracking-C++-Solution
 
 */

#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

using VVI=vector<vector<int>>;
class Solution {
public:
    int numMagicSquaresInside(VVI& G, int ans=0) {
        int M=(int)G.size(),N=(int)G[0].size();
        for (int i=0; i<=M-3; ++i)
            for (int j=0; j<=N-3; ++j)
                if (magic(G,i,j)) ++ans;
        return ans;
    }
private:
    bool magic(const VVI& G, int i, int j) const {
        int r=0,c=0,d1=0,d2=0;
        for (int p=0; p<3; ++p){
            r=0;c=0;
            for (int q=0; q<3; ++q){
                if (G[p+i][q+j]<1 || G[p+i][q+j]>9)
                    return false;
                r+=G[p+i][q+j];
                c+=G[q+i][p+j];
            }
            if (r!=c)
                return false;
            d1+=G[p+i][p+j];
            d2+=G[2-p+i][p+j];
        }
        return d1==d2 && d1==r;
    }
};


/*
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& G, queue<int> q=queue<int>({0}), unordered_set<int> V={}) {
        while (!q.empty()){
            int i=q.front(); q.pop();
            if (V.insert(i).second)
                for (int nei: G[i]) q.push(nei);
        }
        return V.size()==G.size();
    }
};
*/

/*
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& G, stack<int> s=stack<int>({0}), unordered_set<int> V={}) {
        while (!s.empty()){
            int i=s.top(); s.pop();
            if (V.insert(i).second)
                for (int nei: G[i]) s.push(nei);
        }
        return V.size()==G.size();
    }
};
*/

/*
class Solution {
public:
    vector<int> splitIntoFibonacci(string S, vector<int> ans={}) {
        return go(S,ans) ? ans : vector<int>{};
    }
private:
    bool go(const string& S, vector<int>& V, int beg=0){
        if (beg==(int)S.size() && V.size()>2) return true;
        int len=S[beg]=='0' ? 1 : 10;
        for (int i=0,N=(int)S.size(); i<len && beg+i<N; ++i){
            long long curr=stoll(S.substr(beg,i+1));
            if (curr > INT_MAX) return false;
            int sz=(int)V.size();
            if (sz<2 || (sz>1 && V[sz-2]+V[sz-1]==curr)){
                V.push_back((int)curr);
                if (go(S,V,beg+i+1)) return true;
                V.pop_back();
            }
        }
        return false;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    Solution s;
    VVI G={{5,5,5},{5,5,5},{5,5,5}};
    cout << s.numMagicSquaresInside(G) << endl;
    
    
    /*
    Solution s;
    vector<vector<int>> G={{1},{2},{3},{}};
    cout << s.canVisitAllRooms(G) << endl;
    */
    
    /*
    Solution s;
    string S="123456579";
    auto r=s.splitIntoFibonacci(S);
    */
    
    return 0;
}


