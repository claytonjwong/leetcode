/*
 
 https://leetcode.com/contest/leetcode-weekly-contest-50
 
 Rank           Name            Score   Finish Time     Q1 (3)      Q2 (6)      Q3 (7)      Q4 (9)
 211 / 2713     claytonjwong    16      0:55:40         0:11:59    0:25:09  2   0:40:40  1
 
 
 Q1: https://leetcode.com/contest/leetcode-weekly-contest-50/problems/valid-palindrome-ii/
 A1: https://leetcode.com/problems/valid-palindrome-ii/discuss/128523/Short-and-Simple-C++-using-recursion-(-EASY-to-understand-)
 
 Q2: https://leetcode.com/problems/map-sum-pairs/description/
 A2: https://leetcode.com/problems/map-sum-pairs/discuss/128520/Short-and-Simple-C++-solution-(-EASY-to-understand-)
 
 Q3: https://leetcode.com/problems/valid-parenthesis-string/description/
 A3: https://leetcode.com/problems/valid-parenthesis-string/discuss/128527/Short-and-Simple-C++-(-EASY-to-understand-)
 
 Q4: https://leetcode.com/problems/24-game/description/
 A4:
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size()<2) return true;
        return go(s,0,(int)s.size()-1,true);
    }
private:
    bool go(const string& s, int i, int j, bool first){
        while (i<j && s[i]==s[j]){ ++i; --j; };
        return (i>=j) ? true : first ? go(s,i+1,j,false) || go(s,i,j-1,false) : false;
    }
};

 */

/*
class MapSum {
public:
    void insert(string key, int val) {
        bool found=K.find(key)!=K.end();
        K.insert(key);
        for (int i=1; i<=(int)key.size(); ++i){
            if (found)
                M[key.substr(0,i)]=val;
            else
                M[key.substr(0,i)]+=val;
        }
    }
    
    int sum(string prefix) {
        return M[prefix];
    }
private:
    unordered_map<string,int> M;
    unordered_set<string> K;
};
 
 */

/*
class MapSum {
public:
    void insert(string key, int val) {
        bool found=K.find(key)!=K.end(); K.insert(key);
        for (int i=1; i<=(int)key.size(); ++i)
            M[key.substr(0,i)]=found ? val : val+M[key.substr(0,i)];
    }
    int sum(string prefix) { return M[prefix]; }
private:
    unordered_map<string,int> M;
    unordered_set<string> K;
};
 */

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

/*
class Solution {
public:
    bool checkValidString(string s) {
        return go(s,(int)s.size(),0,0);
    }
private:
    bool go(const string& s, int N, int i, int open){
        while (i < N && s[i]!='*'){
            if (s[i]=='(')
                ++open;
            else {
                if (--open < 0)
                    return false;
            }
            ++i;
        }
        if (i==N){
            return open==0;
        } else {
            return go(s,N,i+1,open) || go(s,N,i+1,open+1) || go(s,N,i+1,open-1);
        }
    }
};
*/

class Solution {
public:
    bool checkValidString(string s) {
        return go(s,(int)s.size());
    }
private:
    bool go(const string& s, int N, int i=0, int open=0){
        while (i < N && s[i]!='*'){
            if (s[i]=='(')
                ++open;
            else if (--open < 0)
                return false;
            ++i;
        }
        return (i==N) ? open==0 : go(s,N,i+1,open) || go(s,N,i+1,open+1) || go(s,N,i+1,open-1);
    }
};

/*
 
 You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.
 
 Example 1:
 Input: [4, 1, 8, 7]
 Output: True
 Explanation: (8-4) * (7-1) = 24
 Example 2:
 Input: [1, 2, 1, 2]
 Output: False
 Note:
 The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
 Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
 You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
 
 */

// ran out of time
/*
class Solution {
public:
    bool judgePoint24(vector<int>& A) {
        return go(A,1,0.0);
    }
private:
    vector<char> ops={'+','-','*','/'};
    bool go(const vector<int>& A, int i, double ans){
      while (i < A.size()){
          for (auto op: ops)
              if (go(A,i+1,doit(ans,op,A[i]);
          ++i;
      }
      return ans==24.0;
    }
    double doit(double ans, char c, int next){
        switch(c){
            case '+': return ans+next;
            case '-': return ans-next;
            case '*': return ans*next;
            case '/': return ans/next;
        }
        return 0.0;
    }
};
*/


int main(int argc, const char * argv[]) {

    /*
    Solution s;
    string str="abbcca";
    cout << s.validPalindrome(str) << endl;
*/
    /*
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
    */
    
    /*
    MapSum ms;
    ms.insert("apple",3);
    cout << ms.sum("apple") << endl;
    ms.insert("app",2);
    cout << ms.sum("ap") << endl;
    */
    
    /*
     Input:
     ["MapSum", "insert", "sum", "insert", "sum"]
     [[], ["aa",3], ["a"], ["aa",2], ["a"]]
     Output:
     [null,null,3,null,5]
     Expected:
     [null,null,3,null,2]
     */
    
    /*
    MapSum ms;
    ms.insert("aa",3);
    cout << ms.sum("a") << endl;
    ms.insert("aa",2);
    cout << ms.sum("a") << endl;
*/
    
  
    Solution s;
    string str="(*)";
    cout << s.checkValidString(str) << endl;
    
    
    
    
    
    
    return 0;
}


