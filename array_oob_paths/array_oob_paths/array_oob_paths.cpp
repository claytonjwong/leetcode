/*
 
 576. Out of Boundary Paths
 
 https://leetcode.com/problems/out-of-boundary-paths/description/
 
 There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
 
 Example 1:
 Input:m = 2, n = 2, N = 2, i = 0, j = 0
 Output: 6
 Explanation:
 
 Example 2:
 Input:m = 1, n = 3, N = 3, i = 0, j = 1
 Output: 12
 Explanation:
 
 Note:
 Once you move the ball out of boundary, you cannot move it back.
 The length and height of the grid is in range [1,50].
 N is in range [0,50].
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const static int _MOD=1000000007;
    const static int _SIZE=51;
    int memo[_SIZE][_SIZE][_SIZE];

    void memoInit(){
        for (int N=0; N<_SIZE; ++N){
            for (int i=0; i<_SIZE; ++i){
                for (int j=0; j<_SIZE; ++j){
                    memo[N][i][j]=-1;
                }
            }
        }
    }

    int memoPaths(int m, int n, int N, int i, int j) {
        if (!(0<=i&&i<m && 0<=j&&j<n)) return 1;
        if (N==0) return 0;
        if (memo[N][i][j]!=-1){
            return memo[N][i][j];
        }
        int paths=(memoPaths(m,n,N-1,i-1,j)%_MOD + memoPaths(m,n,N-1,i,j+1)%_MOD)%_MOD
                 +(memoPaths(m,n,N-1,i+1,j)%_MOD + memoPaths(m,n,N-1,i,j-1)%_MOD)%_MOD;
        return memo[N][i][j]=paths%_MOD;
    }
    
public:
    int findPaths(int m, int n, int N, int i, int j) {
        memoInit();
        return memoPaths(m,n,N,i,j);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    cout << solution.findPaths(8,50,23,5,26) << endl;
    
    
    
    return 0;
}





