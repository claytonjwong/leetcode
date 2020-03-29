/*
 * 1395. Count Number of Teams
 *
 * Q2: https://leetcode.com/problems/count-number-of-teams/
 * A2: https://leetcode.com/problems/count-number-of-teams/discuss/555491/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int numTeams(VI& A, int ans = 0) {
        int N = A.size();
        for (auto i{ 0 }; i < N; ++i)
            for (auto j{ i + 1 }; j < N; ++j)
                for (auto k{ j + 1 }; k < N; ++k)
                    if ((A[i] < A[j] && A[j] < A[k]) || (A[i] > A[j] && A[j] > A[k]))
                        ++ans;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
