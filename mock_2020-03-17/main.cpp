/*
 * Facebook- Online Assessment
 * Completed March 17, 2020 12:34 PM
 * Your interview score of 8.36/10 beats 91% of all users.
 * Time Spent: 7 minutes 17 seconds
 * Time Allotted: 1 hour
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 977. Squares of a Sorted Array
 *
 * Q1: https://leetcode.com/problems/squares-of-a-sorted-array/
 * A1: https://leetcode.com/problems/squares-of-a-sorted-array/discuss/542713/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        VI sortedSquares(VI& A) {
            transform(A.begin(), A.end(), A.begin(), [](auto x) { return x * x; });
            sort(A.begin(), A.end());
            return A;
        }
    };
}

/*
 * 791. Custom Sort String
 *
 * Q2: https://leetcode.com/problems/custom-sort-string/
 * A2: https://leetcode.com/problems/custom-sort-string/discuss/542718/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        string customSortString(string S, string T, Map m = {}) {
            for (auto i = 0; i < S.size(); ++i)
                m[S[i]] = i;
            sort(T.begin(), T.end(), [&](auto a, auto b) {
                if (m.find(a) == m.end()) return false;
                if (m.find(b) == m.end()) return true;
                return m[a] < m[b];
            });
            return T;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
