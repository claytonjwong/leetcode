/*
 * 937. Reorder Data in Log Files
 *
 * Q: https://leetcode.com/problems/reorder-data-in-log-files/
 * A: https://leetcode.com/problems/reorder-data-in-log-files/discuss/633431/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VS = vector<string>;
        VS reorderLogFiles(VS& A, VS D = {}, VS L = {}, VS ans = {}) {
            for (auto& log: A) {
                istringstream is{ log };
                string _, word;
                is >> _ >> word;
                if (isdigit(word[0]))
                    D.push_back(log); // digit
                else
                    L.push_back(log); // letter
            }
            auto split = [](auto& log) {
                string id, word, sentence;
                istringstream is{ log };
                is >> id;
                while (is >> word)
                    sentence.append(word + " ");
                return make_tuple(id, sentence);
            };
            sort(L.begin(), L.end(), [&](auto& a, auto& b) {
                auto [id1, first] = split(a);
                auto [id2, second] = split(b);
                if (first == second)
                    return id1 < id2;
                return first < second;
            });
            copy(L.begin(), L.end(), back_inserter(ans));
            copy(D.begin(), D.end(), back_inserter(ans));
            return ans;
        }
    };
}

namespace Concise {
    class Solution {
    public:
        using VS = vector<string>;
        VS reorderLogFiles(VS& A) {
            auto pivot = stable_partition(A.begin(), A.end(), [&](auto& s) {
                auto i = s.find_first_of(" ");
                return isalpha(s[i + 1]);
            });
            sort(A.begin(), pivot, [](auto& a, auto& b) {
                auto i = a.find_first_of(" "),
                     j = b.find_first_of(" ");
                return a.substr(i) == b.substr(j) ? a.substr(0, i) < b.substr(0, j) : a.substr(i) < b.substr(j);
            });
            return A;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
