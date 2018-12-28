/*
 
  https://leetcode.com/contest/weekly-contest-74/
 
 Rank           Name             Score      Finish Time     Q1 (7)    Q2 (7)    Q3 (7)    Q4 (7)
 770 / 2675     claytonjwong     7          0:42:28         0:32:28  2
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

/*
class Solution {
public:
    bool validTicTacToe(vector<string>& b) {
        int cx=cnt(b,'X'),co=cnt(b,'O');
        bool wx=win(b,'X'),wo=win(b,'O');
        if (wx && wo) return false;
        if (wx) return cx==co+1
        if (wo) return cx==co;
        return cx==co+1 || cx==co;
    }
private:
    int cnt(vector<string>& b, char c){
        int res=0;
        for (auto& s: b) res+=count(s.begin(),s.end(),c);
        return res;
    }
    bool win(vector<string>& b, char c){
        for (int i=0; i<3; ++i) if (b[i][0]==c && b[i][1]==c && b[i][2]==c) return true;
        for (int j=0; j<3; ++j) if (b[0][j]==c && b[1][j]==c && b[2][j]==c) return true;
        return (b[0][0]==c && b[1][1]==c && b[2][2]==c)
            || (b[2][0]==c && b[1][1]==c && b[0][2]==c);
    }
};
 */


/*
//AC
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,lessThanLeft=0,lessThanOrEqToRight=0;
        for (auto n: A){
 
            if (n<L)
                ++lessThanLeft;
            else
                lessThanLeft=0;
            
            if (n<=R)
                ++lessThanOrEqToRight;
            else
                lessThanOrEqToRight=0;
            
            cnt+=lessThanOrEqToRight-lessThanLeft;
        }
        return cnt;
    }
};
*/

/*
// AC
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,i=0,j=0;
        for (auto n: A){
            i=(n<L) ? i+1 : 0;
            j=(n<=R) ? j+1 : 0;
            cnt+=j-i;
        }
        return cnt;
    }
};



class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,i=0,j=0;
        for (auto n: A) cnt+=( ++j*=(n<=R) ) - ( ++i*=(n<L) );
        return cnt;
    }
};
*/

/*
class Solution{
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<pair<int, int>> waiting[128];
        for (int i = 0; i < words.size(); i++)
            waiting[words[i][0]].emplace_back(i, 1);
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance) {
                int i = it.first, j = it.second;
                waiting[words[i][j]].emplace_back(i, j + 1);
            }
        }
        return waiting[0].size();
    }
};
*/

/*
class Solution2{
public:
    int numMatchingSubseq (string S, vector<string>& words) {
        vector<vector<int>> alpha (26);
        for (int i = 0; i < S.size (); ++i) alpha[S[i] - 'a'].push_back (i);
        int res = 0;
        
        for (const auto& word : words) {
            int x = -1;
            bool found = true;
            
            for (char c : word) {
                auto it = upper_bound (alpha[c - 'a'].begin (), alpha[c - 'a'].end (), x);
                if (it == alpha[c - 'a'].end ()) found = false;
                else x = *it;
            }
            
            if (found) res++;
        }
        
        return res;
    }
};
*/


// AC
class Solution2 {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt=0;
        unordered_map<char,vector<pair<string,int>>> m;
        for (auto& word: words) m[word[0]].push_back({word,0});
        for (auto c: S){
            auto bucket=m[c];
            m[c].clear();
            for (auto p: bucket){
                int index=(++p.second);
                if (index==p.first.size()){
                    ++cnt;
                } else {
                    char next=p.first[index];
                    m[next].push_back(p);
                }
            }
        }
        return cnt;
    }
};

/*
 // AC
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt=0;
        unordered_map<char,vector<string>> m;
        for (auto& word: words) m[word.back()].push_back(word);
        for (int i=(int)S.size()-1; i>=0; --i){
            char c=S[i];
            auto bucket=m[c];
            m[c].clear();
            for (auto& word: bucket){
                word.pop_back();
                if (word.empty())
                    ++cnt;
                else
                    m[word.back()].push_back(word);
            }
        }
        return cnt;
    }
};
 */


class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt=0;
        vector<vector<string>> v(123);
        for (auto& word: words) v[word.back()].push_back(word);
        for (auto itr=S.rbegin(); itr!=S.rend(); ++itr){
            char c=*itr;
            auto bucket=v[c];
            v[c].clear();
            for (auto& word: bucket){
                word.pop_back();
                if (word.empty())
                    ++cnt;
                else
                    v[word.back()].push_back(word);
            }
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<string> v{
        "XOX",
        " X ",
        "   ",
    };
    cout << s.validTicTacToe(v) << endl;
    */
    
    /*
    Solution s;
    
    //vector<int> v{2,9,2,5,6}; int L=2,R=8;
    //vector<int> v{2, 1, 4, 3}; int L=2,R=3;
    vector<int> v{73,55,36,5,55,14,9,7,72,52}; int L=32,R=69;
    // output 18
    // expected 22
    cout << s.numSubarrayBoundedMax(v, L, R) << endl;
    */
    
    Solution s;
    Solution s2;
    string str="abcde";
    vector<string> words{
        "a", "bb", "acd", "ace"
    };
    
    
    cout << s.numMatchingSubseq(str, words) << endl;
    cout << s2.numMatchingSubseq(str, words) << endl;
    
    return 0;
}




