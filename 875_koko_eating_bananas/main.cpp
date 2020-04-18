/*
 * 875. Koko Eating Bananas
 *
 * Q: https://leetcode.com/problems/koko-eating-bananas/
 * A: https://leetcode.com/problems/koko-eating-bananas/discuss/584448/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int H) {
            auto k{ 1 };
            for (;;) {
                auto h{ 0 }; // (h)ours to eat all piles ⏰
                for (auto pile: piles)
                    h += ceil(pile / k);
                if (h <= H)
                    return k; // target 🎯
                ++k;
            }
        }
    };
}
namespace BinarySearch {
    class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int H) {
            auto i = 1,
                 j = int(1e9);
            while (i < j) {
                auto k = (i + j) / 2,
                     h = 0; // (h)ours to eat all piles ⏰
                for (auto pile: piles)
                    h += ceil(pile / double(k));
                if (h > H)
                    i = k + 1; // ate too slow, eat faster 👉
                else
                    j = k;     // ate too fast, eat slower 👈
            }
            return i;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
