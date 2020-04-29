/*
 * 989. Add to Array-Form of Integer
 *
 * Q: https://leetcode.com/problems/add-to-array-form-of-integer/
 * A: https://leetcode.com/problems/add-to-array-form-of-integer/discuss/602275/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI addToArrayForm(VI& A, int K, int carry = 0) {
        reverse(A.begin(), A.end());
        for (auto i{ 0 }; K || i < A.size(); ++i) {
            if (i == A.size())
                A.push_back(0);
            A[i] += (K % 10) + carry;
            carry = int(A[i] >= 10);
            A[i] %= 10;
            K /= 10;
        }
        if (carry)
            A.push_back(carry);
        return { A.rbegin(), A.rend() };
    }
};

int main() {
    Solution::VI A{9, 9};
    Solution solution;
    auto ans = solution.addToArrayForm(A, 1);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
