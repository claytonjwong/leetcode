/*
 
 280. Wiggle Sort
 
 https://leetcode.com/problems/wiggle-sort/description/
 
 Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 
 For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        weave(nums);
        
    }
    
    void weave(vector<int>& nums){
        
        if (nums.size() <= 2) { return; } // nothing to weave together
    
        //
        // swap sorted pairs
        //
        vector<int>::iterator itr = nums.begin() + 2;
        while (itr <= nums.end()-1){
            
            swap( *(itr-1), *(itr) );
            
            itr += 2;
        }
    }
    
};




int main(int argc, const char * argv[]) {
    
    vector<int> nums{3,2,1,0,-1};
    
    Solution solution;
    solution.wiggleSort(nums);
    
    for ( auto num : nums ){
        cout << num << ",";
    }
    cout << endl;
    
    return 0;
}
