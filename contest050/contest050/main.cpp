/*
 
 https://leetcode.com/contest/leetcode-weekly-contest-50
 
 Rank       Name            Score   Finish Time     Q1 (3)     Q2 (6)     Q3 (7)     Q4 (9)
 63 / 2713  claytonjwong    25      1:20:35         0:07:43    0:14:25    0:22:24    1:00:35  *4
 
 Q1: https://leetcode.com/problems/valid-palindrome-ii/description/
 A1: https://leetcode.com/problems/valid-palindrome-ii/discuss/128523/Short-and-Simple-C++-using-recursion-(-EASY-to-understand-)
 
 Q2: https://leetcode.com/problems/map-sum-pairs/description/
 A2: https://leetcode.com/problems/map-sum-pairs/discuss/128520/Short-and-Simple-C++-solution-(-EASY-to-understand-)
 
 Q3: https://leetcode.com/problems/valid-parenthesis-string/description/
 A3: https://leetcode.com/problems/valid-parenthesis-string/discuss/128527/Short-and-Simple-C++-(-EASY-to-understand-)
 
 Q4: https://leetcode.com/problems/24-game/description/
 A4: https://leetcode.com/problems/24-game/discuss/132798/C++-all-combinations-of-all-permutations
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size()<3) return true;
        return go(s,0,int(s.size())-1);
    }
private:
    bool go(const string& s, int i, int j, bool first=true){
        while (i<j){
            if (s[i]!=s[j])
                return first ? go(s,i+1,j,false) || go(s,i,j-1,false) : false;
            ++i;--j;
        }
        return true;
    }
};
*/

/*
class MapSum {
public:
    void insert(string key, int val) {
        for (int i=1,N=(int)key.size(),found=!(s.insert(key)).second; i<=N; ++i)
            m[key.substr(0,i)]=found ? val : m[key.substr(0,i)]+val;
    }
    int sum(string prefix) {
        return m[prefix];
    }
private:
    unordered_map<string,int> m;
    unordered_set<string> s;
};
*/

/*
class Solution {
public:
    bool checkValidString(string s) {
        return go(s);
    }
private:
    bool go(const string& s, int i=0, int open=0){
        int N=(int)s.size();
        if (i==N) return open==0;
        if (s[i]=='(') return go(s,i+1,open+1);
        if (s[i]==')') return open-1 < 0 ? false : go(s,i+1,open-1);
        return go(s,i+1,open) || go(s,i+1,open+1) || go(s,i+1,open-1);
    }
};
*/


class Solution {
public:
    bool judgePoint24(vector<int>& A) {
        sort(A.begin(),A.end());
        do{
            if (go(A[0],A[1],A[2],A[3]))
                return true;
        } while (next_permutation(A.begin(),A.end()));
        return false;
    }
private:
    bool go(double a, double b, double c, double d) {
        return
        go(a+b,c,d) || go(a-b,c,d) || go(a*b,c,d) || (b&&go(a/b,c,d)) ||
        go(a,b+c,d) || go(a,b-c,d) || go(a,b*c,d) || (c&&go(a,b/c,d)) ||
        go(a,b,c+d) || go(a,b,c-d) || go(a,b,c*d) || (d&&go(a,b,c/d));
    }
    bool go(double a, double b, double c){
        return
        go(a+b,c) || go(a-b,c) || go(a*b,c) || (b&&go(a/b,c)) ||
        go(a,b+c) || go(a,b-c) || go(a,b*c) || (c&&go(a,b/c));
    }
    bool go(double a, double b){
        return abs(a+b-24.0)<0.0001 || abs(a-b-24.0)<0.0001 || abs(a*b-24.0)<0.0001 || (b&&abs(a/b-24.0)<0.0001);
    }
};

int main(int argc, const char * argv[]) {
  
    /*
    Solution s;
    while(true){
        string str;
        cin >> str;
        cout << s.validPalindrome(str) << endl;
    }
    */
    
    /*
    MapSum ms;
    ms.insert("apple", 3);
    cout << ms.sum("app") << endl;
    ms.insert("ap",2);
    cout << ms.sum("ap") << endl;
    */
    
    /*
    Solution s;
    while (true){
        string str="";
        cin >> str;
        cout << s.checkValidString(str) << endl;
    }
    */
    
    Solution s;
    vector<int> v{4,1,8,7};
    cout << s.judgePoint24(v) << endl;
    
    return 0;
}
