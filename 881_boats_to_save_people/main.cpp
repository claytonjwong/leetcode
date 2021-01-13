/*
 * 881. Boats to Save People
 *
 * Q: https://leetcode.com/problems/boats-to-save-people/
 * A: https://leetcode.com/problems/boats-to-save-people/discuss/1014992/Kt-Js-Py3-Cpp-Greedily-Consume-Boats
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int numRescueBoats(VI& A, int K, int cnt = 0) {
        sort(A.begin(), A.end());
        int N = A.size(),
            i = 0,
            j = N - 1;
        while (i <= j)
            if (A[i] + A[j] <= K)            // ⛵️ case 1: both 🙂 i-th and 🙂 j-th person
                ++cnt, ++i, --j;
            else                             // ⛵️ case 2: only 😕 j-th person
                ++cnt, --j;
        return cnt;                          // 🎯 minimum boat count via 💰 greedy consumption
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
