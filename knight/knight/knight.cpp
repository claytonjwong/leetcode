/*
 
 688. Knight Probability in Chessboard
 
 https://leetcode.com/contest/leetcode-weekly-contest-52/problems/knight-probability-in-chessboard/
 
 On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
 
 A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
 
 
 Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
 
 The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.
 
 Example:
 Input: 3, 2, 0, 0
 Output: 0.0625
 Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
 From each of those positions, there are also two moves that will keep the knight on the board.
 The total probability the knight stays on the board is 0.0625.
 Note:
 N will be between 1 and 25.
 K will be between 0 and 100.
 The knight always initially starts on the board.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     double knightProbability(int N, int K, int r, int c) {
         double p=0.0;
         vector<vector<int>> moves {
             {r-2,c-1},{r-2,c+1},{r-1,c-2},{r-1,c+2},
             {r+1,c-2},{r+1,c+2},{r+2,c-1},{r+2,c+1},
         };
         if (!K)
             return _memo[K][r][c]=1.0;
         for (auto& move : moves){
             int nextK=K-1,nextR=move[0],nextC=move[1];
                if (0<=nextR&&nextR<N && 0<=nextC&&nextC<N){
                    p+= _memo[nextK][nextR][nextC] ? _memo[nextK][nextR][nextC]
                    : knightProbability(N, nextK, nextR, nextC);
             }
         }
         return _memo[K][r][c]=p/8.0; // probability for K,r,c ( count of valid moves / 8 )
     }
 private:
     double _memo[100][25][25]={0.0};
 };


#include <iostream>

int main(int argc, const char * argv[]) {
    
    int N=3, K=2, r=0, c=0;
    Solution solution;
    double res=solution.knightProbability(N, K, r, c);
    cout << res << endl;
    
    
    return 0;
}













