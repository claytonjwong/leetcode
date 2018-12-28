/*
 
 53. Maximum Subarray
 
 https://leetcode.com/problems/maximum-subarray/tabs/description
 
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // iterate through each num in nums
        // keep track of sum so far if < 0, then set sum so far to 0
        // keep track of max sum ending here and update for each new max
        // return max sum
        if (nums.empty()){
            return 0;
        }
        
        int sum_so_far = 0;
        int max_sum_ending_here = nums[0];
        for (auto num : nums){
            
            // sequential sum
            sum_so_far += num;

            // reset sum_so_far == num if it is larger than the previous sequential sum
            sum_so_far = max ( sum_so_far, num );
            
            // keep track of max at each ending position
            max_sum_ending_here = max ( max_sum_ending_here, sum_so_far );
        }
        
        return max_sum_ending_here;
    }
};

int main(int argc, const char * argv[]) {
   
    Solution solution;
    vector<int> test {-1};
    
    
    cout << "-1 == " << solution.maxSubArray(test) << endl << endl;
    return 0;
}
