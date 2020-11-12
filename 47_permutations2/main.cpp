/*
 * 47. Permutations II
 *
 * Q: https://leetcode.com/problems/permutations-ii/
 * A: https://leetcode.com/problems/permutations-ii/discuss/136432/Kt-Js-Py3-Cpp-DFS-%2B-BT
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Seen = unordered_set<int>;
    using Unique = unordered_set<string>;
    using fun = function<void(void)>;
    VVI permuteUnique(VI& A, VVI ans = {}, VI path = {}, Seen seen = {}, Unique unique = {}) {
        auto N = A.size();
        fun go = [&]() {
            if (path.size() == N) {
                stringstream key; copy(path.begin(), path.end(), ostream_iterator<int>(key, " "));
                if (unique.insert(key.str()).second)
                    ans.emplace_back(path);
                return;
            }
            for (auto i{ 0 }; i < N; ++i)
                if (seen.insert(i).second)
                    path.push_back(A[i]),
                    go(),
                    path.pop_back(),
                    seen.erase(i);
        };
        go();
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
