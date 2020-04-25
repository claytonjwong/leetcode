/*
 * 541. Reverse String II
 *
 * Q: https://leetcode.com/problems/reverse-string-ii/
 * A: https://leetcode.com/problems/reverse-string-ii/discuss/596912/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        string reverseStr(string S, int K, string ans = {}) {
            int N = S.size();
            for (auto i{ 0 }; i < N; i += 2 * K) {
                auto j = min(i + K, N);
                auto rev = S.substr(i, j - i);
                ans.append(string{ rev.rbegin(), rev.rend() });
                while (j < N && j < i + 2 * K)
                    ans.push_back(S[j++]);
            }
            return ans;
        }
    };
}
namespace Concise {
    class Solution {
    public:
        string reverseStr(string S, int K) {
            int N = S.size();
            for (auto i{ 0 }; i < N; i += 2 * K) {
                auto L = i, R = min(i + K, N) - 1; // -1 for L..R inclusive
                while (L < R)
                    swap(S[L++], S[R--]);
            }
            return S;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
