/*

 659. Split Array into Consecutive Subsequences
 
 https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 
 You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
 
 Example 1:
 Input: [1,2,3,3,4,5]
 Output: True
 Explanation:
 You can split them into two consecutive subsequences :
 1, 2, 3
 3, 4, 5
 
 Example 2:
 Input: [1,2,3,3,4,4,5,5]
 Output: True
 Explanation:
 You can split them into two consecutive subsequences :
 1, 2, 3, 4, 5
 3, 4, 5
 
 Example 3:
 Input: [1,2,3,4,4,5]
 Output: False
 Note:
 The length of the input is in range of [1, 10000]
 
 */

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // key is the last number in the subarray
        // val is a min heap of subarray sizes
        unordered_map<int,priority_queue<int,vector<int>,std::greater<int>>> m{};
        for (auto &&num: nums){
            if (m.find(num-1)==m.end() || m[num-1].empty()){
                // subarray ending in num-1 NOT found,
                // create new subarray of size 1 ending in num
                m[num].push(1);
            } else {
                // subarray ending in num-1 is found, pop off,
                // and increment size by one for subarray ending in num
                int sz=m[num-1].top();
                m[num-1].pop();
                m[num].push(sz+1);
            }
        }
        for (auto itr=m.begin(); itr!=m.end(); ++itr){
            if (!itr->second.empty() && itr->second.top()<3) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {

    vector<int> nums { 1,2,2,3,3,4 };
    Solution solution;
    cout << solution.isPossible(nums) << endl;
    
    return 0;
}




