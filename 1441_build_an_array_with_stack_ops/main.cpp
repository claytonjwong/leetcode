/*
 * 1441. Build an Array With Stack Operations
 *
 * Q: https://leetcode.com/problems/build-an-array-with-stack-operations/
 * A: https://leetcode.com/problems/build-an-array-with-stack-operations/discuss/624724/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VI = vector<int>;
    VS buildArray(VI& A, int N, VS ans = {}) {
        for (auto i{ 0 }, j{ 1 }; i < A.size(); ++j)
            if (A[i] == j)
                ans.emplace_back("Push"), ++i; // remaining element ✅
            else
                ans.emplace_back("Push"),      // missing element ❌
                ans.emplace_back("Pop");
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
