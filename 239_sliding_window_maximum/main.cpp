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

class Solution {
public:
    using VI = vector<int>;
    using Map = map<int, int>;
    VI maxSlidingWindow(VI& A, int k, Map m = {}, VI best = {}) {
        for (auto i{ 0 }; i < A.size(); ++i) {
            ++m[A[i]];
            if (i < k - 1)                         // ✅ first fill window with k elements, for i in 0..k-1 inclusive (ie. k total)
                continue;
            best.push_back(prev(m.end())->first);  // 🎯 the maximumal value is the last value of the 🗺 ordered map
            if (!--m[A[i - (k - 1)]])
                m.erase(A[i - (k - 1)]);           // 🚫 delete last element which "fell" off the left-hand-side of the window of size k if it's frequency within the updated window is 0
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
