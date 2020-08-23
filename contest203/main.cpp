/*
 * Rank            Name             Score    Finish Time    Q1 (3)     Q2 (4)     Q3 (6)    Q4 (7)
 * 2885 / 15080    claytonjwong     7        0:22:12        0:14:46    0:22:12
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <queue>
#include <cmath>

using namespace std;

/*
 * 1560. Most Visited Sector in a Circular Track
 *
 * Q: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
 * A: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/806721/Javascript-Python3-C%2B%2B-Brute-Force-Count
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        VI mostVisited(int N, VI& A, VI ans = {}) {
            transform(A.begin(), A.end(), A.begin(), [](auto j) { return j - 1; });  // 💎 -1 for 0-based indexing
            VI cnt(N);
            auto i = A[0];
            cnt[i] = 1;
            for (auto j: A)
                while (i != j)
                    ++cnt[i = i + 1 < N ? i + 1 : 0];  // ⭐️ i wraps-around at N
            auto max = *max_element(cnt.begin(), cnt.end());
            for (auto i{ 0 }; i < N; ++i)
                if (cnt[i] == max)
                    ans.push_back(i + 1);  // 💎 +1 for 1-based indexing
            return ans;
        }
    };
}

/*
 * 1561. Maximum Number of Coins You Can Get
 *
 * Q: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
 * A: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/discuss/806726/Javascript-Python3-C%2B%2B-Greedy-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        int maxCoins(VI& A, int ans = 0) {
            sort(A.begin(), A.end());
            int N = A.size(),
                K = N / 3,
                i = N - 2;
            while (K--)
                ans += A[i], i -= 2;
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
