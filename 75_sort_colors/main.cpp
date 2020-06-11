/*
 * 75. Sort Colors
 *
 * Q: https://leetcode.com/problems/sort-colors/
 * A: https://leetcode.com/problems/sort-colors/discuss/681992/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = map<int, int>;
    void sortColors(VI& A, Map m = {}, int i = 0) {
        for (auto x: A)
            ++m[x];
        for (auto [x, cnt]: m)
            while (cnt--)
                A[i++] = x;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
