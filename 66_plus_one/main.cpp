/*
 * 66. Plus One
 *
 * Q: https://leetcode.com/problems/plus-one/
 * A: https://leetcode.com/problems/plus-one/discuss/722700/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Deque = deque<int>;
    VI plusOne(VI& A, int carry = 0) {
        int N = A.size(),
            i = N - 1;
        Deque ans{ A.begin(), A.end() };
        do {
            if (10 == ans[i] + 1)
                carry = 1, ans[i] = 0;
            else
                carry = 0, ans[i] = ans[i] + 1;
        } while (carry && 0 <= --i);
        if (carry)
            ans.push_front(1);
        return { ans.begin(), ans.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
