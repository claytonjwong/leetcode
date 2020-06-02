/*
 * 949. Largest Time for Given Digits
 *
 * Q: https://leetcode.com/problems/largest-time-for-given-digits/
 * A: https://leetcode.com/problems/largest-time-for-given-digits/discuss/666302/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    string largestTimeFromDigits(VI& A, string best = {}) {
        sort(A.begin(), A.end());
        do {
            auto cand = time(A);
            if (best < cand)
                best = cand;
        } while (next_permutation(A.begin(), A.end()));
        return best;
    }
private:
    string time(VI& A, ostringstream os = ostringstream()) {
        copy(A.begin(), A.end(), ostream_iterator<int>(os));
        auto hour = os.str().substr(0, 2),
                min = os.str().substr(2);
        if (stoi(hour) <= 23 && stoi(min) <= 59)
            return hour + ":" + min;
        return "";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
