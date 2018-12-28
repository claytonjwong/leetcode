/*
 
 416. Partition Equal Subset Sum
 
 https://leetcode.com/problems/partition-equal-subset-sum/description/
 
 Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 
 Note:
 Each of the array element will not exceed 100.
 The array size will not exceed 200.
 Example 1:
 
 Input: [1, 5, 11, 5]
 
 Output: true
 
 Explanation: The array can be partitioned as [1, 5, 5] and [11].
 Example 2:
 
 Input: [1, 2, 3, 5]
 
 Output: false
 
 Explanation: The array cannot be partitioned into equal sum subsets.
 
 
 
 Solution:
 
 Part 1: First think what the value of the sum of two equal subsets of an array would need to be. It would need to be half of the sum of the array. For example, the array [1,2,3] can be split into two equal subsets whose sums are equal. The first subset is [1,2] and the second subset is [3]. From this example, we find that the sum of the array [1,2,3] is 1+2+3=6, and the sum of each equal sum subset is 1+2=3 and 3=3. So in order for the two subset sums to be equal, they would each need to sum up to half of the sum of the original array. The sum of the original array is 1+2+3=6, and half of that is 6/2=3.
 
 Part 2: Two equal subsequences of the array can only be achieved if the sum of the entire array is even. This is because we are attempting to partition an array of integers. For example, if the array is: [1,2,3,4,5], then the sum of the array is 1+2+3+4+5=15. The value for the sum of each subset of this array would then need to be 15/2=7.5, which is NOT possible, since integers are whole numbers only. So the first part of this solution is to calculate the sum of the array and check if the sum is odd. If so, we can immediately return false since we know it is impossible to partition this array into two equal subset sums of integers:
 
 int sum=accumulate(nums.begin(), nums.end(), 0);
 if (sum % 2) { return false; }
 Next, there is a check to see if the maximum element is greater than half of the sum of the array. If there is a single element greater than half of the array, then there is no possible subset of the array which could be equal to half of the array sum. Take for example the array [2,4,10]. The sum of this array is 2+4+10=16. In order to have two equal subsets for this array, each subset sum would need to be 16/2=8. Since 10 is larger than 8, there is no possible solution. We know for certain that the sum of the remainder of the array without 10 cannot equal 8. In fact the sum of the remainder of the array is 2+4=6 < 8. So again we can immediately return false.
 
 int half = sum / 2;
 if (*max_element(nums.begin(), nums.end()) > half) { return false; }
 
 Part 3: The following loops iterate through each number in the original array to see what sum value can be reached with that number, and without that number. This is the act of analyzing each number. There are two subsets total which we are attempting to partition this array into. So each number is either included in one subset XOR the other subset. We don't care which subset the number belongs to, but we track both use cases by using an array of flags which track which sums can be reached through the sum with or without the current number being analyzed and with or without all the previous numbers analyzed so far. Using dynamic programming for any arbitrary i-th value, we can reach that value if we could previously reach the i-th value minus the current number being analyzed. This is much easier to understand with an example. The example below starts with the base case and builds from there.
 
 The base case is reach[0]=1. This basically means that we can reach of the sum of 0 always, by basically doing nothing as far as analyzing the numbers in the array. With no numbers in a subset of the array, we can always reach the sum of no numbers as 0. The sum of nothing is 0. And yes we can reach 0 with nothing.
 
 Our end-goal is to reach half the sum of the original array as previously discussed in Part 1. If we can somehow reach the sum of half the original array, then we know the original array can be partitioned into two equal sum subsets. Therefore we need to track the total sum of a subset by including XOR not including each number in one of the two subsets. Then check if the total sum of the subset can reach half of the sum of the original array. Therefore, the size of the vector (which tracks the possible total sums of numbers in the subset) needs to be half of the sum of the original array, +1 for the base case 0.
 
 vector<bool> reach(half+1, false);
 reach[0]=1;
 
 For the iterative case, let's look at the example array [1,2,3] again. We will analyze each number of this array iteratively building our total sum reach from the base case sum onwards. The first number under analysis is 1. There are two possibilities. Either 1 is included in the subset XOR it is NOT included in the subset. If it is NOT included, then we can only reach 0 so far. If it is included, then we can reach 1 as well. Since we can reach 0, and since the number 1 can be included in the subset, we can also reach 1. Therefore we can reach any arbitrary i-th sum if we could previously reach that sum without the number currently under analysis. In this example, the sum we can reach is 1 because we can reach 0 and the sum value of 1 minus the value of the current number under analysis 1 is 0. 1-1=0.
 
 Below are possible sums which can be reached BEFORE analyzing the current number 1. This is the same as saying "with an empty subset, yes it is true that we can reach the total sum of 0 with nothing":
 
 reach[0]=true    // base case, we can reach the sum of 0 with nothing
 reach[1]=false
 reach[2]=false
 reach[3]=false
 
 AFTER analyzing the current number 1, there are two possibilities ( either 1 is included in the subset sum or it is NOT included in the subset sum ). Both of these use cases are tracked now. Without 1 in the subset, we can reach 0. With 1 in the subset, we can reach 1. We don't care if 1 is included the subset or not, so we flag both of these use cases:
 
 reach[0]=true
 reach[1]=true   // 1-1=0, set reach[1]=true, since reach[0] is true
 reach[2]=false
 reach[3]=false
 
 Next we analyze the next number in the array [1,2,3]. The next number is 2. With 2, we can reach the sum of half the original array. The sum of the array [1,2,3] is 1+2+3=6, so half that sum is 6/2=3. Since half=3, half minus the current number under analysis 2 is 1. 3-2=1. We know from the previous analysis that if we included 1 in the subset, that we could reach the sum of 1 (reach[1]=true), now we know that if we include 1 and 2 in the subset, we can reach the total sum of 3. Since we reached the total sum of half of the original array's sum, we can return true immediately, since this subset's sum is equal to half of the original array's sum, there must be another subset which is equal to the other half. We don't necessarily care what that other subset is comprised of, since we have found one subset sum equal to half, we know that other subset sum is equal to the other half.
 
 reach[0]=true
 reach[1]=true    // 1-1=0, set reach[1]=true, since reach[0] is true
 reach[2]=false
 reach[3]=true    // 3-2=1, set reach[3]=true, since reach[1] is true
 
 Let's assume we didn't return true immediately after analyzing the number 1 and the number 2. Instead let's assume that we haven't analyzed any numbers at all, and 3 is the first number under analysis. This is an exercise to just find the "other" subset (without 1 and 2). BEFORE analyzing the number 3, we only know that the base case is possible. We can only reach the total sum of 0 with nothing:
 
 reach[0]=true    // base case, we can reach the sum of 0 with nothing
 reach[1]=false
 reach[2]=false
 reach[3]=false
 
 When we first begin to analyze the number 3, we know that the subset sum 0 without the number 3 (i.e. the empty subset) can be reached (reach[0]=true), thus we also know that the sum 3 can be also reached with the number 3 included in this subset, since the sum 3 minus the current number under analysis 3 is 0. 3-3=0. Therefore, AFTER analysis of the number 3:
 
 reach[0]=true    // base case, we can reach the sum of 0 with nothing
 reach[1]=false
 reach[2]=false
 reach[3]=true    // 3-3=0, set reach[3]=true, since reach[0] is true
 
 Summary of Part 3: we have analyzed the two subsets [1,2] and [3] of the original array [1,2,3], and we have found that the sum of those two subsets are both equal to 3. Therefore it is true that this array [1,2,3] can be partitioned into two subsets whose sums are equal.
 
 for (auto num : nums){
 for (int i=half; i >= num; i--){
 if (reach[i-num]) {
 reach[i]=true;
 if (reach[half]) { return true; }
 
 Part 4: The following dynamic programming solution is the coalesced culmination of Part 1, Part 2, and Part 3 of this discussion:
 
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) { return false; }
        int half = sum / 2;
        if (*max_element(nums.begin(), nums.end()) > half) { return false; }
        vector<bool> reach(half+1, false);
        reach[0]=1;
        for (auto num : nums){
            for (int i=half; i >= num; i--){
                if (reach[i-num]) {
                    reach[i]=true;
                    if (reach[half]) { return true; }
                }
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum%2) { return false; }
        int half=sum/2;
        if (*max_element(nums.begin(), nums.end()) > half) { return false; }
        bitset<10001> reach{false};
        reach[0]=true;
        for (auto num : nums){
            for (int i=half; i >= num; i--){
                if (reach[i-num]){
                    reach[i]=true;
                }
            }
        }
        return reach[half];
    }
};


int main(int argc, const char * argv[]) {
    
    //vector<int> nums { 1,2,3,4,5,6,7 }; // 1+6+7=14  2+3+4+5=14
    vector<int> nums { 1,2,3,5 };
    
    Solution solution;
    cout << solution.canPartition(nums) << endl;
    
    
    return 0;
}















