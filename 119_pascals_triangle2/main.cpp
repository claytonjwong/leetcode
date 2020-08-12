/*
 * 119. Pascal's Triangle II
 *
 * Q: https://leetcode.com/problems/pascals-triangle-ii/
 * A: https://leetcode.com/problems/pascals-triangle-ii/discuss/787820/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI getRow(int k) {
        VI cur{ 1 };
        while (k--) {
            VI pre{ cur };
            for (auto i{ 1 }; i < pre.size(); ++i)
                cur[i] = pre[i - 1] + pre[i];
            cur.push_back(1);
        }
        return cur;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
