/*
 
 238. Product of Array Except Self
 
 https://leetcode.com/problems/product-of-array-except-self/description/
 
 Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 
 Solve it without division and in O(n).
 
 For example, given [1,2,3,4], return [24,12,8,6].
 
 Follow up:
 Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int zeros=0,prod=1;
        for (auto& num : nums) {
            if (num) { prod*=num; }
            else     { ++zeros;   }
        }
        if (zeros==0){
            for (auto& num : nums) { num=prod/num; }
        } else if (zeros==1){
            for (auto& num : nums) {
                if (num) { num=0;    }
                else     { num=prod; }
            }
        } else { // zeros > 1
            transform(nums.begin(),nums.end(),nums.begin(),
                      [](int& x){ return 0; });
        }
        return nums;
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int> nums { 1,0,3,6 };
    Solution solution;
    nums = solution.productExceptSelf(nums);
    
    
    return 0;
}




