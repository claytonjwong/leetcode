/*
 
 53. Maximum Subarray
 
 https://leetcode.com/problems/maximum-subarray/tabs/description
 
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 
 */



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int maxSubArray(vector<int>& array){
        
        if (array.empty()) { return 0; }
        
        int currSum = 0;
        int maxSum = array[0];
        for ( auto num : array ){
            
            currSum += num;
            
            if (num > currSum){
                currSum = num;
            }
            
            maxSum = max ( maxSum, currSum );
            
        }
        
        return maxSum;
    }
    
};

int main(int argc, const char * argv[]) {
    
    vector<int> test { -2,1,-3,4,-1,2,1,-5,4 };
    
    Solution solution;
    cout << solution.maxSubArray(test) << endl;
    
    
    
    return 0;
}



