/*
 * 1528. Shuffle String
 *
 * Q: https://leetcode.com/problems/shuffle-string/
 * A: https://leetcode.com/problems/shuffle-string/discuss/756041/Javascript-Python3-C%2B%2B-create-t-from-s
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    string restoreString(string s, VI& A) {
        int N = A.size();
        string t(N, '\0');
        for (auto i{ 0 }; i < N; ++i)
            t[A[i]] = s[i];
        return t;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
