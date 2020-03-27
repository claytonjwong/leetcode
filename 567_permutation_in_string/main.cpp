/*
 * 567. Permutation in String
 *
 * Q: https://leetcode.com/problems/permutation-in-string/
 * A: https://leetcode.com/problems/permutation-in-string/discuss/551220/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    bool checkInclusion(string needle, string haystack, Map m = {}) {
        int M = needle.size(),
                N = haystack.size();
        if (M > N) // if needle is larger than haystack, then its impossible to find needle in haystack ❌
            return false;
        for (auto c: needle)
            --m[c];
        for (auto i{ 0 }; i < M; ++i) {
            auto c = haystack[i];
            if (m.find(c) != m.end())
                ++m[c];
        }
        for (auto i{ M }; i <= N; ++i) {
            if (all_of(m.begin(), m.end(), [](auto& pair) { return pair.second >= 0; })) // target 🎯
                return true;
            if (i < N) { // slide window 👉
                auto pre = haystack[i - M],
                     cur = haystack[i];
                if (m.find(pre) != m.end()) --m[pre];
                if (m.find(cur) != m.end()) ++m[cur];
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
