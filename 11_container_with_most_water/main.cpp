/*
 * 11. Container With Most Water
 *
 * Q: https://leetcode.com/problems/container-with-most-water/
 * A: https://leetcode.com/problems/container-with-most-water/discuss/469278/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxArea(VI& A) {
        int i = 0, j = A.size() - 1, ans = 0;
        while (i < j) {
            ans = max(ans, min(A[i], A[j]) * (j - i));
            if (A[i] < A[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};

int main() {
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}
