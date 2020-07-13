/*
 * https://leetcode.com/contest/weekly-contest-197/ranking/146/
 * https://www.youtube.com/watch?v=-oXf4Ikou_c&t=777s
 *
 * Rank            Name            Score    Finish Time    Q1 (3)     Q2 (4)	    Q3 (5)    Q4 (7)
 * 3645 / 13984    claytonjwong    7        0:16:24        0:00:59    0:11:24 *1
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 1512. Number of Good Pairs
 *
 * Q: https://leetcode.com/problems/number-of-good-pairs/
 * A: https://leetcode.com/problems/number-of-good-pairs/discuss/731629/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        int numIdenticalPairs(VI& A, int cnt = 0) {
            auto N = A.size();
            for (auto i{ 0 }; i < N; ++i)
                for (auto j{ i + 1 }; j < N; ++j)
                    cnt += A[i] == A[j];
            return cnt;
        }
    };
}

/*
 * 1513. Number of Substrings With Only 1s
 *
 * Q: https://leetcode.com/problems/number-of-substrings-with-only-1s/
 * A: https://leetcode.com/problems/number-of-substrings-with-only-1s/discuss/731600/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using LL = long long;
        using VLL = vector<LL>;
        int numSub(string s, int len = 0, VLL run = {}, int cnt = 0) {
            auto sum = [](auto n) { return (n * (n + 1)) / 2; };
            s.push_back('0'); // sentinel value to terminate the last run (if it exists)
            for (auto c: s)
                if (c == '1') ++len; else run.push_back(len), len = 0;
            for (auto len: run)
                cnt = (cnt + sum(len)) % LL(1e9 + 7);
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
