/*
 
 16. 3Sum Closest
 
 https://leetcode.com/problems/3sum-closest/#/description
 
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 
 For example, given array S = {-1 2 1 -4}, and target = 1.
 
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
 */

#include <iostream>
#include <vector>
#include <cmath>
#include "limits.h"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        long result = INT_MAX;
        
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
        
        int a=0;
        int b=a+1;
        int c = (int)nums.size() - 1;
        
        while ( a <= nums.size() - 3 ){ // [0:size-2]
            
            while ( b < c ){
                
                int csum = nums[a] + nums[b] + nums[c]; // current sum
                
                if ( abs((long)target-csum) < abs((long)target-result) ) { // closer match
                    
                    result = csum;
                    
                    // match, cannot get closer to target, return
                    if ( result == (long)target ) { return (int)result; }
                }
                
                if ( csum < target ) { // current sum is too small, increment b
                    do { b++; } while ( b < c and nums[b-1] == nums[b] );
                }
                
                if ( csum > target ) { // current sum is too big, decrement c
                    do { c--; } while ( b < c and nums[c] == nums[c+1] );
                }
            }
            
            do { a++; } while ( nums[a-1] == nums[a] and a <= nums.size() - 3 );
            b=a+1;
            c=(int)nums.size() - 1;
        }
        
        return (int)result;
    }
};



int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    
    
    vector<int> nums = {1,1,-1,-1,3};
    
    int result = solution.threeSumClosest(nums, -1);
    
    cout << result << endl;
    
    return 0;
}
