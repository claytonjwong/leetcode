/*
 * 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
 *
 * Q: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * A: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/discuss/970252/Kt-Js-Py3-Cpp-1-Liners
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int minPartitions(string s) {
        return *max_element(s.begin(), s.end()) - '0';
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
