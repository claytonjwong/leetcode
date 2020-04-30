/*
 * 1086. High Five
 *
 * Q: https://leetcode.com/problems/high-five/
 * A: https://leetcode.com/problems/high-five/discuss/603740/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = unordered_map<int, VI>;
    VVI highFive(VVI& scores, Map m = {}, VVI ans = {}) {
        for (auto& s: scores) {
            auto [i, x] = tie(s[0], s[1]);
            m[i].push_back(x);
        }
        for (auto& [i, A]: m) {
            auto len = min(5, int(A.size()));
            sort(A.rbegin(), A.rend());
            ans.push_back({ i, accumulate(A.begin(), A.begin() + len, 0) / len });
        }
        sort(ans.begin(), ans.end(), [](auto& a, auto& b) { return a[0] < b[0]; }); // sort by student id
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
