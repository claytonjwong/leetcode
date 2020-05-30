/*
 * 1461. Check If a String Contains All Binary Codes of Size K
 *
 * Q: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
 * A: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/660632/Incorrect-problem-statement!!!
 */

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    using Queue = deque<char>;
    using Set = unordered_set<string>;
    bool hasAllCodes(string S, int K, Queue q = {}, Set all = {}) {
        for (auto c: S) {
            q.push_back(c);
            if (q.size() == K) all.insert({ q.begin(), q.end() }), q.pop_front();
        }
        return all.size() == 1 << K;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
