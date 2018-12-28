/*
 
 27. Remove Element
 
 https://leetcode.com/problems/remove-element/#/description
 
 Given an array and a value, remove all instances of that value in place and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 
 Example:
 Given input array nums = [3,2,2,3], val = 3
 
 Your function should return length = 2, with the first two elements of nums being 2.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if (nums.empty()){
            return 0;
        }
            
        // swap all instances of val to the end of the array
        int i = 0;
        int j = (int)nums.size() - 1;
        while ( true ){

            // end index
            while ( i < j && nums[j] == val ){
                j--;
            }
            
            if ( i == j ){
                break;
            }
            
            // move val to the the end
            if (nums[i] == val){
                
                // swap i and j
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            
            i++;

        }
        
        // if i is val, then return i as the array length
        // so that n[i] is NOT included in the array
        if ( nums[i] == val ){
            return i;
        } else {
            return i+1;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> test = { 2, 1, 1, 1 };
    cout << "1 == " << solution.removeElement(test, 1) << endl << endl;
    
    return 0;
}
