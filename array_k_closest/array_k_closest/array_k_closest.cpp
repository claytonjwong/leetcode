/*
 
 658. Find K Closest Elements
 
 https://leetcode.com/contest/leetcode-weekly-contest-45/problems/find-k-closest-elements/
 
 Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
 
 Example 1:
 Input: [1,2,3,4,5], k=4, x=3
 Output: [1,2,3,4]
 Example 2:
 Input: [1,2,3,4,5], k=4, x=-1
 Output: [1,2,3,4]
 Note:
 The value k is positive and will always be smaller than the length of the sorted array.
 Length of the given array is positive and will not exceed 104
 Absolute value of elements in the array and x will not exceed 104
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        
        //
        // find index closest to X, and iterate k times
        // to find and append closest left/right onto the result
        //
        // if left is choosen as the closest element to x,
        // then move left to the left by 1
        //
        // if right is choosen as the closest element to x,
        // then move right to the right by 1
        //
        int index = indexOfElementClosestToX(arr, x);
        
        int left = index-1;
        int right = index;
        while ( k > 0){
            
            // only option is right
            if (left < 0){
                result.push_back(arr[right++]);
            }
            // only option is left
            else if (right >= arr.size()){
                result.push_back(arr[left--]);
            }
            // both left and right exist, take the left/right closest to X,
            // prioritize left if both left/right are an equal distance from x
            else if (abs(x-arr[left]) <= abs(x-arr[right])){
                result.push_back(arr[left--]);
            } else {
                result.push_back(arr[right++]);
            }
            
            k--;
        }

        sort(result.begin(), result.end());
        return result;
    }
    
    //
    // use binary search to find the index of the closest element to X
    //
    int indexOfElementClosestToX(vector<int>& arr, int x){
        
        int beg = 0;
        int end = (int)arr.size();
        
        int i=0;
        while ( beg < end ){
            
            i = (int)(beg + end) / 2;
            
            if (x == arr[i]){
                return i;
            }
            else if ( x < arr[i]){
                end = i-1;
            }
            else if (x > arr[i]){
                beg = i+1;
            }
        }
        
        return i;
    }
};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    int x = 7;
    int k = 3;
    vector<int> test {0,2,4,6,8};
    vector<int> result = solution.findClosestElements(test, k, x);
    
    for (auto el : result){
        cout << el << endl;
    }
        
    
    
    return 0;
}
