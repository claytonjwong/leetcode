/*
 * 475. Heaters
 *
 * Q: https://leetcode.com/problems/heaters/
 * A: https://leetcode.com/problems/heaters/discuss/595623/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findRadius(VI& home, VI& heat, int max = 0) {
        sort(home.begin(), home.end());
        sort(heat.begin(), heat.end());
        int M = home.size(),
                N = heat.size();
        auto i = 0,
                L = 0,
                R = 1;
        for (auto i{ 0 }; i < M;) {
            auto min = int(1e9 + 7);
            if (home[i] <= heat[L]) {     // case 1: 🏠i <-- 🔥L
                min = heat[L] - home[i];
            } else if (R < N) {
                if (home[i] <= heat[R]) { // case 2: 🔥L --> 🏠i <-- 🔥R
                    min = std::min(
                            home[i] - heat[L],
                            heat[R] - home[i]
                    );
                } else {                  // case 3: 🔥L 🔥R --> 🏠i
                    ++L, ++R; continue;
                }
            } else {                      // case 4: 🔥L --> 🏠i  (R == N, so there is no 🔥R)
                min = home[i] - heat[L];
            }
            max = std::max(max, min);
            ++i;
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
