/*
 * 794. Valid Tic-Tac-Toe State
 *
 * Q: https://leetcode.com/problems/valid-tic-tac-toe-state/
 * A: https://leetcode.com/problems/valid-tic-tac-toe-state/discuss/117603/Javascript-Python3-C%2B%2B-Concise-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    bool validTicTacToe(VS& A, string S = {}) {
        for (auto& row: A)
            S.append(row);
        int X = count_if(S.begin(), S.end(), [](auto c) { return c == 'X'; }),
            O = count_if(S.begin(), S.end(), [](auto c) { return c == 'O'; });
        auto win = [&](auto c) {
            auto target = string(3, c);
            if (any_of(A.begin(), A.end(), [&](auto& row) { return row == target; }))
                return true;
            for (auto j{ 0 }; j < 3; ++j) {
                stringstream col; col << A[0][j] << A[1][j] << A[2][j];
                if (col.str() == target)
                    return true;
            }
            stringstream diag1; diag1 << A[0][0] << A[1][1] << A[2][2];
            stringstream diag2; diag2 << A[0][2] << A[1][1] << A[2][0];
            return diag1.str() == target || diag2.str() == target;
        };
        auto winX = win('X'),
             winO = win('O');
        if (winX && winO)       return false;  // case 1: if X won and O won
        if (winX && X - O != 1) return false;  // case 2: if X won, then there must be one more X than O
        if (winO && X - O != 0) return false;  // case 3: if O won, then there must be the same amount of X and O
        return X - O == 0 || X - O == 1;       // case 4: if no winner, then there must be the same amount of X and O xor one more X than O
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
