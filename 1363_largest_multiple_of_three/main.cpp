/*
 * 1363. Largest Multiple of Three
 *
 * Q: https://leetcode.com/problems/largest-multiple-of-three/
 * A: https://leetcode.com/problems/largest-multiple-of-three/discuss/522770/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Cnt = unordered_map<char, int>;
    string largestMultipleOfThree(VI& A, int sum = 0, Cnt cnt = {}, stringstream ans = stringstream()) {
        for (auto x: A)
            ++cnt[x], sum += x;
        if (sum == 0)
            return "0";
        VVI mod{{},{1, 4, 7, 2, 5, 8}, {2, 5, 8, 1, 4, 7}}; // 0, 1, 2
        while (sum % 3) {
            for (auto x: mod[sum % 3]) {
                if (cnt[x]) {
                    --cnt[x], sum -= x; break;
                }
            }
        }
        for (auto i = 9; i >= 0; --i)
            if (cnt[i])
                ans << string(cnt[i], '0' + i);
        return ans.str();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
