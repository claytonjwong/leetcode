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
    VVI combinationSum(VI& A, int target, VVI ans = {}) {
        dfs(A, target, ans);
        return ans;
    }
private:
    void dfs(VI& A, int sum, VVI& ans, int start = 0, VI&& path = {}) {
        if (sum == 0) {
            ans.push_back(path);
            return;
        }
        for (auto i = start; i < A.size(); ++i) {
            if (sum - A[i] < 0)
                continue;
            path.push_back(A[i]);
            dfs(A, sum - A[i], ans, i, move(path));
            path.pop_back();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
