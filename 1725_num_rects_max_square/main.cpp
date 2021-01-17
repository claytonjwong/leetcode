/*
 * 1725. Number Of Rectangles That Can Form The Largest Square
 *
 * Q: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
 * A: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/discuss/1020596/Kt-Js-Py3-Cpp-Best-Max-of-Min(length-width)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int countGoodRectangles(VVI& A, int best = 0) {
        for (auto& rect: A)
            best = max(best, min(rect[0], rect[1]));
        return count_if(A.begin(), A.end(), [=](auto& rect) {
            return best <= rect[0] && best <= rect[1];
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
