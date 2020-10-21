/*
 * 1618. Maximum Font to Fit a Sentence in a Screen
 *
 * Q: https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/
 * A: https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/discuss/904856/Kt-Js-Py3-Cpp-Binary-Search
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class FontInfo {
public:
    int getWidth(int fontSize, char ch);
    int getHeight(int fontSize);
};

class Solution {
public:
    using VI = vector<int>;
    int maxFont(string s, int w, int h, VI& A, FontInfo fontInfo) {
        auto height = [&](auto x) {
            return fontInfo.getHeight(x);
        };
        auto width = [&](auto x) {
            return accumulate(s.begin(), s.end(), 0, [&](auto total, auto c) { return total + fontInfo.getWidth(x, c); });
        };
        auto ok = [&](auto x) {
            return height(x) <= h && width(x) <= w;
        };
        int N = A.size(),
            i = 0,
            j = N - 1;
        while (i < j) {
            auto k = (i + j) / 2;
            if (ok(A[k + 1]))
                i = k + 1;
            else
                j = k;
        }
        return ok(A[i]) ? A[i] : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
