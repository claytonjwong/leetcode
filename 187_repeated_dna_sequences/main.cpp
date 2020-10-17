/*
 * 187. Repeated DNA Sequences
 *
 * Q: https://leetcode.com/problems/repeated-dna-sequences/
 * A: https://leetcode.com/problems/repeated-dna-sequences/discuss/898609/Kt-Js-Py3-Cpp-Sliding-Window-%2B-Map
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_map<string, int>;
    using Deque = deque<char>;
    VS findRepeatedDnaSequences(string s, Deque word = {}, Map m = {}, VS ans = {}) {
        for (auto c: s) {
            if (word.size() == 10)
                word.pop_front();
            word.push_back(c);
            ++m[{ word.begin(), word.end() }];
        }
        for (auto& [word, cnt]: m)
            if (1 < cnt)
                ans.emplace_back(word);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
