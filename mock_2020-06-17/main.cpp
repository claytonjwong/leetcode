/*
 * Apple- Phone Interview
 * Completed June 17, 2020 5:58 PM
 * 99%
 * Your interview score of 9.71/10 beats 99% of all users.
 * Time Spent: 6 minutes 57 seconds
 * Time Allotted: 1 hour 30 minutes
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 169. Majority Element
 *
 * Q: https://leetcode.com/problems/majority-element/
 * A: https://leetcode.com/problems/majority-element/discuss/618622/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        int majorityElement(VI &A, Map m = {}) {
            for (auto x: A)
                ++m[x];
            for (auto[x, cnt]: m)
                if (cnt > A.size() / 2)
                    return x;
            return -1;
        }
    };
}

/*
 * 34. Find First and Last Position of Element in Sorted Array
 *
 * Q: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * A: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/692931/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        VI searchRange(VI &A, int T) {
            auto[i, j] = equal_range(A.begin(), A.end(), T);
            auto beg = static_cast<int>(distance(A.begin(), i)),
                 end = static_cast<int>(distance(A.begin(), j)) - 1;
            return (i != A.end() && *i == T) ? VI{beg, end} : VI{-1, -1};
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
