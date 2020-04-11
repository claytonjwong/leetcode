/*
 * Facebook - Online Assessment
 * Completed April 10, 2020 5:37 PM
 * Time Spent: 19 minutes 24 seconds
 * Time Allotted: 1 hour
 */


#include <iostream>
#include <vector>

using namespace std;


/*
 * 303. Range Sum Query - Immutable
 *
 * Q: https://leetcode.com/problems/range-sum-query-immutable/
 * A: https://leetcode.com/problems/range-sum-query-immutable/discuss/474670/Javascript-and-C%2B%2B-solutions
 */

namespace Question1 {
    class NumArray {
    public:
        NumArray(vector<int>& nums) {
            int N = nums.size();
            A.resize(N + 1);
            for (auto i{ 1 }; i <= N; ++i)
                A[i] = A[i - 1] + nums[i - 1];
        }
        int sumRange(int i, int j) {
            return A[j + 1] - A[i];
        }
    private:
        vector<int> A;
    };
}


/*
 * 157. Read N Characters Given Read4
 *
 * Q: https://leetcode.com/problems/read-n-characters-given-read4/
 * A: https://leetcode.com/problems/read-n-characters-given-read4/discuss/573173/Javascript-and-C%2B%2B-solutions
 */

namespace Question2 {
    int read4(char* buf);
    class Solution {
    public:
        int read(char *buf, int N, int read = 0) {
            auto write{ buf };
            do {
                char next[4];
                read = read4(next);
                for (auto i{ 0 }; i < read && write - buf < N; ++i)
                    *write++ = next[i];
            } while (read == 4 && write - buf < N);
            return write - buf;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
