/*
 * 339. Nested List Weight Sum
 *
 * Q: https://leetcode.com/problems/nested-list-weight-sum/
 * A: https://leetcode.com/problems/nested-list-weight-sum/discuss/124490/Kt-Js-Py3-Cpp-Recursive
 */

#include <iostream>
#include <vector>

using namespace std;

struct NestedInteger {
    bool isInteger();
    int getInteger();
    vector<NestedInteger> &getList();
};

class Solution {
public:
    int depthSum(vector<NestedInteger>& A, int depth = 1, int total = 0) {
        for (auto& it: A)
            if (it.isInteger())
                total += it.getInteger() * depth;
            else
                total += depthSum(it.getList(), depth + 1);
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
