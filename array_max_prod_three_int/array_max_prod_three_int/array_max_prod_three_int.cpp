/*
 
 given an interger array, return the maximum product of 3 integers
 
 */

#include <iostream>
#include <vector>

using namespace std;


long max_prod(vector<int>& nums){
    
    if (nums.size() < 3){
        return INT_MIN;
    }
    
    sort(nums.begin(), nums.end());
    
    // case 1: all numbers are negative,
    // take 3 negative closest to 0 ( right hand side of sorted array )
    
    // case 2: 2 or more negative and 1 or more positive numbers,
    // take the 2 most neg and largest pos
    
    // case 3: largest pos ( right hand side of sorted array )
    

    return max (
        nums[0] * nums[1] * nums[nums.size()-1],
        nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3]);
}


int main(int argc, const char * argv[]) {

    
    vector<int> test1 { 5,4,3,2,1 }; // 1,2,3,4,5 = 3*4*5 = 60
    vector<int> test2 { 5,4, -3, -2, -1 }; // -3, -2, -1, 4, 5 = -3 * -2 * 5 = 30
    vector<int> test3 { 3, 5, -2, -3 }; // -3, -2, 3, 5 = -3 * -2 * 5 = 30
    
    cout << max_prod(test1) << endl;
    cout << max_prod(test2) << endl;
    cout << max_prod(test3) << endl;
    
    return 0;
}





