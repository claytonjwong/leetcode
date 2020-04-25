/*
 * 492. Construct the Rectangle
 *
 * Q: https://leetcode.com/problems/construct-the-rectangle/
 * A: https://leetcode.com/problems/construct-the-rectangle/discuss/595689/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI constructRectangle(int area) {
        int W = sqrt(area);
        while (area % W)
            --W;
        return { area / W, W };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
