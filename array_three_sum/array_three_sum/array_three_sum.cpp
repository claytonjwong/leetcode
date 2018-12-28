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

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        //
        // sort nums, then strategically check for a+b+c=0 as a = -(b+c)
        //
        // ex:
        //
        // -2, -1, 0, 1, 2
        //  a   b        c ==> a+b+c = -2 -1 2 = -1, increment b to try and find a larger sum
        //  a      b     c ==> a+b+c = -2 + 0 + 2 = 0
        //
        //      a  b     c ==> a+b+c = -1 + 0 + 2 = 1, decrement c to try and find a smaller sum
        //      a  b  c    ==> a+b+c = -1 + 0 + 1 = 0
        //
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 3){
            return result;
        }
        
        int a=0;
        int b=a+1;
        int c = (int)nums.size() - 1;
        
        while ( a <= nums.size() - 3 ){ // [0:size-2]
            
            while ( b < c ){
                int csum = nums[a] + nums[b] + nums[c]; // current sum
                
                if ( csum == 0 ){ // match
                
                    vector<int> zvec = { nums[a], nums[b], nums[c] };
                    result.push_back( zvec );
                    
                    // iterate inwards until all b/c combos are exhausted
                    do { b++; } while ( b < c and nums[b-1] == nums[b] );
                    do { c--; } while ( b < c and nums[c] == nums[c+1] );
                
                } else if ( csum < 0 ) { // current sum is too small, increment b
                    do { b++; } while ( b < c and nums[b-1] == nums[b] );
                    
                } else if ( csum > 0 ) { // current sum is too big, decrement c
                    do { c--; } while ( b < c and nums[c] == nums[c+1] );
                }
            }
            
            do { a++; } while ( nums[a-1] == nums[a] and a <= nums.size() - 3 );
            b=a+1;
            c=(int)nums.size() - 1;
        }
        
        return result;
    }
};



int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    
    
    vector<int> nums = {-1,0,1,2,-1,-4};
    
    vector<vector<int>> result = solution.threeSum(nums);
    
    for (auto v : result){
        cout << "[";
        for (auto num : v){
            cout << to_string(num) << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
