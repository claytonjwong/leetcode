/*
 * 1560. Most Visited Sector in a Circular Track
 *
 * Q: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
 * A: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/discuss/806721/Javascript-Python3-C%2B%2B-Brute-Force-Count
 */

#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
