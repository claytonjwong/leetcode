/*
 
 https://leetcode.com/contest/weekly-contest-67/
 
 Rank       Name            Score	Finish Time 	Q1 (2)      Q2 (6)      Q3 (7)      Q4 (10)
 311 / 2865	claytonjwong 	15      1:16:19         0:17:19     1:16:19     0:39:02
 
 */

#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int cnt=0;
        for (int i=L; i<=R; ++i)
            if (isPrime(i)) ++cnt;
        return cnt;
    }
private:
    int isPrime(int n){
        n=__builtin_popcount(n);
        if (n==1) return false;
        for (int i=2; i<n; ++i)
            if (n%i==0)
                return false;
        return true;
    }
};


/*
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int maxi=0;
        vector<vector<int>> m(N,vector<int>(N,1));
        if (!mines.empty())
            for (auto &v: mines)
                m[v[0]][v[1]]=0;
        for (int i=0; i<N; ++i){
            for (int j=0; j<N; ++j){
                int k=0;
                while (canExpand(N, i, j, m, k)) ++k;
                maxi=max(maxi,k);
            }
        }
        return maxi;
    }
private:
    bool canExpand(int N, int x, int y, vector<vector<int>>& m, int k){
        if (x-k<0 || y-k<0 || x+k>=N || y+k>=N) return false;
        return m[x-k][y] && m[x][y+k] && m[x+k][y] && m[x][y-k];
    }
};
 */

/*
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int beg=0,end=0;
        set<char> v;
        while(end<S.size()){
            beg=end;
            end=1+endPart(S, beg, v);
            res.push_back(end-beg);
        }
        return res;
    }
private:
    int endPart(string s, int start, set<char>& visited){
        char c=s[start];
        visited.insert(c);
        int end=start;
        for (int i=(int)s.size()-1; i>=0; --i)
            if (s[i]==c){
                end=i;
                break;
            }
        if (start==end) return end;
        int maxi=end;
        for (int i=start+1; i<=end; ++i)
            if (visited.find(s[i])==visited.end())
                maxi=max(maxi,endPart(s,i,visited));
        return maxi;
    }
};
*/


int main(int argc, const char * argv[]) {
    
    Solution s;
    set<char> visited;
    string str="ababcbacadefegdehijhklij";
    //          012345678901234567890123
    //auto r=s.partitionLabels(str);
    
    return 0;
}
