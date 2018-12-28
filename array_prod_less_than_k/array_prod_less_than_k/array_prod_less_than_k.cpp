/*
 
 713. Subarray Product Less Than K
 
 https://leetcode.com/contest/leetcode-weekly-contest-55/problems/subarray-product-less-than-k/
 
 Your are given an array of positive integers nums.
 
 Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
 
 Example 1:
 Input: nums = [10, 5, 2, 6], k = 100
 Output: 8
 Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
 Note:
 
 0 < nums.length <= 50000.
 0 < nums[i] < 1000.
 0 <= k < 10^6.
 
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0, sz=(int)nums.size();
        for (int i=0; i<sz-1; ++i){
            if (nums[i]>=k) continue;
            ++cnt;
            long prod=nums[i];
            for (int j=i+1; j<sz; ++j){
                prod*=nums[j];
                if (prod<k)
                    ++cnt;
                else
                    break;
            }
        }
        return nums[sz-1] >= k ? cnt : cnt+1;
    }
};


int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> nums{10,5,2,6};
    cout << solution.numSubarrayProductLessThanK(nums, 100) << endl;
    return 0;
}
