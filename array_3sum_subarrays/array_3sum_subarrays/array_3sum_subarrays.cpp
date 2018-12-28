/*
 
 689. Maximum Sum of 3 Non-Overlapping Subarrays
 
 https://leetcode.com/contest/leetcode-weekly-contest-52/problems/maximum-sum-of-3-non-overlapping-subarrays/
 
 In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.
 
 Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.
 
 Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
 
 Example:
 Input: [1,2,1,2,6,7,5,1], 2
 Output: [0, 3, 5]
 Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
 We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
 Note:
 nums.length will be between 1 and 20000.
 nums[i] will be between 1 and 65535.
 k will be between 1 and floor(nums.length / 3).
 
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <unordered_map>

using namespace std;


class SolutionAC {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sum(nums.size() + 1);
        for (int i = 0; i < (int)nums.size(); i++)
            sum[i + 1] = sum[i] + nums[i];
        
        vector<pair<int,int>> forward(nums.size());
        forward[0] = make_pair(sum[k] - sum[0], 0);
        for (int i = 1; i <= (int)nums.size() - k; i++) {
            int t = sum[i + k] - sum[i];
            forward[i] = (forward[i - 1].first >= t) ? forward[i - 1] : make_pair(t, i);
        }
        
        vector<pair<int,int>> backward(nums.size());
        for (int i = (int)nums.size() - k; i >= 0; i--) {
            int t = sum[i + k] - sum[i];
            backward[i] = (backward[i + 1].first > t) ? backward[i + 1] : make_pair(t, i);
        }
        
        int ansSum = 0;
        vector<int> ans(3);
        for (int i = k; i <= (int)nums.size() - k * 2; i++) {
            int t = forward[i - k].first + backward[i + k].first + sum[i + k] - sum[i];
            if (ansSum < t) {
                ansSum = t;
                ans = vector<int>{ forward[i - k].second, i, backward[i + k].second };
            }
        }
        
        return ans;
    }
};


class Solution{
private:
    unordered_map<int,int> _memoSumOfOneSubarrays{};
    unordered_map<int,pair<int,int>> _memoSumOfTwoSubarrays{};
    
    vector<int> calcSubarraySums(const vector<int>& nums){
        vector<int> sums(nums.size()+1,0);
        for (int i=1; i<sums.size(); ++i){
            sums[i]=sums[i-1]+nums[i-1];
        }
        return sums;
    }
    
    int getSubarraySum(const vector<int>& sums, int start, int k){
        return sums[start+k] - sums[start];
    }
    
    int maxSumOfOneSubarrays(const vector<int>& sums, int start, int k){
        if (_memoSumOfOneSubarrays.find(start)!=_memoSumOfOneSubarrays.end()){
            return _memoSumOfOneSubarrays[start];
        }
        int maxSumOne=0,indexOfMaxSumOne=0;
        for (int indexOne=start; indexOne < sums.size()-k; ++indexOne){
            int currSumOne=getSubarraySum(sums,indexOne,k);
            if (currSumOne > maxSumOne){
                maxSumOne=currSumOne;
                indexOfMaxSumOne=indexOne;
            }
        }
        for (int i=start; i<=indexOfMaxSumOne; ++i){
            _memoSumOfOneSubarrays[i]=indexOfMaxSumOne;
        }
        return _memoSumOfOneSubarrays[start];
    }
    
    pair<int,int> maxSumOfTwoSubarrays(const vector<int>& sums, int start, int k){
        if (_memoSumOfTwoSubarrays.find(start)!=_memoSumOfTwoSubarrays.end()){
            return _memoSumOfTwoSubarrays[start];
        }
        pair<int,int> res;
        int maxSumTwo=0,indexOfMaxSumTwo=start,indexOfMaxSumOne=start+k;
        for (int indexTwo=start; indexTwo < sums.size()-2*k; ++indexTwo){
            int indexOne=maxSumOfOneSubarrays(sums, indexTwo+k, k);
            int currSumTwo=getSubarraySum(sums,indexTwo,k);
            int currSumOne=getSubarraySum(sums,indexOne,k);
            if (currSumTwo+currSumOne > maxSumTwo){
                maxSumTwo=currSumTwo+currSumOne;
                indexOfMaxSumTwo=indexTwo;
                indexOfMaxSumOne=indexOne;
            }
        }
        res.first=indexOfMaxSumTwo;
        res.second=indexOfMaxSumOne;
        for (int i=start; i<=indexOfMaxSumTwo; ++i){
            _memoSumOfTwoSubarrays[i]=res;
        }
        return _memoSumOfTwoSubarrays[start];
    }
    
    vector<int> maxSumOfThreeSubarrays(const vector<int>& sums, int start, int k){
        vector<int> res(3,0);
        int maxSumThree=0;
        int indexOfMaxSumThree=start,indexOfMaxSumTwo=start+k,indexOfMaxSumOne=start+2*k;
        for (int indexThree=start; indexThree < sums.size()-3*k; ++indexThree){
            auto indexTwoAndOne=maxSumOfTwoSubarrays(sums, indexThree+k, k);
            int indexTwo=indexTwoAndOne.first;
            int indexOne=indexTwoAndOne.second;
            int currSumThree=getSubarraySum(sums,indexThree,k);
            int currSumTwo=getSubarraySum(sums,indexTwo,k);
            int currSumOne=getSubarraySum(sums,indexOne,k);
            if (currSumThree+currSumTwo+currSumOne > maxSumThree){
                maxSumThree=currSumThree+currSumTwo+currSumOne;
                indexOfMaxSumThree=indexThree;
                indexOfMaxSumTwo=indexTwo;
                indexOfMaxSumOne=indexOne;
            }
        }
        res[0]=indexOfMaxSumThree;
        res[1]=indexOfMaxSumTwo;
        res[2]=indexOfMaxSumOne;
        return res;
    }
    
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k){
        vector<int> sums=calcSubarraySums(nums);
        return maxSumOfThreeSubarrays(sums,0,k);
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int> nums {
        0,1,2,3,4,5
    };
    int k=2;
    
    /*
     
     output: [0,3,6] or [1,3,8]
     expected: [1,4,7]
     
     */
    
    SolutionAC solutionAC;
    vector<int> resAC=solutionAC.maxSumOfThreeSubarrays(nums,k);
    
    Solution solution;
    vector<int> res=solution.maxSumOfThreeSubarrays(nums,k);
    
    return 0;
}



