/*
 * 459. Repeated Substring Pattern
 *
 * Q: https://leetcode.com/problems/repeated-substring-pattern/
 * A: https://leetcode.com/problems/repeated-substring-pattern/discuss/826659/Javascript-Python3-C%2B%2B-Recursive-%2B-.-Iterative
 */

#include <iostream>

using namespace std;

namespace Recursive {
    class Solution {
    public:
        static constexpr auto INF = int(1e9 + 7);
        bool repeatedSubstringPattern(string S, int k = INF) {
            k = k != INF ? k : S.size() / 2;
            return !k ? false : (!(S.size() % k) && all_of(S.begin(), S.end(), [i = -1, k, &S](auto _) mutable { return S.size() <= ++i + k || S[i] == S[i + k]; })) || repeatedSubstringPattern(S, k - 1);
        }
    };
}

namespace Iterative {
    class Solution {
    public:
        bool repeatedSubstringPattern(string S) {
            int N = S.size();
            for (auto k{ 1 }; k <= N / 2; ++k) {
                if (N % k)
                    continue;                          // 🚫 candidate pattern of length k must evenly divide N
                auto i = 0;
                while (i + k < N && S[i] == S[i + k])  // 🚌 explore candidate pattern of length k
                    ++i;
                if (i + k == N)
                    return true;                       // 🎯 match found for candidate pattern of length k
            }
            return false;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
