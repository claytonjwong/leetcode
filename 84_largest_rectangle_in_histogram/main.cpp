/*
 * 84. Largest Rectangle in Histogram
 *
 * Q: https://leetcode.com/problems/largest-rectangle-in-histogram/
 * A: https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/724329/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int largestRectangleArea(VI& A, VI s = {}, int max = 0) { // 🤔 s == monotonically non-decreasing queue
        int N = A.size(),
            i = 0;
        auto updateMaxArea = [&]() {
            auto h = A[s.back()]; s.pop_back();
            auto w = i - (s.empty() ? 0 : 1 + s.back());
            max = std::max(max, h * w); // 🎯 maximum area
        };
        while (i < N) {
            while (s.size() && A[i] < A[s.back()]) // 🛑 exit condition: A[i] >= s.back() for monotonically non-decreasing queue invariant
                updateMaxArea(); // ⭐️ pop back from stack & update max
            s.push_back(i++);
        }
        while (s.size())
            updateMaxArea(); // ⭐️ pop back from stack & update max
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
