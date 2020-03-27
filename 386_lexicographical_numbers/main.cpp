/*
 * 386. Lexicographical Numbers
 *
 * Q: https://leetcode.com/problems/lexicographical-numbers/
 * A: https://leetcode.com/problems/lexicographical-numbers/discuss/414893/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    VI lexicalOrder(int N, VS S = {}, VI A = {}) {
        while (N) {
            stringstream ss; ss << N--;
            S.push_back(ss.str());
        }
        sort(S.begin(), S.end());
        transform(S.begin(), S.end(), back_inserter(A), [](auto& s) { return stoi(s); });
        return A;
    }
};

int main() {
    Solution solution;
    auto ans = solution.lexicalOrder(20);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    return 0;
}
