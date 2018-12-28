/*
 
 1. Two Sum
 
 https://leetcode.com/problems/two-sum/#/description
 
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

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res;
        unordered_map<int,int> map{};
        for (int i=0; i<nums.size(); ++i){
            int compliment=target-nums[i];
            if (map.find(compliment)!=map.end()){
                res.push_back(map[compliment]);
                res.push_back(i);
                break;
            }
            map[nums[i]]=i;
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    
    vector<int> nums = { 3, 3 };
    int target = 6;
    
    vector<int> result = solution.twoSum(nums, target);
    cout << "[0,1] == [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
