/*
 
 15. 3Sum
 
 https://leetcode.com/problems/3sum/#/description
 
 
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note: The solution set must not contain duplicate triplets.
 
 For example, given array S = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        set<vector<int>> zeroSum{};
        if (nums.size()<3){ return vector<vector<int>>(); }
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size()-2; ++i){
            int left=i+1, right=(int)nums.size()-1, sum=0;
            while (left<right){
                sum=nums[i]+nums[left]+nums[right];
                if (sum==0){
                    zeroSum.insert(vector<int>{nums[i],nums[left],nums[right]});
                    ++left; --right;
                }
                else if (sum<0) { ++left;  }
                else if (sum>0) { --right; }
            }
        }
        return vector<vector<int>>(zeroSum.begin(),zeroSum.end());
    }

};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> numbers { -1, 0, 1, 2, -1, 4 };
    
    vector<vector<int>> ret = solution.threeSum(numbers);
    
    return 0;
}
