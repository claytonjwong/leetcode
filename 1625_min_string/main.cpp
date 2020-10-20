/*
 * 1625. Lexicographically Smallest String After Applying Operations
 *
 * Q: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
 * A: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/discuss/903526/Kt-Js-Py3-Cpp-Brute-Force-via-DFS-%2B-BFS
 */

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

namespace DFS {
    class Solution {
    public:
        using Set = unordered_set<string>;
        using fun = function<void(string)>;
        string findLexSmallestString(string s, int amount, int pivot) {
            auto best{ s };
            Set seen{ s };
            fun go = [&](auto s) {
                if (best > s)
                    best = s;
                string increment;
                transform(s.begin(), s.end(), back_inserter(increment), [i = -1, amount](auto c) mutable {
                    return ++i & 1 ? (((c - '0') + amount) % 10) + '0' : c;
                });
                if (seen.insert(increment).second)
                    go(increment);
                auto rotate = s.substr(pivot) + s.substr(0, pivot);
                if (seen.insert(rotate).second)
                    go(rotate);
            };
            go(s);
            return best;
        }
    };
}

namespace BFS {
    class Solution {
    public:
        using Queue = queue<string>;
        using Set = unordered_set<string>;
        using fun = function<void(string)>;
        string findLexSmallestString(string s, int amount, int pivot) {
            auto best{ s };
            Queue q{{{ s }}};
            Set seen{ s };
            while (q.size()) {
                auto cur = q.front(); q.pop();
                if (best > cur)
                    best = cur;
                string increment;
                transform(cur.begin(), cur.end(), back_inserter(increment), [i = -1, amount](auto c) mutable {
                    return ++i & 1 ? (((c - '0') + amount) % 10) + '0' : c;
                });
                if (seen.insert(increment).second)
                    q.push(increment);
                auto rotate = cur.substr(pivot) + cur.substr(0, pivot);
                if (seen.insert(rotate).second)
                    q.push(rotate);
            }
            return best;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
