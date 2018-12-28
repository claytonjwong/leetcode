/*
 
 https://leetcode.com/contest/weekly-contest-83
 
 Rank           Name            Score   Finish Time Q1 (3)    Q2 (5)    Q3 (7)    Q4 (9)
 103 / 2688     claytonjwong    24      1:18:38     0:05:57   0:18:14   0:27:14   1:13:38  *1
 
 
 Q1: https://leetcode.com/problems/positions-of-large-groups/description/
 A1: https://leetcode.com/problems/positions-of-large-groups/discuss/129394/Straightforward-C++
 
 Q2: https://leetcode.com/problems/masking-personal-information/description/
 A2: https://leetcode.com/problems/masking-personal-information/discuss/129400/Straightforward-C++
 
 Q3: https://leetcode.com/problems/consecutive-numbers-sum/description/
 A3: https://leetcode.com/problems/consecutive-numbers-sum/discuss/131463/Straightforward-C++-with-explanation
 
 Q4: https://leetcode.com/problems/unique-letter-string/description/
 A4: https://leetcode.com/problems/unique-letter-string/discuss/131470/C++-iterator-solution
 
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

/*
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S, vector<vector<int>> ans={}) {
        for (int i=0,j=i+1,N=(int)S.size(); i<N; i=j){
            while (j<N && S[i]==S[j]) ++j;
            if (j-i > 2)
                ans.emplace_back(vector<int>{i,j-1});
        }
        return ans;
    }
};
*/

/*
class Solution {
public:
    string maskPII(string S, string ans="", string nums="") {
        auto pos=S.find('@');
        if (pos==string::npos){
            for (auto c: S) if (isdigit(c))
                nums.push_back(c);
            int N=(int)nums.size();
            ans=N==13 ? "+***-" : N==12 ? "+**-" : N==11 ? "+*-" : "";
            ans.append("***-***-"+nums.substr(N-4));
        } else {
            ans=string(1,S[0])+"*****"+S.substr(pos-1);
            transform(ans.begin(),ans.end(),ans.begin(),::tolower);
        }
        return ans;
    }
};
*/

/*
class Solution {
public:
    int consecutiveNumbersSum(int N, int ans=1) {
        for (int k=2; k*(k+1)/2 <= N; ++k)
            ans=(N-k*(k+1)/2)%k==0 ? ans+1 : ans;
        return ans;
    }
};
*/


class Solution {
public:
    int uniqueLetterString(string S, int ans=0) {
        for (int i=0,N=(int)S.size(); i<N; ++i){
            auto L=find(S.rbegin()+N-i,S.rend(),S[i]);
            auto R=find(S.begin()+i+1,S.end(),S[i]);
            int left=L==S.rend() ? 0 : (int)distance(L,S.rbegin()+N);
            int right=R==S.end() ? N-1 : (int)distance(S.begin(),R)-1;
            ans+=(i-left+1)*(right-i+1);
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    string str="abcdddeeeeaabbbcd";
    auto r=s.largeGroupPositions(str);
    */
    
    /*
    Solution s;
    string str="86-(10)12345678";
    cout << s.maskPII(str) << endl;
    */
    
    /*
    Solution s;
    cout << s.consecutiveNumbersSum(15) << endl;
    */
    
    
    Solution s;
    string str="ABA";
    cout << s.uniqueLetterString(str) << endl;
    
    
    
    return 0;
}
