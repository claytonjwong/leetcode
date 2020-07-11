/*
 * 78. Subsets
 *
 * Q: https://leetcode.com/problems/subsets/
 * A: https://leetcode.com/problems/subsets/discuss/731155/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    using VI = vector<int>;
    using VVI = vector<VI>;
    int N;
    VI A;
    VVI ans;
    void go(int i = 0, VI&& path = {}) {
        if (i == N) {
            ans.push_back(path); // 🛑 base case: add the unique path onto the answer
            return;
        }
        path.push_back(A[i]);
        go(i + 1, move(path)); // ✅ with A[i]
        path.pop_back();
        go(i + 1, move(path)); // 🚫 without A[i]
    }
public:
    VVI subsets(VI& A_) {
        A = A_;
        N = A.size();
        go();
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
