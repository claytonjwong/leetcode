/*
 * 1371. Find the Longest Substring Containing Vowels in Even Counts
 *
 * Q: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 * A: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/discuss/578155/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>; // value -> first index
        int findTheLongestSubstring(string S, string V = "aeiou", int max = 0) {
            auto encode = [&](auto c) { return 1 << V.find(c); };
            int N = S.size();
            VI A(N + 1);
            Map seen{{0, 0}};
            for (auto i{ 1 }; i <= N; ++i) {
                if (V.find(S[i - 1]) == string::npos) // A[i] is not a vowel
                    A[i] = A[i - 1];
                else                                     // A[i] is a vowel
                    A[i] = A[i - 1] ^ encode(S[i - 1]);
                if (seen.find(A[i]) != seen.end())
                    max = std::max(max, i - seen[A[i]]); // 🎯 max of i-th index minus first seen A[i] index
                else
                    seen[A[i]] = i; // 👀 first seen A[i] index
            }
            return max;
        }
    };
}

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>; // value -> first index
        int findTheLongestSubstring(string S, string V = "aeiou", int max = 0) {
            auto encode = [&](auto c) {
                auto i = V.find(c);
                return i == string::npos ? 0 : 1 << i;
            };
            int N = S.size();
            VI A(N + 1);
            Map seen{{0, 0}};
            for (auto i{ 1 }; i <= N; ++i) {
                A[i] = A[i - 1] ^ encode(S[i - 1]);
                auto first = seen.find(A[i]) != seen.end() ? seen[A[i]] : i;
                if (first == i)
                    seen[A[i]] = i; // 👀 first seen A[i] index
                max = std::max(max, i - first); // 🎯 max of i-th index minus first seen A[i] index
            }
            return max;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
