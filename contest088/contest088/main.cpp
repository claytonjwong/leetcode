/*

 Rank           Name            Score   Finish Time     Q1 (4)      Q2 (4)          Q3 (5)    Q4 (8)
 1241 / 3405    claytonjwong    8       1:37:20         0:13:28     1:12:20  *5
 
 https://leetcode.com/contest/weekly-contest-88
 
 Q1: https://leetcode.com/problems/shifting-letters/description/
 A1: https://leetcode.com/problems/shifting-letters/discuss/137937/Concise-C++-with-explanation-(-EASY-to-understand-)
 
 Q2: https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 A2: https://leetcode.com/problems/maximize-distance-to-closest-person/discuss/137957/Straightforward-C++-with-explanation-(-EASY-to-understand-)
 
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>

using namespace std;

/*
 // AC
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts, string ans="") {
        int N=(int)S.size();
        vector<int> sums(shifts);
        for (int i=N-2; i>=0; --i)
            sums[i]=(sums[i]+sums[i+1])%26;
        for (int i=0; i<N; ++i)
            ans.push_back('a'+(S[i]-'a'+sums[i])%26);
        return ans;
    }
};
*/

/*
 // AC
class Solution {
public:
    string shiftingLetters(string S, vector<int>& T) {
        for (int N=(int)S.size(),i=N-1,j=T[i]; i>=0; --i,j+=T[i]%26)
            S[i]='a'+(S[i]-'a'+j)%26;
        return S;
    }
};
 */


/*
 // AC
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int N=(int)seats.size(),beg=0,mid=0,end=0;
        for (int i=0; i<N && seats[i]==0; ++i) ++beg;
        for (int i=beg,j=i+1; j<N; i=j,j=i+1){
            while (j<N && seats[j]==0) ++j;
            mid=max(mid,(j-i)/2);
        }
        for (int i=N-1; i>=0 && seats[i]==0; --i) ++end;
        return max({beg,mid,end});
    }
};
*/

// AC
class Solution {
public:
    int maxDistToClosest(vector<int>& A, int ans=0) {
        for (int i=0,N=(int)A.size(); i<N; ++i){
            if (A[i]) continue; queue<int> q({i}); unordered_set<int> V({i});
            for (int found=0,depth=1,K=(int)q.size(); !found && !q.empty(); ++depth,K=(int)q.size()){
                while (!found && K--){
                    int j=q.front(),L=max(0,j-1),R=min(N-1,j+1); q.pop();
                    if (A[L] || A[R]) found=true;
                    if (V.insert(L).second) q.push(L);
                    if (V.insert(R).second) q.push(R);
                }
                ans=max(ans,depth);
            }
        }
        return ans;
    }
};

/*
 
 // ran out of time
 
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int N=(int)quiet.size();
        vector<set<int>> R(N);
        for (int i=0; i<N; ++i) R[i].insert(i);
        for (auto& i: richer){
            int x=i[0],y=i[1];
            R[y].insert(x);
            for (auto& s: R){
                if (s.find(y)!=s.end())
                    s.insert(x);
            }
        }
        vector<int> ans(N);
        for (int i=0; i<N; ++i){
            int mini=N,minq=N;
            for (int j=0; j<N; ++j){
                if (quiet[j] < minq){
                    minq=quiet[j];
                    mini=j;
                }
            }
            ans[i]=mini;
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    string str="abc"; vector<int> shifts{3,5,9};
    cout << s.shiftingLetters(str, shifts) << endl;
    */
    
    
    vector<int> seats{0,1};
    Solution s;
    cout << s.maxDistToClosest(seats) << endl;
    
    
    /*
    Solution s;
    vector<vector<int>> richer{{1,0},{2,1}}; vector<int> quiet{0,1,2};
    auto r=s.loudAndRich(richer, quiet);
     
     */
    
    
    return 0;
}


