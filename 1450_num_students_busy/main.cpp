/*
 * 1450. Number of Students Doing Homework at a Given Time
 *
 * Q: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
 * A: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/discuss/640623/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        int busyStudent(VI& A, VI& B, int T) {
            return count_if(A.begin(), A.end(), [i = -1, &A, &B, T](auto _) mutable { ++i; return A[i] <= T && T <= B[i]; });
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        int busyStudent(VI& A, VI& B, int T, int cnt = 0) {
            auto N = A.size();
            for (auto i{ 0 }; i < N; ++i)
                if (A[i] <= T && T <= B[i])
                    ++cnt;
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
