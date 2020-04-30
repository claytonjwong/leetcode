/*
 * 1085. Sum of Digits in the Minimum Number
 *
 * Q: https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/
 * A: https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/discuss/603712/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int sumOfDigits(VI& A) {
        return sum(*min_element(A.begin(), A.end())) % 2 == 0;
    }
private:
    int sum(int x) {
        return x ? x % 10 + sum(x / 10) : 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
