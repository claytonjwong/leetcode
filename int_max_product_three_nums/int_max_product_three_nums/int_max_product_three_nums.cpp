/*
 
 628. Maximum Product of Three Numbers
 
 https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 
 Given an integer array, find three numbers whose product is maximum and output the maximum product.
 
 Example 1:
 Input: [1,2,3]
 Output: 6
 Example 2:
 Input: [1,2,3,4]
 Output: 24
 Note:
 The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size=(int)nums.size();
        if (size < 3) { return 0; }
        sort(nums.begin(), nums.end());
        return max ( nums[0]*nums[1]*nums[size-1], nums[size-3]*nums[size-2]*nums[size-1] );
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums { 5, 3, 2, 1, 2, 3, -4, -5 };
    
    Solution solution;
    cout << solution.maximumProduct(nums) << endl;
    
    return 0;
}




