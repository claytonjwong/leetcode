/*
 * 448. Find All Numbers Disappeared in an Array
 *
 * Q: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * A: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/672550/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI findDisappearedNumbers(VI& A) {
        VI ans(A.size() + 1);  // +1 for 1-based indexing (0 is a sentinel placeholder value)
        iota(ans.begin(), ans.end(), 0); // ans[i] = i
        for_each(A.begin(), A.end(), [&](auto x) { ans[x] = 0; });
        ans.erase(remove_if(ans.begin(), ans.end(), [](auto x) { return !x; }), ans.end());
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
