/*
 * 1271. Hexspeak
 *
 * Q: https://leetcode.com/problems/hexspeak/
 * A: https://leetcode.com/problems/hexspeak/discuss/444208/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string toHexspeak(string str, ostringstream os=ostringstream()) {
        auto num = stoll(str);
        os << hex << uppercase << num;
        auto A = os.str();
        for (auto i=0; i < A.size(); ++i) {
            if (A[i] == '0') A[i] = 'O';
            if (A[i] == '1') A[i] = 'I';
            if (!isalpha(A[i]))
                return "ERROR";
        }
        return A;
    }
};

int main() {
    Solution solution;
    auto ans = solution.toHexspeak("747823223228"); // "AEIDBCDIBC"
    cout << ans << endl;
    return 0;
}

