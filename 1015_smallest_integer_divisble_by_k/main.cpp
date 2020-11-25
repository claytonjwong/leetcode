/*
 * 1015. Smallest Integer Divisible by K
 *
 * Q: https://leetcode.com/problems/smallest-integer-divisible-by-k/
 * A: https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/261255/Kt-Js-Py3-Cpp-Mod-K
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<int>;
    int smallestRepunitDivByK(int K, int N = 1, Set seen = {}) {
        for (auto i{ 1 };; ++i) {
            auto mod = N % K;
            if (!mod)
                return i;
            if (!seen.insert(mod).second)
                break;
            N = (10 * N + 1) % K;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
