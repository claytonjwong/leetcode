/*
 * 1652. Defuse the Bomb
 *
 * Q: https://leetcode.com/problems/defuse-the-bomb/
 * A: https://leetcode.com/problems/defuse-the-bomb/discuss/935371/Kt-Js-Py3-Cpp-One-Step-at-a-Time
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI decrypt(VI& A, int K, VI ans = {}) {
        auto N = A.size();
        if (!K)
            return VI(N);
        if (K < 0) {
            reverse(A.begin(), A.end());
            ans = decrypt(A, -K);
            return { ans.rbegin(), ans.rend() };
        }
        auto step = [=](auto i) { return i + 1 < N ? i + 1 : 0; };
        for (auto i{ 0 }; i < N; ++i) {
            auto steps = K,
                 total = 0,
                 j = step(i);
            while (steps--) total += A[j], j = step(j);
            ans.push_back(total);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
