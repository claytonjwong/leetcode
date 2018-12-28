/*
 
 416. Partition Equal Subset Sum
 
 https://leetcode.com/problems/partition-equal-subset-sum/description/
 
 Given a non-empty array containing only positive integers, find if the array
 can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 
 Note:
 Each of the array element will not exceed 100.
 The array size will not exceed 200.
 Example 1:
 
 Input: [1, 5, 11, 5]
 
 Output: true
 
 Explanation: The array can be partitioned as [1, 5, 5] and [11].
 Example 2:
 
 Input: [1, 2, 3, 5]
 
 Output: false
 
 Explanation: The array cannot be partitioned into equal sum subsets.
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void print(vector<vector<bool>>& dp){
    cout << "  ";
    for (int i=0; i<dp[0].size(); ++i)
        cout << i%10;
    cout << endl;
    for (int i=0; i<dp.size(); ++i){
        cout << i%10 << " ";
        for (int j=0; j<dp[0].size(); ++j)
            cout << dp[i][j];
        cout << endl;
    }
}

/*
 
 Input: { 1,5,11,5 }
 
 dp[][]:
 
   01234567890123456789012
 0 10000000000000000000000
 1 01000000000000000000000
 2 01000010000000000000000
 3 01000010000010000100000
 4 01000010000110000100001
 
 */
// AC
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=(int)nums.size();
        for (auto num: nums) sum+=num;
        int target=sum/2;
        if (sum%2 || *max_element(nums.begin(),nums.end())>target) return false;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        dp[0][0]=true; // with i=0 items, we can reach the sum of 0
        for (int i=1; i<=n; ++i){
            for (int j=0; j<=target; ++j){
                dp[i][j]=dp[i-1][j];  // without i-th item
                if (!dp[i][j] && j>=nums[i-1])
                    dp[i][j]=dp[i-1][j-nums[i-1]]; // with i-th item
            }
        }
        return dp[n][target];
    }
};
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=(int)nums.size();
        for (auto num: nums) sum+=num;
        int target=sum/2;
        if (sum%2 || *max_element(nums.begin(),nums.end())>target) return false;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for (auto num: nums){
            for (int i=target; i>=0; --i){
                if (i-num<0) continue;
                if (dp[i-num]){
                    dp[i]=true;
                }
            }
        }
        return dp[target];
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> nums { 5,1,5,11 };
    cout << s.canPartition(nums) << endl;
    
    return 0;
}








