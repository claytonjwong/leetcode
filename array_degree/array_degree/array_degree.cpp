/*
 
 697. Degree of an Array
 
 https://leetcode.com/contest/leetcode-weekly-contest-54/problems/degree-of-an-array/
 
 Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
 
 Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
 
 Example 1:
 Input: [1, 2, 2, 3, 1]
 Output: 2
 Explanation:
 The input array has a degree of 2 because both elements 1 and 2 appear twice.
 Of the subarrays that have the same degree:
 [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 The shortest length is 2. So return 2.
 Example 2:
 Input: [1,2,2,3,1,4,2]
 Output: 6
 Note:
 
 nums.length will be between 1 and 50,000.
 nums[i] will be an integer between 0 and 49,999.
 
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> m{}; // key=number val=indices of number
        int max_freq=0;
        for (int i=0; i<nums.size(); ++i){
            auto num=nums[i];
            m[num].push_back(i);
            max_freq=max(max_freq,(int)m[num].size());
        }
        int min_len=50000;
        for (auto &&x : m){
            if (x.second.size()==max_freq){
                int curr_len=
                    *max_element(x.second.begin(),x.second.end())
                   -*min_element(x.second.begin(),x.second.end())+1; // +1 for inclusive end-points
                min_len=min(min_len,curr_len);
            }
        }
        return min_len;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    vector<int> nums = { 1,2,2,3,1,4,2 };
    cout << solution.findShortestSubArray(nums) << endl;
    
    
    
    return 0;
}









