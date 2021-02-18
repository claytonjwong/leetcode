/*
 * 120. Triangle
 *
 * Q: https://leetcode.com/problems/triangle/
 * A: https://leetcode.com/problems/triangle/discuss/38726/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using fun = function<int(int, int)>;
        int minimumTotal(VVI& A) {
            fun go = [&](auto i, auto j) {
                if (i == A.size())
                    return 0;
                return A[i][j] + min(go(i + 1, j), go(i + 1, j + 1));
            };
            return go(0, 0);
        }
    };
}

namespace TopDownMemo {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using fun = function<int(int, int)>;
        using Map = unordered_map<string, int>;
        int minimumTotal(VVI& A, Map m = {}) {
            fun go = [&](auto i, auto j) {
                stringstream key; key << i << "," << j;
                if (m.find(key.str()) != m.end())
                    return m[key.str()];
                if (i == A.size())
                    return m[key.str()] = 0;
                return m[key.str()] = A[i][j] + min(go(i + 1, j), go(i + 1, j + 1));
            };
            return go(0, 0);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int minimumTotal(VVI& A) {
            int N = A.size();
            for (auto i{ N - 2 }; 0 <= i; --i)
                for (auto j{ 0 }; j < A[i].size(); ++j)
                    A[i][j] += min(A[i + 1][j], A[i + 1][j + 1]);
            return A[0][0];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
