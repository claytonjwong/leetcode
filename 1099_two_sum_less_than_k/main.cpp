/*
 * 1099. Two Sum Less Than K
 *
 * Q: https://leetcode.com/problems/two-sum-less-than-k/
 * A: https://leetcode.com/problems/two-sum-less-than-k/discuss/603797/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = set<int>;
    int twoSumLessThanK(VI& A, int K, Set seen = {}, int max = -1) {
        for (auto x: A) {
            auto T = K - x;
            auto it = seen.lower_bound(T);
            if (it != seen.begin())
                max = std::max(max, x + *--it);
            seen.insert(x);
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
