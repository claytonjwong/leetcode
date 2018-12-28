/*
 
 477. Total Hamming Distance

 
 https://leetcode.com/problems/total-hamming-distance/description/
 
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 
 Now your job is to find the total Hamming distance between all pairs of the given numbers.
 
 Example:
 Input: 4, 14, 2
 
 Output: 6
 
 Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
 showing the four bits relevant in this case). So the answer will be:
 HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
 Note:
 Elements of the given array are in the range of 0 to 10^9
 Length of the array will not exceed 10^4.
 
 */

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
    
    /* Brute force TLE */
//    int totalHammingDistance(vector<int>& nums) {
//        
//        if (nums.empty()){
//            return 0;
//        }
//        
//        int total = 0;
//        for (int i=0; i < nums.size()-1; i++){
//            for (int j=i+1; j < nums.size(); j++){
//                total += __builtin_popcount(nums[i] ^ nums[j]);
//            }
//        }
//        return total;
//    }
    
    
    /*
    
    better solution is to iterate through each bit position,
    count the amount of 1s and the amount of 0s,
    then multiply those counts for calculating the hamming distance for that bit position
    
    now we know how to calculate the hamming distance for one bit position,
    we can repeat this for every bit position, and sum up those products
    to calculate the total hamming distance
     
    Example: for size 3
     
    n = 3
     
     4  = 0100
     14 = 1110
     2  = 0010

          1220  k   = count of bits set to 1 for this bit position
          2113  n-k = count of bits set to 0 for this bit position
     
     k * ( n - k ) is the amount of permutations of 0s and 1s for that bit position
     
     */
    int totalHammingDistance(vector<int>& nums){
        
        int total = 0;
        
        if (nums.size() < 2){
            return 0;
        }
        
        //
        // iterate through each bit position from right-to-left
        //
        int k[32];
        for (int i=0; i < 32; i++){
            
            //
            // count the amount of 1s for this bit position
            // ( the amount of 0s can be deduced based on the size of the array )
            //
            k[i]=0;
            for (auto num : nums){
                if (num & (1 << i)){
                    k[i]++;
                }
            }
            total += k[i] * (nums.size() - k[i]); // (amount of 1s) X (amount of 0s)
        }
        
        return total;
    }

};


int main(int argc, const char * argv[]) {

    
    Solution solution;
    
    vector<int> test {4,14,2};
    
    cout << "6 == " << solution.totalHammingDistance(test) << endl;
    
    return 0;
}




