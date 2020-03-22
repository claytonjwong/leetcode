/*
 * 1389. Create Target Array in the Given Order
 *
 * Q: https://leetcode.com/problems/create-target-array-in-the-given-order/
 * A: https://leetcode.com/problems/create-target-array-in-the-given-order/discuss/547200/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI createTargetArray(VI& nums, VI& index, VI ans = {}) {
        for (auto i{ 0 }; i < nums.size(); ++i)
            ans.insert(ans.begin() + index[i], nums[i]);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
