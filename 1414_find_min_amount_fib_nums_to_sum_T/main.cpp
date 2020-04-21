/*
 * 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 *
 * Q: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
 * A: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/589359/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findMinFibonacciNumbers(int T, VI A = VI{0, 1}, int cnt = 0) {
        while (A[A.size() - 2] + A[A.size() - 1] <= T)
            A.push_back(A[A.size() - 2] + A[A.size() - 1]);
        for (int i = A.size() - 1; i > 0 && T > 0; --i)
            if (T >= A[i])
                T -= A[i], ++cnt;
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
