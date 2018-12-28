/*
 
 https://leetcode.com/contest/weekly-contest-86
 
 Rank           Name            Score   Finish Time     Q1 (3)          Q2 (5)    Q3 (6)    Q4 (8)
 200 / 2323     claytonjwong    14      1:14:37         0:25:17  *1     0:30:51   1:09:37
 
 */


#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>


using namespace std;

/*
using VVI=vector<vector<int>>;
class Solution {
public:
    int numMagicSquaresInside(VVI& G, int ans=0) {
        int M=(int)G.size(),N=(int)G[0].size();
        for (int i=0; i<=M-3; ++i)
            for (int j=0; j<=N-3; ++j)
                if (magic(G,i,j))
                    ++ans;
        return ans;
    }
private:
    bool magic(VVI& G, int i, int j) {
        int row=0,col=0,d1=0,d2=0;
        for (int p=0; p<3; ++p){
            row=0; col=0;
            for (int q=0; q<3; ++q){
                if (G[p+i][q+j]<1||G[p+i][q+j]>9) return false;
                row+=G[p+i][q+j];
                col+=G[q+i][p+j];
            }
            d1+=G[p+i][p+j];
            d2+=G[2-p+i][p+j];
        }
        return d1==d2 && row==col && d1==row;
    }
};
*/

/*
using VVI=vector<vector<int>>;
class Solution {
public:
    bool canVisitAllRooms(VVI& G) {
        queue<int> q({0});
        unordered_set<int> v({0});
        while (!q.empty()){
            int i=q.front(); q.pop();
            for (int nei: G[i])
                if (v.insert(nei).second)
                    q.push(nei);
        }
        return G.size()==v.size();
    }
};
*/

class Solution {
public:
    vector<int> splitIntoFibonacci(string S, vector<int> V={}) {
        return go(S,V) ? V : vector<int>{};
    }
private:
    bool go(const string& S, vector<int>& V, int i=0){
        int N=(int)S.size(),K=(int)V.size();
        if (i==N)
            return K>2;
        int len=S[i]=='0' ? 1 : 10;
        for (int j=1; j<=len && i+j<=N; ++j){
            long long curr=stoll(S.substr(i,j));
            if (curr>INT_MAX) return false;
            
            if (K<2 || V[K-2]+V[K-1]==curr){
                V.push_back((int)curr);
                if (go(S,V,i+j)) return true;
                V.pop_back();
            }
        }
        return false;
    }
};


int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    VVI G{{4,3,8,4},
          {9,5,1,9},
          {2,7,6,2}};
    cout << s.numMagicSquaresInside(G) << endl;
    */
    
    /*
    Solution s;
    VVI G{{1,3},{3,0,1},{2},{0}};
    cout << s.canVisitAllRooms(G) << endl;
    */
    
    string S="1101111";
    Solution s;
    auto r=s.splitIntoFibonacci(S);
     
    return 0;
}


