/*
 * 1640. Check Array Formation Through Concatenation
 *
 * Q: https://leetcode.com/problems/check-array-formation-through-concatenation/
 * A: https://leetcode.com/problems/check-array-formation-through-concatenation/discuss/919391/Kt-Js-Py3-Cpp-Do-we-%22have%22-what-we-%22need%22
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

namespace Queue {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Queue = queue<int>;
        bool canFormArray(VI& need, VVI& have, Queue q = {}) {
            for (auto x: need) {
                if (q.size()) {
                    if (x != q.front())
                        return false;
                    q.pop();
                    continue;
                }
                auto found{ false };
                for (auto& piece: have) {
                    if (x == piece[0]) {
                        found = true;
                        for (auto i{ 1 }; i < piece.size(); q.push(piece[i++]));
                        break;
                    }
                }
                if (!found)
                    return false;
            }
            return true;
        }
    };
}
namespace Map {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Map = unordered_map<int, int>;
        bool canFormArray(VI& need, VVI& have, Map m = {}, VI make = {}) {
            for (auto i{ 0 }; i < have.size(); ++i)
                m[have[i][0]] = i;
            int i = 0,
                N = need.size();
            while (i < N) {
                if (m.find(need[i]) == m.end())
                    return false;
                auto j = m[need[i]];
                make.insert(make.end(), have[j].begin(), have[j].end());
                i += have[j].size();
            }
            return need == make;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
