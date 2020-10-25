/*
 * 1629. Slowest Key
 *
 * Q: https://leetcode.com/problems/slowest-key/
 * A: https://leetcode.com/problems/slowest-key/discuss/909815/Kt-Js-Py3-Cpp-Best-Time
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    char slowestKey(VI& A, string keys, int best = 0, char ans = '\0') {
        for (auto i{ 0 }; i < A.size(); ++i) {
            auto time = 0 < i ? A[i] - A[i - 1] : A[i];
            auto key = keys[i];
            if (best < time || (best == time && ans < key))
                best = time,
                ans = key;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
