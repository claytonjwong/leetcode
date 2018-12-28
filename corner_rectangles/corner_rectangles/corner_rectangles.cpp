/*
 
 750. Number Of Corner Rectangles
 
 https://leetcode.com/contest/weekly-contest-63/problems/number-of-corner-rectangles/
 
 Given a grid where each entry is only 0 or 1, find the number of corner rectangles.
 
 A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.
 
 Example 1:
 Input: grid =
 [[1, 0, 0, 1, 0],
 [0, 0, 1, 0, 1],
 [0, 0, 0, 1, 0],
 [1, 0, 1, 0, 1]]
 Output: 1
 Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].
 Example 2:
 Input: grid =
 [[1, 1, 1],
 [1, 1, 1],
 [1, 1, 1]]
 Output: 9
 Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and one 3x3 rectangle.
 Example 3:
 Input: grid =
 [[1, 1, 1, 1]]
 Output: 0
 Explanation: Rectangles must have four distinct corners.
 Note:
 The number of rows and columns of grid will each be in the range [1, 200].
 Each grid[i][j] will be either 0 or 1.
 The number of 1s in the grid will be at most 6000.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int cnt=0,m=(int)grid.size(),n=(int)grid[0].size();
        for (int i=0; i<m-1; ++i)
            for (int j=0; j<n-1; ++j)
                if (grid[i][j])
                    for (int k=i+1; k<m; ++k)
                        for (int l=j+1; l<n; ++l)
                            if (grid[i][l] && grid[k][l] && grid[k][j])
                                ++cnt;
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
