/*
 * 1299. Replace Elements with Greatest Element on Right Side
 *
 * Q: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
 * A: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/discuss/474473/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    using VI = vector<int>;
    VI replaceElements(VI& A) {
        int N = A.size(), maxi = A[N - 1];
        for (auto i = N - 2; i >=0; --i) {
            auto cur = A[i];
            A[i] = max(maxi, A[i + 1]);
            maxi = max(maxi, cur);
        }
        A[N - 1] = -1;
        return A;
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    VI replaceElements(VI& A, int cur = 0) {
        int N = A.size(), maxi = A[N - 1];
        for (auto i = N - 2; i >=0; --i, maxi = max(maxi, cur))
            cur = A[i], A[i] = max(maxi, A[i + 1]);
        A[N - 1] = -1;
        return A;
    }
};

int main() {
    Solution solution;
    Solution::VI A{17,18,5,4,6,1};
    auto ans = solution.replaceElements(A);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
