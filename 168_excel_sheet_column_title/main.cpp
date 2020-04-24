/*
 * 168. Excel Sheet Column Title
 *
 * Q: https://leetcode.com/problems/excel-sheet-column-title/
 * A: https://leetcode.com/problems/excel-sheet-column-title/discuss/594280/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Recursive {
    class Solution {
    public:
        using VI = vector<int>;
        string convertToTitle(int N) {
            return !N ? "" : convertToTitle(--N / 26) + string(1, 'A' + N % 26); // -1 for 0-based to 1-based indexing
        }
    };
}
namespace Iterative {
    class Solution {
    public:
        using VI = vector<int>;
        string convertToTitle(int N, string ans = {}) {
            for (; N; N /= 26)
                --N, ans.push_back('A' + N % 26); // -1 for 0-based to 1-based indexing
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
