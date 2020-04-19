/*
 * 1419. Minimum Number of Frogs Croaking
 *
 * Q: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
 * A: https://leetcode.com/problems/minimum-number-of-frogs-croaking/discuss/586488/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace Hardcoded {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        int minNumberOfFrogs(string S, Map cnt = Map{{'c', 0},{'r',0},{'o',0},{'a',0},{'k',0}}, int max = -1e9) {
            auto ok = [&]() { return cnt['c'] >= cnt['r'] && cnt['r'] >= cnt['o'] && cnt['o'] >= cnt['a'] && cnt['a'] >= cnt['k']; };
            for (auto c: S) {
                if (!ok())
                    return -1;
                ++cnt[c];
                if (c == 'k')
                    max = std::max(max, 1 + std::max({cnt['c'] - cnt['k'], cnt['r'] - cnt['k'], cnt['o'] - cnt['k'], cnt['a'] - cnt['k']}));
            }
            return cnt['c'] == cnt['r'] && cnt['r'] == cnt['o'] && cnt['o'] == cnt['a'] && cnt['a'] == cnt['k'] ? max : -1;
        }
    };
}
namespace CountArray {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<char, int>;
        int minNumberOfFrogs(string S, string order = "croak", int max = 0) {
            VI cnt(5);
            auto ok = [&]() {
                for (auto i{ 1 }; i < cnt.size(); ++i)
                    if (cnt[i - 1] < cnt[i])
                        return false;
                return true;
            };
            for (auto c: S) {
                if (!ok())
                    return -1;
                ++cnt[order.find(c)];
                if (c == 'k')
                    for (auto pre: string("croa"))
                        max = std::max(max, 1 + cnt[order.find(pre)] - cnt[order.find(c)]);
            }
            return all_of(cnt.begin(), cnt.end(), [&](auto x) { return x == cnt[0]; }) ? max : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
