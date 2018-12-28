/*
 
 Rank           Name            Score   Finish Time     Q1 (3)     Q2 (4)    Q3 (6)    Q4 (9)
 316 / 2421     claytonjwong    7       0:15:00         0:02:23    0:15:00
 
 Q1: https://leetcode.com/problems/flipping-an-image/description/
 A1: https://leetcode.com/problems/flipping-an-image/discuss/131721/4-liner-C++-reverse()-and-transform()
 
 Q2: https://leetcode.com/problems/find-and-replace-in-string/description/
 A2: https://leetcode.com/problems/find-and-replace-in-string/discuss/131727/Simple-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>


using namespace std;

/*
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row: A){
            reverse(row.begin(),row.end());
            for (auto& col: row) col^=1;
        }
        return A;
    }
};
*/

/*
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row: A) {
            reverse(row.begin(),row.end());
            transform(row.begin(),row.end(),row.begin(),[](int col){ return col^1; });
        }
        return A;
    }
};
*/


class Solution {
public:
    string findReplaceString(string A, vector<int>& I, vector<string>& S, vector<string>& T, map<int,pair<string,string>> M={}, string ans="") {
        for (int i=0,N=(int)I.size(); i<N; ++i) M[I[i]]={S[i],T[i]};
        for (int i=0,N=(int)A.size(); i<N;)
            if (M.find(i)!=M.end() && A.find(M[i].first,i)==i){
                ans.append(M[i].second);
                i+=(int)M[i].first.size();
            } else
                ans.push_back(A[i++]);
        return ans;
    }
};


/*
 // ran out of time
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int ans=0) {
        int N=(int)A[0].size();
        vector<int>P(N),Q(N);
        for (int i=0; i<N; ++i){
            for (int j=0; j<N; ++j){
                P[i]<<=1;
                P[i]|=A[i][j];
                Q[i]<<=1;
                Q[i]|=B[i][j];
            }
        }
        for (int i=1; i<=N; ++i){
            for (int j=0,k=i; j<i; ++j,--k){
                cout << "compare A row " << N-k << " with B row " << j << "...";
                for (int L=N-1; L>=0; --L){
                    int a=P[N-k] << L, b=Q[j], c=a&b;
                    ans=max(ans,__builtin_popcount(c));
                    cout << "a=" << a << " b=" << b << " c=" << c << endl;
                }
            }
            cout << endl << endl;
        }
        return ans;
    }
};
 */


int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<vector<int>> A={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    auto r=s.flipAndInvertImage(A);
    
    //[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
     */
    
    
    
    Solution s;
    vector<int> I={1,3};
    string A="fabcdg";
    vector<string> S={"a","cd"};
    vector<string> T={"eee","ffff"};
    cout << s.findReplaceString(A, I, S, T);
    
    
    /*
    Solution s;
    vector<vector<int>>
    A={{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0}},
    B={{0,0,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    auto r=s.largestOverlap(A, B);
    */
    return 0;
}


