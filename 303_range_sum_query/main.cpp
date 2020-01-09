/*
 * 303. Range Sum Query - Immutable
 *
 * Q: https://leetcode.com/problems/range-sum-query-immutable/
 * A: https://leetcode.com/problems/range-sum-query-immutable/discuss/474670/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    using VI = vector<int>;
    NumArray(VI A) {
        auto N = A.size();
        S.resize(N + 1);
        S[0] = 0;
        for (auto i = 1; i <= N; ++i)
            S[i] = S[i - 1] + A[i - 1];
    }
    int sumRange(int i, int j) {
        return S[j + 1] - S[i];
    }
private:
    VI S;
};

int main() {
    NumArray numArray({-2,0,3,-5,2,-1});
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}
