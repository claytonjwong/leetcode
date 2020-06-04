/*
 * 344. Reverse String
 *
 * Q: https://leetcode.com/problems/reverse-string/
 * A: https://leetcode.com/problems/reverse-string/discuss/670042/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Easy {
    class Solution {
    public:
        using VC = vector<char>;
        void reverseString(VC& S) {
            reverse(S.begin(), S.end());
        }
    };
}

namespace Hard {
    class Solution {
    public:
        using VC = vector<char>;
        void reverseString(VC& S) {
            int N = S.size();
            for (auto i{ 0 }; i < N / 2; ++i)
                swap(S[i], S[N - 1 - i]);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
