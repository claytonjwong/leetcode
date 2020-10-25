/*
 * 948. Bag of Tokens
 *
 * Q: https://leetcode.com/problems/bag-of-tokens/
 * A: https://leetcode.com/problems/bag-of-tokens/discuss/909784/Kt-Js-Py3-Cpp-Greedy-Max-Score
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int bagOfTokensScore(VI& A, int power, int score = 0, int best = 0) {
        sort(A.begin(), A.end());
        int N = A.size(),
            i = 0,
            j = N - 1;
        while (i <= j && (A[i] <= power || 0 < score)) {
            if (A[i] <= power)
                power -= A[i++], ++score;
            else if (0 <= score)
                power += A[j--], --score;
            best = max(best, score);
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
