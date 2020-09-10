/*
 * 1580. Put Boxes Into the Warehouse II
 *
 * Q: https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/
 * A: https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/discuss/840231/Javascript-Python3-C%2B%2B-Greedy-%2B-Shrinking-Window-i-...-j
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxBoxesInWarehouse(VI& box, VI& spot, int cnt = 0) {
        sort(box.rbegin(), box.rend());
        int i = 0,
            j = int(spot.size()) - 1;
        for (auto k{ 0 }; i <= j && k < box.size(); ++k) {
            if (box[k] <= max(spot[i], spot[j])) {
                ++cnt;
                if (spot[i] < spot[j])
                    --j;
                else
                    ++i;
            }
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
