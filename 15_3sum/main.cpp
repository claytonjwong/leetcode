/*
 * 15. 3Sum
 *
 * Q: https://leetcode.com/problems/3sum/
 * A: https://leetcode.com/problems/3sum/discuss/725733/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI threeSum(VI& A, VVI ans = {}) {
        sort(A.begin(), A.end());
        int N = A.size(),
            i = 0;
        while (i + 2 < N) {
            auto j = i + 1,
                 k = N - 1;
            while (j < k) { // ⭐️ 2sum window [ j ... k ]
                auto sum = A[i] + A[j] + A[k];
                if (sum == 0) ans.push_back({ A[i], A[j], A[k] }); // 🎯 3sum target
                if (sum <= 0) do { ++j; } while (A[j] == A[j - 1] && j < k); // shrink 2sum window: [ j 👉 ... k ] 🚫 skip duplicate j
                if (0 <= sum) do { --k; } while (A[k] == A[k + 1] && j < k); // shrink 2sum window: [ j ... 👈 k ] 🚫 skip duplicate k
            }
            do { ++i; } while (A[i - 1] == A[i] && i + 2 < N); // 🚫 skip duplicate i
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
