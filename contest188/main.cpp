/*
 * https://leetcode.com/contest/weekly-contest-188/
 *
 * Rank           Name           Score   Finish Time    Q1 (3)       Q2 (4)    Q3 (5)   Q4 (7)
 * 4552 / 12714   claytonjwong   7       0:44:17        0:05:09 *1   0:39:17
 */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

/*
 * 1441. Build an Array With Stack Operations
 *
 * Q: https://leetcode.com/problems/build-an-array-with-stack-operations/
 * A: https://leetcode.com/problems/build-an-array-with-stack-operations/discuss/624724/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VS = vector<string>;
        using VI = vector<int>;
        VS buildArray(VI& A, int N, VS ans = {}) {
            for (auto i{ 0 }, j{ 1 }; i < A.size(); ++j)
                if (A[i] == j)
                    ans.emplace_back("Push"), ++i; // remaining element ✅
                else
                    ans.emplace_back("Push"),      // missing element ❌
                    ans.emplace_back("Pop");
            return ans;
        }
    };
}

/*
 * 1442. Count Triplets That Can Form Two Arrays of Equal XOR
 *
 * Q: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
 * A: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623806/Javascript-and-C%2B%2B-solutions
 */
class Solution {
public:
    using VI = vector<int>;
    int countTriplets(VI& A, int cnt = 0) {
        int N = A.size();
        VI XOR(N + 1);
        for (auto i{ 1 }; i <= N; ++i)
            XOR[i] = XOR[i - 1] ^ A[i - 1];
        for (auto i{ 0 }; i < N; ++i) {
            for (auto j{ i + 1 }; j < N; ++j) {
                auto cur{ 0 };
                for (auto k{ j }; k < N; ++k) {
                    cur ^= A[k];
                    if ((XOR[i] ^ XOR[j]) == cur) // target 🎯
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
