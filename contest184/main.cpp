/*
 * https://leetcode.com/contest/weekly-contest-184/
 *
 * Rank          Name            Score    Finish Time    Q1 (3)          Q2 (4)      Q3 (5)     Q4 (7)
 * 2211 / 9816   claytonjwong    12       0:40:15        0:06:17  *1     0:14:19     0:35:15
 *
 * Q1: https://leetcode.com/problems/string-matching-in-an-array/
 * A1: https://leetcode.com/problems/string-matching-in-an-array/discuss/575927/Javascript-and-C%2B%2B-solutions
 *
 * Q2: https://leetcode.com/problems/queries-on-a-permutation-with-key/
 * A2: https://leetcode.com/problems/queries-on-a-permutation-with-key/discuss/575943/Javascript-and-C%2B%2B-solutions
 *
 * Q3: https://leetcode.com/problems/html-entity-parser/
 * A3: https://leetcode.com/problems/html-entity-parser/discuss/574892/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <sstream>
#include <limits>

using namespace std;


/*
 * 1408. String Matching in an Array
 *
 * Q: https://leetcode.com/problems/string-matching-in-an-array/
 * A: https://leetcode.com/problems/string-matching-in-an-array/discuss/575927/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VS = vector<string>;
        using Set = unordered_set<string>;
        VS stringMatching(VS& words, Set ans = {}) {
            for (auto& word: words)
                for (auto& sub: words)
                    if (word != sub && word.find(sub) != string::npos)
                        ans.insert(sub);
            return { ans.begin(), ans.end() };
        }
    };
}


/*
 * 1409. Queries on a Permutation With Key
 *
 * Q: https://leetcode.com/problems/queries-on-a-permutation-with-key/
 * A: https://leetcode.com/problems/queries-on-a-permutation-with-key/discuss/575943/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        VI processQueries(VI& queries, int N, VI ans = {}) {
            VI A(N); iota(A.begin(), A.end(), 1);
            for (auto j: queries) {
                auto i = distance(A.begin(), find(A.begin(), A.end(), j));
                for (ans.push_back(i); i > 0; --i)
                    swap(A[i - 1], A[i]); // 👈 "bubble up" A[i] to the front of A
            }
            return ans;
        }
    };
}


/*
 * 1410. HTML Entity Parser
 *
 * Q: https://leetcode.com/problems/html-entity-parser/
 * A: https://leetcode.com/problems/html-entity-parser/discuss/574892/Javascript-and-C%2B%2B-solutions
 */
namespace Question3 {
    class Solution {
    public:
        using Map = unordered_map<string, char>;
        string entityParser(string text, int i = -1, int j = -1, string ans = {}) {
            Map map{{"&quot;",'"'},{"&apos;",'\''},{"&amp;",'&'},{"&gt;",'>'},{"&lt;",'<'},{"&frasl;",'/'}};
            for (auto k{ 0 }; k < text.size(); ++k) {
                auto c = text[k];
                ans.push_back(c);
                if (c == '&') i = k;
                if (c == ';') j = k;
                if (i < j) {
                    auto N = int(ans.size()) - (j - i + 1); // N is the index of text[i..j] (+1 for i..j inclusive)v
                    auto T = ans.substr(N); // target 🎯
                    if (map.find(T) != map.end()) {
                        ans = ans.substr(0, N); // remove text[i..j]
                        ans.push_back(map[T]); // add corresponding html entity
                    }
                    i = j = -1;
                }
            }
            return ans;
        }
    };
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
