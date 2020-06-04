/*
 * 832. Flipping an Image
 *
 * Q: https://leetcode.com/problems/flipping-an-image/
 * A: https://leetcode.com/problems/flipping-an-image/discuss/131721/4-liner-C%2B%2B-reverse()-and-transform()
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI flipAndInvertImage(VVI& A) {
        for (auto& row: A) {
            reverse(row.begin(), row.end());
            transform(row.begin(), row.end(), row.begin(), [](auto x) { return x ^ 1; });
        }
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
