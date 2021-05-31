/*
 * 65. Valid Number
 *
 * Q: https://leetcode.com/problems/valid-number/
 * A: https://leetcode.com/problems/valid-number/discuss/1209666/A-few-solutions
 */

#define USE_BOOST 1  // 👈 uncomment this line to use boost 🚀

#ifdef USE_BOOST
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#endif
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using VS = vector<string>;

class Solution {
public:
    bool isNumber(string s) {
        auto indexAfterSign = [](auto& s) {
            auto i = 0;
            while (i < s.size() && s[i] == '+' || s[i] == '-')
                ++i;
            return i;
        };
        auto isOK = [&](auto& s, auto allowed) {
            auto i = indexAfterSign(s);
            auto t = s.substr(i);
            if (1 < i || t.empty() || t == ".")  // 💩 sanity check
                return false;
            return count_if(t.begin(), t.end(), [](auto c){ return c == '.'; }) <= allowed
                   && all_of(t.begin(), t.end(), [](auto c){ return isdigit(c) || c == '.'; });
        };
        auto isInteger = [&](auto& s) { return isOK(s, 0); };
        auto isDecimal = [&](auto& s) { return isOK(s, 1); };
        VS A;
#if USE_BOOST
        boost::split(A, s, boost::is_any_of("eE")); // boost 🚀 is awesome! 🎉 🥳
#else
        //
        // 🙃 without boost: simply splitting a string on one 'e' xor 'E' is verbose
        //
        auto isE = [](auto c) { return c == 'e' || c == 'E'; };
        if (1 == count_if(s.begin(), s.end(), isE)) {
            string t;
            transform(s.begin(), s.end(), back_inserter(t), [&](auto c) { return !isE(c) ? c : ' '; });
            stringstream ss{ t };
            for (string word; ss >> word; A.emplace_back(word));
        }
#endif
        if (2 == A.size())
            return (isInteger(A[0]) || isDecimal(A[0])) && isInteger(A[1]);
        return isInteger(s) || isDecimal(s);
    }
};

int main() {
    Solution solution;
    VS A{ "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789" },
       B{ "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "e.7e5" };
    for (auto& s: A) assert( solution.isNumber(s));
    for (auto& s: B) assert(!solution.isNumber(s));
    return 0;
}
