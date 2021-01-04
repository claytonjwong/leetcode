/*
 * 1711. Count Good Meals
 *
 * Q: https://leetcode.com/problems/count-good-meals/
 * A: https://leetcode.com/problems/count-good-meals/discuss/1001864/Kt-Js-Py3-Cpp-Map-%2B-Brute-Force-Search
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using LL = long long;
    using VLL = vector<LL>;
    using Map = unordered_map<LL, LL>;
    int countPairs(VI& A, Map m = {}, LL mod = 1e9 + 7, LL cnt = 0) {
        for (LL x: A) {
            for (LL t{ 1 }; t <= 100 * 1e9; t <<= 1) {
                LL y = t - x;
                if (0 <= y && m.find(y) != m.end())
                    cnt = (cnt + m[y]) % mod;
            }
            ++m[x];
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
