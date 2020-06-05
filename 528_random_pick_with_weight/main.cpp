/*
 * 528. Random Pick with Weight
 *
 * Q: https://leetcode.com/problems/random-pick-with-weight/
 * A: https://leetcode.com/problems/random-pick-with-weight/discuss/671868/Missing-Consideration
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Naive {
    class Solution {
        using VI = vector<int>;
        VI A;
    public:
        Solution(VI& weights, VI all = {}) {
            for_each(weights.begin(), weights.end(), [i = -1, &all](auto w) mutable {
                fill_n(back_inserter(all), w, ++i);
            });
            A = all;
        }
        int pickIndex() {
            return A[rand() % A.size()];
        }
    };
}

namespace PrefixSumsLinearSearch {
    class Solution {
        using VI = vector<int>;
        VI A;
    public:
        Solution(VI& weights) {
            for (auto w: weights)
                A.push_back(w + (!A.empty() ? A.back() : 0)); // prefix sums
        }
        int pickIndex() {
            auto t = rand() % A.back();
            for (auto i{ 0 }; i < A.size(); ++i)
                if (t < A[i])
                    return i;
            return A.back();
        }
    };
}

namespace PrefixSumsBinarySearch {
    class Solution {
        using VI = vector<int>;
        VI A;
    public:
        Solution(VI& weights) {
            for (auto w: weights)
                A.push_back(w + (!A.empty() ? A.back() : 0)); // prefix sums
        }
        int pickIndex() {
            auto t = rand() % A.back();
            int N = A.size(),
                i = 0,
                j = N - 1;
            while (i < j) {
                auto k = (i + j) / 2;
                if (A[k] <= t)
                    i = k + 1;
                else
                    j = k;
            }
            return i;
        }
    };
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
