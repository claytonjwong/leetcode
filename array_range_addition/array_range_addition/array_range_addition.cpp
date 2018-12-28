/*
 
 370. Range Addition
 
 https://leetcode.com/problems/range-addition/description/
 
 Assume you have an array of length n initialized with all 0's and are given k update operations.
 
 Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
 
 Return the modified array after all k operations were executed.
 
 Example:
 
 Given:
 
 length = 5,
 updates = [
 [1,  3,  2],
 [2,  4,  3],
 [0,  2, -2]
 ]
 
 Output:
 
 [-2, 0, 3, 5, 3]
 Explanation:
 
 Initial state:
 [ 0, 0, 0, 0, 0 ]
 
 After applying operation [1, 3, 2]:
 [ 0, 2, 2, 2, 0 ]
 
 After applying operation [2, 4, 3]:
 [ 0, 2, 5, 5, 3 ]
 
 After applying operation [0, 2, -2]:
 [-2, 0, 3, 5, 3 ]
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates){
        vector<int> res = vector<int>(length);
        
        for (auto update : updates){
            int i = update[0];
            int j = update[1];
            int val = update[2];
            
            while (i<=j){ res[i++] += val; }
        }
        
        return res;
    }
};

// 0  1  2
// 0  0  0
// 0  0  1


int main(int argc, const char * argv[]) {

    vector<vector<int>> updates {
        {1,  3,  2},
        {2,  4,  3},
        {0,  2, -2}
    };
    
    Solution solution;
    vector<int> result = solution.getModifiedArray(5, updates);
    
    for ( auto el : result ){
        cout << el << ", ";
    }
    cout << endl;
    
    
    return 0;
}




