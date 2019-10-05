/*

 Score: 5.62 of 10

 Q1: https://leetcode.com/problems/rotated-digits/
 A1: https://leetcode.com/problems/rotated-digits/discuss/394958/Javascript-and-C%2B%2B-Solutions

 Q2: https://leetcode.com/problems/maximize-distance-to-closest-person/
 A2: https://leetcode.com/problems/maximize-distance-to-closest-person/discuss/394981/Javascript-and-C%2B%2B-Solutions

 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace Q1 {
    class Solution {
    public:
        int rotatedDigits(int N, int ans=0) {
            auto ok = [](auto num, bool rotated=false) {
                for (; num > 0; num /= 10) {
                    auto last = num % 10;
                    if (last == 3 || last == 4 || last == 7)
                        return false;
                    if (last == 2 || last == 5 || last == 6 || last == 9)
                        rotated = true;
                }
                return rotated;
            };
            for (auto n=1; n <= N; ans += ok(n++));
            return ans;
        }
    };
}

namespace Q2 {
    class Solution {
    public:
        int maxDistToClosest(vector<int>& A) {
            int N = A.size(), L{-1}, R{-1}, run{0}, max_run{0};
            for (int i=0; i < N; ++i) {
                if (A[i])
                    L = L == -1 ? i : L, run=0;
                else
                    max_run = max(max_run, ++run);
                if (A[N-1 - i])
                    R = R == -1 ? N-1 - i : R;
            }
            return max({L, int(ceil(max_run / 2.0)), N - (R+1)});
        }
    };
}

int main() {
    Q1::Solution solution1;


    return 0;
}
