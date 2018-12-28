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

class Solution1 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res=0, size=(int)A.size();
        if (size < 3) { return 0; }
        for (int i=0; i < size-2; i++){
            int delta=A[i]-A[i+1];
            for (int j=i+2; j < size && A[j-1]-A[j]==delta; j++) { res++; }
        }
        return res;
    }
};


class Solution2{
public:
    int numberOfArithmeticSlices(vector<int>& nums){
        int sz=(int)nums.size();
        if (sz < 3) { return 0; }
        int prev=0;
        for (int i=2; i<sz; i++){
            if (nums[i-2]-nums[i-1]==nums[i-1]-nums[i]) {
                ++prev;
                _sum+=prev;
            } else {
                prev=0;
            }
        }
        return _sum;
    }
private:
    int _sum=0;
};

int main(int argc, const char * argv[]) {

    Solution1 solution;
    vector<int> nums { 1,2,3,8,9,10 };
    cout << "Slices: : " << solution.numberOfArithmeticSlices(nums) << endl;

    
    return 0;
}
