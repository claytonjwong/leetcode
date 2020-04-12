/*
 * 1023. Camelcase Matching
 *
 * Q: https://leetcode.com/problems/camelcase-matching/
 * A: https://leetcode.com/problems/camelcase-matching/discuss/574743/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     using VB = vector<bool>;
//     using VS = vector<string>;
//     VB camelMatch(VS& queries, string pattern, VB ans = {}) {
//         auto isUpper = [](auto c) { return c <= 90; }; // 90 == 'Z'
//         auto up = [&](auto& word) {
//             string U; copy_if(word.begin(), word.end(), back_inserter(U), [&](auto c) {
//                 return isUpper(c);
//             });
//             sort(U.begin(), U.end());
//             return U;
//         };
//         auto target = up(pattern); // 🎯
//         for (auto& query: queries) {
//             if (query.size() < pattern.size() || up(query) != up(target)) {
//                 ans.push_back(false);
//                 continue;
//             }
//             auto j{ 0 };
//             for (auto i{ 0 }; i < query.size() && j < pattern.size(); ++i)
//                 if (query[i] == pattern[j])
//                     ++j;
//             ans.push_back(j == pattern.size());
//         }
//         return ans;
//     }
// };

class Solution {
public:
    using VB = vector<bool>;
    using VS = vector<string>;
    VB camelMatch(VS& queries, string pattern, VB ans = {}) {
        auto ok = [&](auto& query, int j = 0) {
            for (auto i{ 0 }; i < query.size(); ++i)
                if (j < pattern.size() && query[i] == pattern[j])
                    ++j;
                else if (query[i] <= 'Z') // uppercase mis-match ❌
                    return false;
            return j == pattern.size();
        };
        for (auto& q: queries)
            ans.push_back(ok(q));
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
