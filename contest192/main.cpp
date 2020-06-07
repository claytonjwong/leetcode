/*
 * https://leetcode.com/contest/weekly-contest-192
 * https://youtu.be/tdxyH8gHtMo
 *
 * Rank            Name             Score    Finish Time    Q1 (3)     Q2 (4)     Q3 (5)     Q4 (6)
 * 1812 / 13805    claytonjwong     12       0:29:09        0:02:03    0:11:43    0:29:09
 */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <limits>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

/*
 * 1470. Shuffle the Array
 *
 * Q: https://leetcode.com/problems/shuffle-the-array/
 * A: https://leetcode.com/problems/shuffle-the-array/discuss/674389/Javascript-and-C%2B%2B-solutions
 */
namespace Question1_Concise {
    class Solution {
    public:
        using VI = vector<int>;
        VI shuffle(VI& A, int K, int j = 0, VI ans = {}) {
            transform(A.begin(), A.end(), back_inserter(ans), [i = -1, &j, &A, K](auto _) mutable { return !(++i % 2) ? A[j++] : A[j + K - 1]; });
            return ans;
        }
    };
}
namespace Question1_Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        VI shuffle(VI& A, int K, VI ans = {}) {
            for (auto i{ 0 }; i < K; ++i)
                ans.push_back(A[i]),
                ans.push_back(A[i + K]);
            return ans;
        }
    };
}

/*
 * 1471. The k Strongest Values in an Array
 *
 * Q: https://leetcode.com/problems/the-k-strongest-values-in-an-array/
 * A: https://leetcode.com/problems/the-k-strongest-values-in-an-array/discuss/674391/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        VI getStrongest(VI& A, int K) {
            sort(A.begin(), A.end());
            auto m = A[(A.size() - 1) / 2];
            sort(A.begin(), A.end(), [&](auto a, auto b) { return abs(b - m) == abs(a - m) ? b < a : abs(b - m) < abs(a - m); });
            A.resize(K);
            return A;
        }
    };
}

/*
 * 1472. Design Browser History
 *
 * Q: https://leetcode.com/problems/design-browser-history/
 * A: https://leetcode.com/problems/design-browser-history/discuss/674419/Javascript-and-C%2B%2B-solutions
 */
namespace Question3 {
    class BrowserHistory {
        deque<string> url;
        int i = 0;
    public:
        BrowserHistory(string homepage) : url{ homepage } {
        }
        void visit(string next) {
            while (i)
                url.pop_front(), --i;
            url.push_front(next);
        }
        string back(int steps) {
            while (steps-- && i + 1 < url.size())
                ++i;
            return url[i];
        }
        string forward(int steps) {
            while (steps-- && 0 <= i - 1)
                --i;
            return url[i];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
