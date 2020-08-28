/*
 * 1564. Put Boxes Into the Warehouse I
 *
 * Q: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/
 * A: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/discuss/817303/Javascript-Python3-C%2B%2B-Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxBoxesInWarehouse(VI& box, VI& spot, int cnt = 0) {
        // 1. preprocess the boxes and spots
        sort(box.rbegin(), box.rend());
        for (auto j{ 1 }; j < spot.size(); ++j)
            spot[j] = min(spot[j], spot[j - 1]);
        // 2. greedily place i-th box into j-th spot (if it fits) from 👈 right-to-left
        auto i = int(box.size()) - 1,
                j = int(spot.size()) - 1;
        while (0 <= i && 0 <= j) {
            if (box[i] <= spot[j])  // ✅ i-th min box fits in j-th min spot
                --i, --j, ++cnt;
            else                    // 🚫 try next monotonically non-decreasing j-th min spot
                --j;
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
