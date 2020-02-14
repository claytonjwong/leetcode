/*
 * 1347. Minimum Number of Steps to Make Two Strings Anagram
 *
 * Q: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
 * A: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/discuss/509106/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

// class Solution {
// public:
//     using Map = unordered_map<char, int>;
//     int minSteps(string s, string t, Map m = {}, int ans = 0) {
//         for (auto c: s)
//             ++m[c];
//         for (auto c: t)
//             if (m[c]-- <= 0)
//                 ++ans;
//         return ans;
//     }
// };

class Solution {
public:
    using VI = vector<int>;
    int minSteps(string s, string t, VI A = VI(123)) {
        for (auto i = 0; i < s.size(); ++i)
            ++A[s[i]],
            --A[t[i]];
        return accumulate(A.begin(), A.end(), 0, [](auto a, auto b) { return a + abs(b); }) / 2;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
