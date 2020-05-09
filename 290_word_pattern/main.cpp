/*
 * 290. Word Pattern
 *
 * Q: https://leetcode.com/problems/word-pattern/
 * A: https://leetcode.com/problems/word-pattern/discuss/622795/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_map<char, string>;
    using Set = unordered_set<string>;
    bool wordPattern(string P, string words, VS A = {}, Map m = {}, Set seen = {}) {
        istringstream is{ words };
        for (string word; is >> word; A.push_back(word));
        if (P.size() != A.size())
            return false;
        for (auto i{ 0 }; i < A.size(); ++i) {
            if (m.find(P[i]) == m.end() && seen.insert(A[i]).second)
                m[P[i]] = A[i];
            if (m[P[i]] != A[i])
                return false;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
