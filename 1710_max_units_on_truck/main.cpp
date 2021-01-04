/*
 * 1710. Maximum Units on a Truck
 *
 * Q: https://leetcode.com/problems/maximum-units-on-a-truck/
 * A: https://leetcode.com/problems/maximum-units-on-a-truck/discuss/999095/Kt-Js-Py3-Cpp-BEST-Greedily-TAKE-BOXES-while-we-HAVE-room
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int maximumUnits(VVI& A, int have, int best = 0) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) { return b[1] < a[1]; });
        for (auto i{ 0 }; i < A.size(); ++i) {
            auto [boxes, units] = tie(A[i][0], A[i][1]);
            auto take = min(have, boxes);
            best += take * units;
            have -= take;
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
