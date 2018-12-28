/*
 
 Rank         Name          Score   Finish Time     Q1 (2)    Q2 (5)    Q3 (8)    Q4 (10)
 96 / 1229    claytonjwong  10      1:31:59         0:04:18             1:16:59  3
 
 Q1: https://leetcode.com/problems/number-of-segments-in-a-string/description/
 A1: https://leetcode.com/problems/number-of-segments-in-a-string/discuss/136293/C++-istringstream
 
 Q3: https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
 A3: https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/136292/Straightforward-C++-with-explanation
 
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int countSegments(string s, int cnt=0) {
        istringstream is(s);
        while (is >> s) ++cnt;
        return cnt;
    }
};

/*
class Solution {
public:
    int findSubstringInWraproundString(string s, vector<int> v=vector<int>(26,0)) {
        for (int i=0,k=1,N=(int)s.size(); i<N; ++i,k=1){
            while (i+k<N && s[i+k]==next(s[i+k-1])) ++k;
            int bucket=s[i]-'a';
            v[bucket]=max(v[bucket],k);
        }
        return accumulate(v.begin(),v.end(),0);
    }
private:
    char next(char c){ return c=='z' ? 'a' : ++c; }
};
*/

int main(int argc, const char * argv[]) {
    
    
    Solution s;
    cout << s.countSegments(" a ");
    
    
    /*
    Solution s; string p="zabc";
    cout << s.findSubstringInWraproundString(p) << endl;
     */
    
    return 0;
}
