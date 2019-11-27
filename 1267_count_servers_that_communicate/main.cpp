/*
 * 1267. Count Servers that Communicate
 *
 * Q: https://leetcode.com/problems/count-servers-that-communicate/
 * A: https://leetcode.com/problems/count-servers-that-communicate/discuss/438394/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Servers = vector<tuple<int,int>>;
    int countServers(VVI& A, Servers servers={}, int ans=0) {
        int M = A.size(),
            N = A[0].size();
        VI row(M),
            col(N);
        for (auto i=0; i < M; ++i)
            for (auto j=0; j < N; ++j)
                if (A[i][j] == 1)
                    servers.push_back({i,j}),
                        ++row[i],
                        ++col[j];
        for (auto [i,j]: servers)
            if (row[i] > 1 || col[j] > 1)
                ++ans;
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{1,0},{0,1}};
    auto ans = solution.countServers(A);
    cout << ans << endl;
    return 0;
}
