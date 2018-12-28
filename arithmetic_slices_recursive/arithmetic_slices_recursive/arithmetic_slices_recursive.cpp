/*

 413. Arithmetic Slices
 
 https://leetcode.com/problems/arithmetic-slices/description/
 
 A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 
 For example, these are arithmetic sequence:
 
 1, 3, 5, 7, 9
 7, 7, 7, 7
 3, -1, -5, -9
 The following sequence is not arithmetic.
 
 1, 1, 2, 5, 7
 
 A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 
 A slice (P, Q) of array A is called arithmetic if the sequence:
 A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 
 The function should return the number of arithmetic slices in the array A.
 
 
 Example:
 
 A = [1, 2, 3, 4]
 
 return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 
 */


#include <iostream>
#include <vector>

using namespace std;
/*
class Solution{
public:
    Solution() : _count{0} {}
    
    int numberOfArithmeticSlices(vector<int>& nums){
        int size=(int)nums.size();
        helper(nums, size-1);
        return _count;
    }
    
    int helper(vector<int>& nums, int end){
        if (end < 2) { return 0; }
        int slices=0;
        if ((nums[end-2] - nums[end-1]) == (nums[end-1] - nums[end])){
            slices = 1 + helper(nums, end-1);
            _count += slices;
        } else {
            helper(nums, end-1);
        }
        return slices;
    }
    
private:
    int _count;
};
*/

/*
class Solution{
public:
    
    int numberOfArithmeticSlices(vector<int>& nums){
        int sum=0, sz=(int)nums.size();
        if (sz < 3) { return 0; }
        vector<int> dp(sz);
        dp[0]=0;
        dp[1]=0;
        for (int i=2; i<sz; i++){
            if (nums[i-2]-nums[i-1]==nums[i-1]-nums[i]) {
                sum+=dp[i]=dp[i-1]+1;
            }
        }
        return sum;
    }
};
 */


class Solution{
public:
    
    int numberOfArithmeticSlices(vector<int>& nums){
        int sum=0, sz=(int)nums.size();
        if (sz < 3) { return 0; }
        int dp=0;
        for (int i=2; i<sz; i++){
            if (nums[i-2]-nums[i-1]==nums[i-1]-nums[i]) {
                sum+=++dp;
            }
        }
        return sum;
    }
};


int main(int argc, const char * argv[]) {

    vector<int> A { 1,2,3,4 };
    Solution solution;
    
    cout << solution.numberOfArithmeticSlices(A) << endl;
    
    
    return 0;
}





