/*
 * 406. Queue Reconstruction by Height
 *
 * Q: https://leetcode.com/problems/queue-reconstruction-by-height/
 * A: https://leetcode.com/problems/queue-reconstruction-by-height/discuss/673416/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI reconstructQueue(VVI& A, int INF = int(1e9 + 7)) {
        int N = A.size();
        VVI ans(N, VI(2, INF));
        sort(A.begin(), A.end(), [](auto& a, auto& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        for (auto& pair: A) {
            auto [h, k] = tie(pair[0], pair[1]);
            auto i{ 0 }, j{ k };
            while (j) // skip past k people which have height >= h
                if (ans[i++][0] >= h)
                    --j;
            while (ans[i][0] < INF) // find next available index for insertion
                ++i;
            ans[i] = VI{ h, k }; // insert here 🎯
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
