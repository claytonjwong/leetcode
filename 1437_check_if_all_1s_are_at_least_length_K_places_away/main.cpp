/*
 * 1437. Check If All 1's Are at Least Length K Places Away
 *
 * Q: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
 * A: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/discuss/613577/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool kLengthApart(VI& A, int K, VI index = {}) {
        for_each(A.begin(), A.end(), [i = 0, &index](auto x) mutable {
            if (x)
                index.push_back(i);
            ++i;
        });
        return all_of(index.begin(), index.end(), [i = -1, K, &index](auto _) mutable {
            ++i;
            return i == 0 || index[i] - index[i - 1] > K;
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
