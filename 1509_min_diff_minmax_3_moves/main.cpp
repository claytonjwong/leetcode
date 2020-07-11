/*
 * 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
 *
 * Q: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
 * A: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/730531/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using LL = long long;
    using Deque = deque<LL>;
    int minDifference(VI& nums, LL min = numeric_limits<LL>::max()) {
        Deque A{ nums.begin(), nums.end() };
        auto minDiff = [&](auto i, auto j) {
            if (j < i)
                return 0LL;
            return *max_element(i, j) - *min_element(i, j);
        };
        sort(A.begin(), A.end());
        for (auto i{ 0 }; i < 3; ++i) {
            min = std::min({ min, minDiff(A.begin(), A.begin() + (A.size() - 3)), minDiff(A.begin() + 3, A.end()) });
            A.push_front(A.back()), A.pop_back();
        }
        return min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
