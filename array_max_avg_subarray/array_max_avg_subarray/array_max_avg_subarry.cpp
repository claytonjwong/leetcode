//
//  main.cpp
//  array_max_avg_subarray
//
//  Created by CLAYTON WONG on 7/15/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;

        // add up first k
        for (int i=0; i < k and i < nums.size(); i++){
            sum += nums[i];
        }
        
        // slide left and find the max sum
        double max = sum;
        for (int i=1; i <= nums.size() - k; i++){
            sum = sum - nums[i-1] + nums[i+k-1];
            if (sum > max){
                max = sum;
            }
        }
        
        // max avg
        return max / k;
    }
    
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> test = { 1,2,3,4 };
    
    double result = solution.findMaxAverage(test, 3);
    
    cout << result;
    
    return 0;
}
