/*
 * 316. Remove Duplicate Letters
 *
 * Q: https://leetcode.com/problems/remove-duplicate-letters/
 * A: https://leetcode.com/problems/remove-duplicate-letters/discuss/890223/Kt-Js-Py3-C%2B%2B-Monotonic-Queue-%2B-Detailed-Explanation
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    using Set = unordered_set<char>;
    string removeDuplicateLetters(string s, Map last = {}, Set have = {}, string A = {}) {
        int N = s.size();
        for (auto i{ 0 }; i < N; ++i)
            last[s[i]] = i;
        for (auto i{ 0 }; i < N; ++i) {
            while (have.find(s[i]) == have.end() && A.size() && s[i] < A.back() && i < last[A.back()])
                have.erase(A.back()), A.pop_back();
            if (have.insert(s[i]).second)
                A.push_back(s[i]);
        }
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
