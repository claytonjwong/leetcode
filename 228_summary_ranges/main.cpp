/*
 * 228. Summary Ranges
 *
 * Q: https://leetcode.com/problems/summary-ranges/
 * A: https://leetcode.com/problems/summary-ranges/discuss/913748/Kt-Js-Py3-Cpp-Monotonic-Chains
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VI = vector<int>;
    VS summaryRanges(VI& A, VI chain = {}, VS chains = {}) {
        auto save = [&]() {
            stringstream stream;
            stream << chain.front();
            if (chain.front() != chain.back())
                stream << "->" << chain.back();
            chains.emplace_back(stream.str());
            chain.clear();
        };
        for (auto x: A) {
            if (!chain.empty() && x != 1 + chain.back())  // 🚫 broken link in the chain 🔗
                save();
            chain.push_back(x);
        }
        if (!chain.empty())
            save();
        return chains;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
