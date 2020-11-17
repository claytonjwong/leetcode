/*
 * 1653. Minimum Deletions to Make String Balanced
 *
 * Q: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
 * A: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/discuss/938408/Kt-Js-Py3-Cpp-Prefix-%2B-Suffix
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minimumDeletions(string s) {
        int N = s.size();
        VI prefix(N),
           suffix(N),
           cands(N);
        int beg = 0,
                end = N - 1;
        for (auto i{ beg }; i <= end; ++i) prefix[i] = int(s[i] == 'b') + (beg < i ? prefix[i - 1] : 0);
        for (auto i{ end }; beg <= i; --i) suffix[i] = int(s[i] == 'a') + (i < end ? suffix[i + 1] : 0);
        for (auto i{ 0 }; i < N; ++i)
            cands[i] = prefix[i] + suffix[i];
        return *min_element(cands.begin(), cands.end()) - 1;  // ⭐️ -1 since we only need to delete 'a' xor 'b' at the optimal "pivot"
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
