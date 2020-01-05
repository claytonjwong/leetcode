/*
 * 1309. Decrypt String from Alphabet to Integer Mapping
 *
 * Q: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
 * A: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/discuss/471422/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s, int offset = 96, int x = 0, string ans = {}) {
        while (!s.empty()) {
            if (s.back() == '#') {
                int n = s.size();
                stringstream ss; ss << s[n - 3] << s[n - 2]; ss >> x;
                s = s.substr(0, n - 3);
            } else {
                stringstream ss; ss << s.back(); ss >> x;
                s.pop_back();
            }
            ans.push_back(x + offset);
        }
        return {ans.rbegin(), ans.rend()};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
