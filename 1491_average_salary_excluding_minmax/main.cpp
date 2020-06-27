/*
 * 1491. Average Salary Excluding the Minimum and Maximum Salary
 *
 * Q: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
 * A: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/discuss/708064/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    double average(VI& A) {
        sort(A.begin(), A.end());
        return accumulate(A.begin() + 1, A.end() - 1, 0.0) / (A.size() - 2);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
