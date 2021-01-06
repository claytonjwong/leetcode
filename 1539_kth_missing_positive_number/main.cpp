/*
 * 1539. Kth Missing Positive Number
 *
 * Q: https://leetcode.com/problems/kth-missing-positive-number/
 * A: https://leetcode.com/problems/kth-missing-positive-number/discuss/780016/Kt-Js-Py3-Cpp-Seen-Set-%2B-Concise
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

namespace Seen {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        int findKthPositive(VI& A, int K) {
            Set seen{ A.begin(), A.end() };
            for (auto i{ 1 };; ++i)
                if (seen.find(i) == seen.end() && !--K)
                    return i;
        }
    };
}
namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        int findKthPositive(VI& A, int k) {
            auto i = 0,
                 x = 0;
            while (k && i < A.size())
                if (++x == A[i])
                    ++i;
                else
                    --k;
            return x + k;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
