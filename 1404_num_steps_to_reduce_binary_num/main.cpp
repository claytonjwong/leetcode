/*
 * 1404. Number of Steps to Reduce a Number in Binary Representation to One
 *
 * Q: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
 * A: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/discuss/564286/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    int numSteps(string s, deque<int> A = {}, int steps = 0) {
        transform(s.begin(), s.end(), back_inserter(A), [](auto c) { return int(c == '1'); });
        auto div = [&]() {
            A.pop_back();
        };
        auto inc = [&]() {
            int N = A.size(), i = N - 1, carry = 1;
            A[i] = 0; // 1 + 1 = 0 and carry = 1
            while (--i >= 0 && carry)
                if (A[i])
                    A[i] = 0; // 1 + 1 = 0 and carry = 1
                else
                    A[i] = 1, // 0 + 1 = 1 and carry = 0
                            carry = 0;
            if (carry) A.push_front(1);
        };
        while (A.size() > 1) {
            if (A.back() == 0)
                div();
            else
                inc();
            ++steps;
        }
        return steps;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
