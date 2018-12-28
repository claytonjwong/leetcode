/*
 
 209. Minimum Size Subarray Sum
 
 https://leetcode.com/problems/minimum-size-subarray-sum/description/
 
 Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 
 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
 
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
// TLE
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> sums(n+1);
        for (int i=1; i<=n; ++i)
            sums[i]+=nums[i]+sums[i-1];
        for (int sz=1; sz<=nums.size(); ++sz){
            for (int i=0; i+sz<=n; ++i){
                int s=accumulate(nums.begin()+i,nums.begin()+i+sz,0);
                if (s>=target) return sz;
            }
        }
        return 0;
    }
};
 */


// AC
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> sums(n+1);
        for (int i=1; i<=n; ++i)
            sums[i]+=nums[i-1]+sums[i-1];
        for (int offset=0; offset<n; ++offset){
            for (int i=0; i+offset<n; ++i){
                int left=i,right=i+offset;
                int currSum=sums[right+1]-sums[left];
                if (currSum>=target)
                    return offset+1;
            }
        }
        return 0;
    }
};


/*
 // AC
class Solution {
public:
    int minSubArrayLen(int t, vector<int>& n) {
        int N=(int)n.size();
        vector<int> s(N+1);
        for (int i=1; i<=N; ++i)
            s[i]+=n[i-1]+s[i-1];
        for (int k=0; k<N; ++k)
            for (int i=0; i+k<N; ++i)
                if (s[i+k+1]-s[i]>=t)
                    return k+1;
        return 0;
    }
};
*/


int main(int argc, const char * argv[]) {
    
    int target=7;
    vector<int> v{2,3,1,2,4,3};
    Solution s;
    cout << s.minSubArrayLen(target, v) << endl;
    return 0;
}
