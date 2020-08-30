/*
 * 1566. Detect Pattern of Length M Repeated K or More Times
 *
 * Q: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
 * A: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/discuss/819276/Javascript-Python3-C%2B%2B-T-Pieces-Whole
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool containsPattern(VI& A, int K, int T) {
        string S; transform(A.begin(), A.end(), back_inserter(S), [](auto x) { return x + '0'; });
        for (auto i{ 0 }, j{ K * T }; i + j <= A.size(); ++i) {
            ostringstream whole;
            auto piece = S.substr(i, K);
            for (auto t{ T }; t--; whole << piece);
            if (whole.str() == S.substr(i, j))
                return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
