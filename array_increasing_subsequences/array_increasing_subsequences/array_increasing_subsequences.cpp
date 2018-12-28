/*
 
 491. Increasing Subsequences
 
 https://leetcode.com/problems/increasing-subsequences/description/
 
 Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
 
 Example:
 Input: [4, 6, 7, 7]
 Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 Note:
 The length of the given array will not exceed 15.
 The range of integer in the given array is [-100,100].
 The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
 
 */

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res{};
        helper(nums,{},0,res);
        return res;
    }
    
private:
    void helper(const vector<int>& nums, vector<int>&& subs,
                const int& start, vector<vector<int>>& res){
        if (subs.size()>=2) res.push_back(subs);
        unordered_map<int,bool> hash{};
        for (int i=start; i<nums.size(); ++i){ // iterative back-tracking
            if ((subs.empty() || subs.back()<=nums[i])
                && hash.find(nums[i])==hash.end()){ // recursive constraint
                subs.push_back(nums[i]);
                hash[nums[i]]=true;
                helper(nums,{subs.begin(),subs.end()},i+1,res); // forward-tracking
                subs.pop_back();
            }
        }
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int> nums = { 4, 6, 7, 7 };
    
    Solution solution;
    vector<vector<int>> res=solution.findSubsequences(nums);
    
    return 0;
}





