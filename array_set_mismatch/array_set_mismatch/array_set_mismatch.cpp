/*
 
 645. Set Mismatch
 
 https://leetcode.com/contest/leetcode-weekly-contest-42/problems/set-mismatch/
 
 The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
 
 Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
 
 Example 1:
 Input: nums = [1,2,2,4]
 Output: [2,3]
 Note:
 The given array size will in the range [2, 10000].
 The given array's numbers won't have any order.
 
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int duplicate=0;
        
        // add numbers into a hash, when the hash size is unchanged, then we found the duplicate number
        set<int> unique;
        
        // add up each number in the hash to find the duplicate and the actual sum
        int unique_size=0;
        int actual_sum=0;
        for (auto num : nums){
            unique.insert(num);
            unique_size+=1;
            if (duplicate==0 && unique.size() != unique_size){
                duplicate=num;
            }
            actual_sum+=num;
        }
        
        // subtract the actual sum (not including the dupicate)
        // from the sum of the series to find the missing number
        int n = (int)nums.size();
        int sum_of_series = n * ( n + 1 ) / 2;
        int missing_number = sum_of_series - ( actual_sum - duplicate );
        
        return vector<int> { duplicate, missing_number };
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    
    // 1+2+3+4 = 10
    // 1+2+2+4 =  9
    vector<int> test = { 2, 2 };
    
    
    
    cout << "[duplicate,missing] == 2,3, == ";
    
    vector<int> r = solution.findErrorNums(test);
    for (auto n : r){
        cout << n << ",";
    }
    cout << endl << endl;

    return 0;
}
