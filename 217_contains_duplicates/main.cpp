/*
 * 217. Contains Duplicate
 *
 * Q: https://leetcode.com/problems/contains-duplicate/
 * A: https://leetcode.com/problems/contains-duplicate/discuss/824996/Javascript-Python3-C%2B%2B-1-Liners-Seen-Set
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        bool containsDuplicate(VI& A) {
            return A.size() != Set{ A.begin(), A.end() }.size();
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        bool containsDuplicate(VI& A, Set S = {}) {
            for (auto x: A)
                if (!S.insert(x).second)
                    return true;
            return false;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
