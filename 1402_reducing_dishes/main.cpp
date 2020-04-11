/*
 * 1402. Reducing Dishes
 *
 * Q: https://leetcode.com/problems/reducing-dishes/
 * A: https://leetcode.com/problems/reducing-dishes/discuss/574182/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxSatisfaction(VI& A, int max = 0) {
        sort(A.rbegin(), A.rend());
        for (auto j{ 1 }; j <= A.size(); ++j) {
            auto next{ 0 };
            for (auto i{ 0 }, k{ j }; i < j; ++i, --k)
                next += A[i] * k;
            max = std::max(max, next);
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
