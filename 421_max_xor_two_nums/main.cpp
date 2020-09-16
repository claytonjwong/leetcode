/*
 * 421. Maximum XOR of Two Numbers in an Array
 *
 * Q: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 * A: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/849679/Javascript-Python3-C%2B%2B-Trie-%2B-Greedy-Alternative-Path
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    struct Trie {
        unordered_map<int, shared_ptr<Trie>> m;
    };
    int findMaximumXOR(VI& A, int max = 0) {
        auto root = make_shared<Trie>();                 // 🌲 trie
        for (auto x: A) {
            auto _xor{ 0 };
            auto cur{ root },                            // 👀 current path in trie for inserting binary representation of x
                 alt{ root };                            // 🤔 alternative path for pre-existing values in trie
            for (auto i{ 31 }; 0 <= i; --i) {
                auto p = 0 < (x & (1 << i)) ? 1 : 0,     // 🚙 direction p and opposite 🚗 direction q
                     q = p ^ 1;
                if (cur->m.find(p) == cur->m.end())      // 🚙 add direction p to 👀 current path (as needed)
                    cur->m[p] = make_shared<Trie>();
                cur = cur->m[p];
                if (alt->m.find(q) != alt->m.end())      // 🚗 diff direction q for 🤔 alternative path (💰 greedily take this path whenever possible)
                    alt = alt->m[q], _xor ^= (1 << i);
                else                                     // 🚙 same direction p for 🤔 alternative path
                    alt = alt->m[p];
            }
            max = std::max(max, _xor);                   // 🎯 max xor
        }
        return max;
    }
};

int main() {
    Solution solution;
    Solution::VI A{ 1, 2 };
    cout << solution.findMaximumXOR(A) << endl;
    return 0;
}
