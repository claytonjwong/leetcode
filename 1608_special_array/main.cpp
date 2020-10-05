/*
 * 1608. Special Array With X Elements Greater Than or Equal X
 *
 * Q: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
 * A: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/discuss/877706/Javascript-Python3-C%2B%2B-Lower-Bound-(ie.-Binary-Search)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int specialArray(VI& A) {
        int N = A.size();
        sort(A.begin(), A.end());
        for (auto i{ 0 }; i <= N; ++i)
            if (distance(A.begin(), lower_bound(A.begin(), A.end(), i)) == N - i)
                return i;
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
