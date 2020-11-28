/*
 * 239. Sliding Window Maximum
 *
 * Q: https://leetcode.com/problems/sliding-window-maximum/
 * A: https://leetcode.com/problems/sliding-window-maximum/discuss/951922/C%2B%2B-Ordered-Map
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = map<int, int>;
        VI maxSlidingWindow(VI& A, int k, Map m = {}, VI best = {}) {
            for (auto it = A.begin(); it != A.begin() + k; ++m[*it++]);
            best.push_back(prev(m.end())->first);
            for (auto i{ k }; i < A.size(); ++i) {
                if (!--m[A[i - k]])
                    m.erase(A[i - k]);
                ++m[A[i]];
                best.push_back(prev(m.end())->first);
            }
            return best;
        }
    };
}
namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = map<int, int>;
        VI maxSlidingWindow(VI& A, int k, Map m = {}, VI best = {}) {
            for (auto it = A.begin(); it != A.begin() + k - 1; ++m[*it++]);
            for (auto i{ k - 1 }; i < A.size(); ++i) {
                ++m[A[i]];
                best.push_back(prev(m.end())->first);
                if (!--m[A[i - (k - 1)]])
                    m.erase(A[i - (k - 1)]);
            }
            return best;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
