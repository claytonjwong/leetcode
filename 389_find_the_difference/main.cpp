/*
 * 389. Find the Difference
 *
 * Q: https://leetcode.com/problems/find-the-difference/
 * A: https://leetcode.com/problems/find-the-difference/discuss/862287/Javascript-Python3-C%2B%2B-Concise-solutions
 */

#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        return accumulate(t.begin(), t.end(), 0) - accumulate(s.begin(), s.end(), 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
