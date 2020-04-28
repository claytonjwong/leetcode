/*
 * 734. Sentence Similarity
 *
 * Q: https://leetcode.com/problems/sentence-similarity/
 * A: https://leetcode.com/problems/sentence-similarity/discuss/600740/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using Set = unordered_set<string>;
    bool areSentencesSimilar(VS& A, VS& B, VVS& pairs, Set same = {}) {
        auto M = A.size(),
                N = B.size();
        if (M != N)
            return false;
        auto key = [](auto& a, auto& b) {
            stringstream ss; ss << a << "_" << b;
            return ss.str();
        };
        auto similar = [&](auto& a, auto& b) {
            return a == b || same.find(key(a, b)) != same.end() || same.find(key(b, a)) != same.end();
        };
        for (auto& p: pairs) {
            auto [a, b] = tie(p[0], p[1]);
            same.insert(key(a, b));
            same.insert(key(b, a));
        }
        for (auto i{ 0 }; i < N; ++i)
            if (!similar(A[i], B[i]))
                return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
