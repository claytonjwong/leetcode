/*
 * 131. Palindrome Partitioning
 *
 * Q: https://leetcode.com/problems/palindrome-partitioning/
 * A: https://leetcode.com/problems/palindrome-partitioning/discuss/972094/Kt-Js-Py3-Cpp-DFS-%2B-BT
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using fun = function<void(int, VS&&)>;
    VVS partition(string s, VVS paths = {}) {
        auto N = s.size();
        auto ok = [](auto& word) { return word == string{ word.rbegin(), word.rend() }; };
        fun go = [&](auto i, auto&& path) {
            if (i == N) {
                paths.emplace_back(path);
                return;
            }
            string cand;
            while (i < N) {
                cand.push_back(s[i]);
                if (ok(cand)) {
                    path.emplace_back(cand);
                    go(i + 1, move(path));
                    path.pop_back();
                }
                ++i;
            }
        };
        go(0, {});
        return paths;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
