/*
 
 https://leetcode.com/contest/weekly-contest-73
 
 Rank           Name            Score    Finish Time     Q1 (4)         Q2 (5)      Q3 (5)    Q4 (5)
 1025 / 2533    claytonjwong     9       1:23:43         0:50:54  2                 1:13:43
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
 // AC
class Solution {
public:
    int rotatedDigits(int N) {
        int cnt=0;
        for (int i=0; i<=N; ++i){
            string s(to_string(i));
            set<char> c(s.begin(),s.end());
            if (c.count('3')||c.count('4')||c.count('7')) continue;
            if (c.count('2')||c.count('5')||c.count('6')||c.count('9')) ++cnt;
        }
        return cnt;
    }
};
*/

/*
 // AC
#include <vector>
class Solution {
public:
    string customSortString(string S, string T) {
        string res,nomatch;
        unordered_map<char,int> mi;
        int n=(int)S.size();
        vector<int> v(n,0);
        for (int i=0,c=S[i]; i<n; ++i,c=S[i])
            mi[c]=i;
        for (auto c: T)
            if (mi.count(c)) ++v[mi[c]]; else nomatch.push_back(c);
        for (int i=0,c=S[i]; i<n; ++i,c=S[i])
            while (--v[mi[c]]>=0) res.push_back(c);
        return res+nomatch;
    }
};
*/

/*
 // wrong answer, TODO revist this one
class Solution {
public:
    
    int numTilings(int N) {
        vector<int> dp(N+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        int n=4;
        dp[n]=2+dp[n-3]+dp[n-2]+dp[n-1];
        return dp[n];
    }
private:
    int go(int N){
        if (N<0) return 0;
        if (N==0) return 1;
        return go(N-1)+go(N-2)+2*go(N-3);
    }
};
*/

// AC
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& g, vector<int>& t) {
        for (int i=0; i<g.size(); ++i)
            if (abs(t[0])+abs(t[1])>=abs(t[0]-g[i][0])+abs(t[1]-g[i][1])) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    /*
    string S="cba";
    string T="abcd";
    Solution s;
    cout << s.customSortString(S, T) << endl;
    */
    
    /*
    while(true){
        
        int N;
        cout << "N: ";
        cin >> N; cout << endl;
        Solution s;
        Solution s2;
        //cout << s.numTilings(4) << endl;
        cout << s.rotatedDigits(N) << endl;
        cout << s2.rotatedDigits(N) << endl << endl;
    }
     */
    
    vector<vector<int>> g {
        {-1,2},{0,1},{-2,3},{0,1},{-5,0}
        
    };
    vector<int> t {-2,0};
    Solution s;
    cout << s.escapeGhosts(g, t) << endl;
    //cout << s2.escapeGhosts(g, t) << endl;
    
    
    return 0;
}
