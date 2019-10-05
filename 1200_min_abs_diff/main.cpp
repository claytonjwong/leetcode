/*



 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <deque>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Deltas = deque<int>;
    VVI minimumAbsDifference(VI& A, int T=1e6+1, VVI ans={}) {
        sort(A.begin(), A.end());
        for (auto i=1; i < A.size(); ++i)
            T = min(T, A[i] - A[i-1]);
        for (auto i=1; i < A.size(); ++i)
            if (A[i-1] + T == A[i])
                ans.emplace_back(VI({A[i-1], A[i]}));
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VI A{1,3,6,10,15};
    auto ans = solution.minimumAbsDifference(A);
    for (auto& v: ans)
        cout << "[" << v[0] << "," << v[1] << "], ";
    cout << endl;
    return 0;
}