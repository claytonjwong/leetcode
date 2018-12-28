/*
 
 624. Maximum Distance in Arrays
 
 https://leetcode.com/problems/maximum-distance-in-arrays/description/
 
 Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.
 
 Example 1:
 Input:
 [[1,2,3],
 [4,5],
 [1,2,3]]
 Output: 4
 Explanation:
 One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
 Note:
 Each given array will have at least 1 number. There will be at least two non-empty arrays.
 The total number of the integers in all the m arrays will be in the range of [2, 10000].
 The integers in the m arrays will be in the range of [-10000, 10000].
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int smallest = arrays[0][0];
        int biggest = arrays[0][arrays[0].size()-1];
        int maxDiff = 0;
        
        for (int i=1; i < arrays.size(); i++){
            
            int curr_smallest = arrays[i][0];
            int curr_biggest = arrays[i][arrays[i].size()-1];
            int curr_maxDiff = max( abs(biggest - curr_smallest), abs(curr_biggest - smallest)  );
            
            smallest = min ( smallest, curr_smallest );
            biggest = max ( biggest, curr_biggest );
            maxDiff = max( maxDiff, curr_maxDiff );
        }
        
        return maxDiff;
    }
};




int main(int argc, const char * argv[]) {

    vector<vector<int>> arrays;
    
    
    
    arrays.push_back(vector<int>{-8,-7,-7,-5,1,1,3,4});
    arrays.push_back(vector<int>{-2});
    arrays.push_back(vector<int>{-10,-10,-7,0,1,3});
    arrays.push_back(vector<int>{2});
    
    Solution solution;
    cout << solution.maxDistance(arrays) << endl;
    
    
    return 0;
}




