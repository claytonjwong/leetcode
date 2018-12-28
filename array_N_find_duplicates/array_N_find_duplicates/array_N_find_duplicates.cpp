/*
 
 442. Find All Duplicates in an Array
 
 https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/
 
 Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements that appear twice in this array.
 
 Could you do it without extra space and in O(n) runtime?
 
 Example:
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [2,3]
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> res;
        
        int i=0;
        while(i < nums.size()){
            
            // move nums[nums[i]-1] into proper position (if not already there)
            // nums[0] = 1
            // nums[1] = 2
            // nums[2] = 3
            // etc
            if (nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            } else {
                i++;
            }
        }
        
        for (int i=0; i < (int)nums.size(); i++){
            if (nums[i] != i+1){
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {

    vector<int> nums { 4,3,2,7,8,2,3,1 };
    
    Solution solution;

    vector<int> result = solution.findDuplicates(nums);
    for ( auto el : result ){
        cout << el << ", ";
    }
    cout << endl;
    
    return 0;
}



