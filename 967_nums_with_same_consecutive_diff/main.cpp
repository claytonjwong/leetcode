/*
 * 967. Numbers With Same Consecutive Differences
 *
 * Q: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
 * A: https://leetcode.com/problems/numbers-with-same-consecutive-differences/discuss/211594/Javascript-Python3-C%2B%2B-DFS-%2B-BT
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<void(VI&)>;
    VI numsSameConsecDiff(int N, int K, VI path = {}, VVI paths = {}, VI ans = {}) {
        fun go = [&](VI& path) {
            if (path.size() == N) {
                paths.push_back(path);
                return;
            }
            for (auto i{ 0 }; i < 10; ++i)
                if (!path.size() || i == path.back() + K || i == path.back() - K)
                    path.push_back(i),
                            go(path),
                            path.pop_back();
        };
        go(path);
        if (1 < N)
            paths.erase(remove_if(paths.begin(), paths.end(), [](auto& path) { return !path[0]; }), paths.end());
        transform(paths.begin(), paths.end(), back_inserter(ans), [](auto& path) {
            int x = 0,
                    n = path.size();
            for (auto i{ 0 }; i < path.size(); ++i)
                x += (path[i] * pow(10, n - i - 1));
            return x;
        });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
