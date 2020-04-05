/*
 * 1405. Longest Happy String
 *
 * Q: https://leetcode.com/problems/longest-happy-string/
 * A: https://leetcode.com/problems/longest-happy-string/discuss/565380/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    using VP = vector<pair<char, int>>;
    string longestDiverseString(int a, int b, int c, bool found = false, string ans = {}) {
        Map m{{'a', a}, {'b', b}, {'c', c}};
        do {
            found = false;
            VP A{m.begin(), m.end()};
            sort(A.begin(), A.end(), [](auto& a, auto& b) { return a.second > b.second; });
            auto N = ans.size();
            for (auto i{ 0 }; i < 3; ++i) {
                auto [cur, cnt] = A[i];
                if (cnt > 0 && (N < 2 || ans[N - 2] != cur || ans[N - 1] != cur)) {
                    ans.push_back(cur);
                    --m[cur];
                    found = true;
                    break;
                }
            }
        } while (found);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
