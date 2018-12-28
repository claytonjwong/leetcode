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
        if (K==0) return 1.0;
        double p=0.0;
        for (auto& move : getMoves(N,r,c)){
            int nextMove=K-1, nextRow=move[0], nextCol=move[1];
            p+=_memo[nextMove][nextRow][nextCol] ?
               _memo[nextMove][nextRow][nextCol] : knightProbability(N, nextMove, nextRow, nextCol);
        }
        return _memo[K][r][c]=p/8.0;
    }
    
private:
    double _memo[100][25][25] = {0.0}; // [K][r][c]
    
    bool isValidMove(const int& N, const int& r, const int& c){
        return 0<=r&&r<N && 0<=c&&c<N ? true : false;
    }
    
    vector<vector<int>> getMoves(const int& N, const int& r, const int& c){
        vector<vector<int>> validMoves{}, allMoves{
                     {r-2,c-1} , {r-2,c+1},
            
            {r-1,c-2},                    {r-1,c+2},
                           /* r,c */
            {r+1,c-2},                    {r+1,c+2},
            
                     {r+2,c-1} , {r+2,c+1},
        };
        for (auto& move : allMoves)
            if (isValidMove(N,move[0],move[1]))
                validMoves.push_back(move);
        return validMoves;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    double res=solution.knightProbability(3, 2, 0, 0);
    
    return 0;
}
