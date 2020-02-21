/*
 * 1349. Maximum Students Taking Exam
 *
 * Q: https://leetcode.com/problems/maximum-students-taking-exam/
 * A: https://leetcode.com/problems/maximum-students-taking-exam/discuss/516182/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*

go()
    if memo value
        return memo value
    go() -> get all valid seating arrangements for cur row based on pre row
    for each seating arrangement
        res = max(res, # students in current seating arrangement + dfs(next row))
    memo[i][pre_row]


getSeats()
    if i == N
        add seating arrangement
        return

    for (i = start; i < N; ++i)
        if i-th seat is OK
            set student
            go(i + 1)
            unset student


*/

class Solution {
public:
    using VI = vector<int>;
    using VC = vector<char>;
    using VVC = vector<VC>;
    using Memo = unordered_map<int, unordered_map<int, int>>;
    int maxStudents(VVC& A, Memo memo = {}) {
        int M = A.size(),
                N = A[0].size();
        for (auto i = 0; i < M; ++i)
            for (auto j = 0; j < 1 << N; ++j)
                memo[i][j] = -1;
        return go(A, M, N, memo);
    }
private:
    int go(VVC& A, int M, int N, Memo& memo, int i = 0, int pre = 0, VI seats = {}, int ans = 0) {
        if (i == M)
            return 0;
        if (memo[i][pre] > -1)
            return memo[i][pre];
        getSeats(seats, A, N, i, 0, pre);
        for (auto cur: seats)
            ans = max(ans, __builtin_popcount(cur) + go(A, M, N, memo, i + 1, cur));
        return memo[i][pre] = ans;
    }
    void getSeats(VI& seats, VVC& A, int N, int i, int j, int pre, int cur = 0) {
        if (j == N) {
            seats.push_back(cur);
            return;
        }
        // with current seat (if seat is not broken and cannot cheat)
        auto frontL = [&]() { return i == 0 || j == 0     || (pre & 1 << (j - 1)) == 0; };
        auto frontR = [&]() { return i == 0 || j == N - 1 || (pre & 1 << (j + 1)) == 0; };
        auto L = [&]() { return j == 0     || (cur & 1 << (j - 1)) == 0; };
        auto R = [&]() { return j == N - 1 || (cur & 1 << (j + 1)) == 0; };
        if (A[i][j] != '#' && frontL() && frontR() && L() && R()) {
            cur |= 1 << j;
            getSeats(seats, A, N, i, j + 1, pre, cur);
            cur ^= 1 << j;
        }
        // without current seat
        getSeats(seats, A, N, i, j + 1, pre, cur);
    }
};

int main() {
    Solution solution;
    Solution::VVC A{
        {'#','.','#','#','.','#'},
        {'.','#','#','#','#','.'},
        {'#','.','#','#','.','#'}
    };
    cout << solution.maxStudents(A) << endl;
    Solution::VVC B{
        {'#','.','.','.','#'},
        {'.','#','.','#','.'},
        {'.','.','#','.','.'},
        {'.','#','.','#','.'},
        {'#','.','.','.','#'}
    };
    cout << solution.maxStudents(B) << endl;
    return 0;
}
