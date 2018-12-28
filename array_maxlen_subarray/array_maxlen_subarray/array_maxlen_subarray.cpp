/*
 
 718. Maximum Length of Repeated Subarray
 
 https://leetcode.com/contest/leetcode-weekly-contest-56/problems/maximum-length-of-repeated-subarray/
 
 Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
 
 Example 1:
 Input:
 A: [1,2,3,2,1]
 B: [3,2,1,4,7]
 Output: 3
 Explanation:
 The repeated subarray with maximum length is [3, 2, 1].
 Note:
 1 <= len(A), len(B) <= 1000
 0 <= A[i], B[i] < 100
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxi=0;
        for (int i=0; i<A.size(); ++i){
            for (int j=0; j<B.size(); ++j){
                int k=0;
                while (i+k<A.size() && j+k<B.size() && A[i+k]==B[j+k]){
                    ++k;
                }
                maxi=max(maxi,k);
            }
        }
        return maxi;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> A { 0,1,1,1,1 };
    vector<int> B { 1,0,1,0,1 };
    
    Solution solution;
    cout << solution.findLength(A, B) << endl;
    
    
    
    return 0;
}




