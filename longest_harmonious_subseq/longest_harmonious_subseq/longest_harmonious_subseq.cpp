/*
 
 594. Longest Harmonious Subsequence
 
 Q: https://leetcode.com/problems/longest-harmonious-subsequence/description/
 A: https://leetcode.com/problems/longest-harmonious-subsequence/discuss/130355/2-liner-C++
 
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    int findLHS(vector<int>& A) {
        unordered_map<int,int> m;
        for (auto x: A) ++m[x];
        int ans=0;
        for (auto x: m)
            if (m.count(x.first-1))
                ans=max(ans,m[x.first]+m[x.first-1]);
        return ans;
    }
};
*/


class Solution {
public:
    int findLHS(vector<int>& A, unordered_map<int,int> m={}, int ans=0) {
        for (auto x: A) ++m[x];
        for (auto& x: m) ans=max(ans,m.count(x.first-1) ? m[x.first]+m[x.first-1] : 0);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> nums{1,3,2,2,5,2,3,7};
    cout << s.findLHS(nums) << endl;
    
    return 0;
}


