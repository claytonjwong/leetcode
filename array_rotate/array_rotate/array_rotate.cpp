//
//  main.cpp
//  array_rotate
//
//  Created by CLAYTON WONG on 8/4/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        // no need to rotate completely, since its the same vector
        int shifts = k % nums.size();
        if (shifts==0){
            return;
        }
        
        // create new vector and make second chunk the first chunk
        vector<int>::iterator new_beginning=nums.end() - shifts;
        vector<int> new_nums = vector<int>(new_beginning, nums.end());
        
        // make first chunk the second chunk and set nums to the newly formed vector
        new_nums.insert(new_nums.end(), nums.begin(), new_beginning);
        nums = new_nums;
    }
    
    void rotate2(int nums[], int n, int k) {
        k = k % n;
        reverse(nums, nums + n);
        reverse(nums, nums + k);
        reverse(nums + k, nums + n);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> test { 1,2,3,4,5,6,7 };
    solution.rotate(test, 3);
    
    int nums[7] = {1,2,3,4,5,6,7};
    
    solution.rotate2(nums, 7, 3);
    
    
    
    return 0;
}
