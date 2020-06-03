/*
 * 39. Combination Sum
 *
 * Q: https://leetcode.com/problems/combination-sum/
 * A: https://leetcode.com/problems/combination-sum/discuss/506331/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI combinationSum(VI& A, int T, VVI ans = {}) {
        go(ans, A, T);
        return ans;
    }
private:
    void go(VVI& ans, VI& A, int sum, int start = 0, VI&& path = {}) {
        if (!sum) {
            ans.push_back(path);
            return;
        }
        for (auto i{ start }; i < A.size(); ++i)
            if (0 <= sum - A[i])
                path.push_back(A[i]),
                go(ans, A, sum - A[i], i, move(path)),
                path.pop_back();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
