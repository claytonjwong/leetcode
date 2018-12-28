/*
 
 https://leetcode.com/contest/leetcode-weekly-contest-7
 
 Rank       Name            Score    Finish Time    Q1 (1)       Q2 (1)    Q3 (1)    Q4 (1)
 247/499    claytonjwong    2        1:02:24        0:26:06  *1  0:53:22
 
 2 h 30 m    2/4    1:12:10    2/4
 
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

/*
class Solution {
public:
    bool validWordAbbreviation(string S, string A) {
        int i=0,j=0,M=(int)S.size(),N=(int)A.size();
        while (i<M && j<N){
            while (i<M && j<N && isalpha(A[j])){
                if (A[j++]!=S[i++])
                    return false;
            }
            int num=0;
            while (i<M && j<N && isdigit(A[j])){
                if (num==0 && A[j]=='0') return false;
                num*=10;
                num+=stoi(string(1,A[j++]));
            }
            i+=num;
        }
        return i==M && j==N;
    }
};
 */

/*
class Solution {
public:
    int longestPalindrome(string s, int ans=0, bool odd=false) {
        unordered_map<char,int> m;
        for (auto c: s) ++m[c];
        for (auto& x: m){
            ans+=x.second;
            if (x.second%2==1){
                odd=true;
                --ans;
            }
        }
        return odd ? ans+1 : ans;
    }
};
*/

/*
// wrong answer, but close
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int N=(int)nums.size();
        vector<int> sums(N+1,0);
        for (int i=1; i<=N; ++i) sums[i]=sums[i-1]+nums[i-1];
        set<int> s;
        go(sums,N,k,k,s);
        return *min_element(s.begin(),s.end());
    }
private:
    
    int go(const vector<int>& sums, const int N, const int maxK, int k, set<int>& s, int start=0){
        if (k==0) return 0;
        int maxi=0;
        int sum=0;
        for (int i=start; i<=N-k; ++i){
            sum=sums[i+1]-sums[start];
            maxi=max(sum,go(sums,N,maxK,k-1,s,i+1));
        }
        if (k==maxK){
            s.insert(maxi);
        }
        return maxi;
    }
};
 */
 
int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    string S="a",A="1";
    cout << s.validWordAbbreviation(S, A) << endl;
    */
    
    /*
    Solution s;
    //while (true){
        string str="AAABB";
        //cin >> str;
        cout << s.longestPalindrome(str) << endl;
    //}
    */
    
    Solution s;
    vector<int> A{7,2,5,10,8};
    cout << s.splitArray(A, 2) << endl;
    
    return 0;
}
