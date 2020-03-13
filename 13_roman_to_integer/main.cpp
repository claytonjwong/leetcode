/*
 * 13. Roman to Integer
 *
 * Q: https://leetcode.com/problems/roman-to-integer/
 * A: https://leetcode.com/problems/roman-to-integer/discuss/469658/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int romanToInt(string s, int val = 0, unordered_map<string, int> m = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}}) {
//        for (auto n = s.size(); s.size() > 1; n = s.size()) {
//            auto two = s.substr(n - 2), one = s.substr(n - 1);
//            if (m.find(two) != m.end())
//                val += m[two], s = s.substr(0, n - 2);
//            else
//                val += m[one], s = s.substr(0, n - 1);
//        }
//        return val + (s.empty() ? 0 : m[s]);
//    }
//};

class Solution {
public:
    using Map = unordered_map<char, int>;
    int romanToInt(string s, int cur = 0, int pre = 0, int ans = 0) {
        Map m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (auto c: string{s.rbegin(), s.rend()}) {
            cur = m[c];
            ans += cur < pre ? -cur : cur;
            pre = m[c];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("III") << endl;
    return 0;
}
