/*
 * 1239. Maximum Length of a Concatenated String with Unique Characters
 *
 * Q: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
 * A: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/discuss/786020/Javascript-Python3-C%2B%2B-hash-collisions
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Set = unordered_set<char>;
    using fun = function<int(int, int)>;
    int maxLength(VS& A) {
        A.erase(remove_if(A.begin(), A.end(), [](auto& s) { return Set{ s.begin(), s.end() }.size() < s.size(); }), A.end()); // 🚫 remove invalid s
        fun go = [&](int i, int pre) {
            if (i == A.size())
                return 0;
            auto cur = accumulate(A[i].begin(), A[i].end(), 0, [](auto hash, auto c) { return hash | 1 << (c - 'a'); });
            if (pre & cur)
                return go(i + 1, pre); // ❌ collision of non-unique chars, thus we only consider 🚫 without A[i]
            else
                return max(go(i + 1, pre), int(A[i].size()) + go(i + 1, pre | cur)); // max of 🚫 without A[i] xor ✅ with A[i]
        };
        return go(0, 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
