/*
 
 152. Maximum Product Subarray
 
 https://leetcode.com/problems/maximum-product-subarray/description/
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int mini=nums[0],maxi=nums[0],res=nums[0];
        for (int i=1; i<nums.size(); ++i){
            int prev=mini;
            mini=min({nums[i],mini*nums[i],maxi*nums[i]});
            maxi=max({nums[i],prev*nums[i],maxi*nums[i]});
            res=max(res,maxi);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums { 2,3,-2,4 };
    Solution s;
    cout << s.maxProduct(nums) << endl;
    
    
    return 0;
}



