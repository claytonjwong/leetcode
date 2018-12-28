/*
 
 1. Two Sum
 
 https://leetcode.com/problems/two-sum/description/
 
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int i=0,j=0;
        for (; i<nums.size(); ++i){
            int delta=target-nums[i];
            if (m.count(delta)){
                j=m[delta];
                break;
            }
            m[nums[i]]=i;
        }
        return vector<int>{i,j};
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums { 3,3 };
    int target=6;
    Solution s;
    auto res=s.twoSum(nums, target);
    
    return 0;
}


