/*
 * https://leetcode.com/contest/weekly-contest-165
 *
 * 1 h 30 m	8/19	0:51:10	2/4	1479/3837
 *
 * Q1: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game
 * A1: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/discuss/441746/Javascript-and-C%2B%2B-solutions
 *
 * Q2: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
 * A2: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/discuss/441752/Javascript-and-C%2B%2B-solutions
 *
 * Q3: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
 * A3: https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/442151/Javascript-and-C%2B%2B-solutions
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

/*
 * 1275. Find Winner on a Tic Tac Toe Game
 *
 * Q: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game
 * A: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/discuss/441746/Javascript-and-C%2B%2B-solutions
 */

/*

 A is X
 B is O

 keep track of amount of each per X and O:

 diag1: 0,0   1,1   2,2
 diag2: 0,2   1,1   2,0
 row0,1,2
 col0,1,2

 when either X or O become 3, then they win, return A or B

 also keep track of total # of moves, if < 9, return pending

 */

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    string tictactoe(VVI& moves, VVI board=VVI(3, VI(3,-1)), int turn=1, int total=0) { // A is 1 and B is 0
        auto isWin = [&](VI row=VI(3), VI col=VI(3), int d1=0, int d2=0) {
            for (auto i=0; i < 3; ++i) {
                for (auto j=0; j < 3; ++j) {
                    if (board[i][j] != turn)
                        continue;
                    if (++row[i] == 3 || ++col[j] == 3)
                        return true;
                    if (i == j && ++d1 == 3)
                        return true;
                    if (((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0)) && ++d2 == 3)
                        return true;
                }
            }
            return false;
        };
        for (auto move: moves) {
            auto [i,j] = tie(move[0], move[1]);
            board[i][j] = turn;
            if (isWin())
                return turn == 1 ? "A" : "B";
            turn ^= 1;
            ++total;
        }
        return total < 9 ? "Pending" : "Draw";
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{0,0},{2,0},{1,1},{2,1},{2,2}};
    auto ans = solution.tictactoe(A);
    cout << ans << endl;
    return 0;
}
*/


/*
 * 1276. Number of Burgers with No Waste of Ingredients
 *
 * Q: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
 * A: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/discuss/441752/Javascript-and-C%2B%2B-solutions
 */

/*

 naive algorithm (expected to TLE) is to make one jumbo burger at a time (ie. decrement a by 4 and decrement b by 1)
 until a == 2b

 this is expected to TLE because a <= 10^7 and b <= 10^7

 well... its actually accepted, cool!

 */

/*
class Solution {
public:
    using VI = vector<int>;
    VI numOfBurgers(int a, int b, int c=0) {
        while (a > 0 && b > 0 && a != 2 * b)
            a -= 4, --b, ++c;
        if (a == 2 * b)
            return {c,b};
        else
            return {};
    }
};

int main() {
    Solution solution;
    auto ans = solution.numOfBurgers(2, 1);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
*/


/*
 * 1277. Count Square Submatrices with All Ones
 *
 * Q: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
 * A: https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/442151/Javascript-and-C%2B%2B-solutions
 */
/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int countSquares(VVI& A, int ans=0) {
        auto [M, N] = make_tuple(A.size(), A[0].size());
        for (auto i=1; i < M; ++i)
            for (auto j=1; j < N; ++j)
                if (A[i][j] && A[i-1][j] && A[i][j-1] && A[i-1][j-1])
                    A[i][j] = 1 + min({A[i-1][j], A[i][j-1], A[i-1][j-1]});
        for (auto& row: A)
            ans += accumulate(row.begin(), row.end(), 0);
        return ans;
    }
};
*/
/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int countSquares(VVI& A, int ans=0) {
        auto [M, N] = make_tuple(A.size(), A[0].size());
        for (auto i=0; i < M; ++i)
            for (auto j=0; j < N; ans += A[i][j++])
                if (i && j && A[i][j] && A[i-1][j] && A[i][j-1] && A[i-1][j-1])
                    A[i][j] = 1 + min({A[i-1][j], A[i][j-1], A[i-1][j-1]});
        return ans;
    }
};
*/
