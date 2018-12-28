/*
 
 26. Remove Duplicates from Sorted Array
 
 https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
 
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array nums = [1,1,2],
 
 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        
        if (nums.size() < 2){
            return nums.size(); // no dups possible for size 0 or 1
        }
        
        // remove dups for size >= 2, increment j for all non-dups
        // and the new length is j+1
        int j = 0;
        for (int i = 1; i < nums.size(); i++){
            
            if ( nums[j] != nums[i] ){
                j++;
                nums[j] = nums[i]; // j == i if there is no dup
            }
            
        }
        return j+1;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> test_nums = { 1,1,2 };
    
    cout << "solution.removeDuplicates(test_nums): " << solution.removeDuplicates(test_nums) << endl << endl;
    
    return 0;
}
