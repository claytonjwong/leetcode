/*
Apple Online Assessment
Completed April 29, 2020 5:57 PM
Time Spent: 11 minutes 17 seconds
Time Allotted: 1 hour
*/

#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 884. Uncommon Words from Two Sentences
 *
 * Q: https://leetcode.com/problems/uncommon-words-from-two-sentences/
 * A: https://leetcode.com/problems/uncommon-words-from-two-sentences/discuss/159907/Concise-C%2B%2B
 */
namespace Question1_Verbose {
    class Solution {
    public:
        using Set = set<string>;
        using VS = vector<string>;
        using Map = unordered_map<string, int>;
        VS uncommonFromSentences(string A, string B, Set a = {}, Set b = {}, Map cnt = {}, VS ans = {}) {
            auto getWords = [&](auto& s, auto& res) {
                istringstream stream{ s };
                for (string word; stream >> word; ++cnt[word], res.insert(word));
            };
            getWords(A, a);
            getWords(B, b);
            set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans));
            set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(ans));
            ans.erase(remove_if(ans.begin(), ans.end(), [&](auto& s) { return cnt[s] > 1; }), ans.end());
            return ans;
        }
    };
}
namespace Question1_Concise {
    class Solution {
    public:
        using VS = vector<string>;
        using Map = unordered_map<string, int>;
        VS uncommonFromSentences(string A, string B, Map cnt = {}, VS ans = {}) {
            auto getWords = [&](auto& s) {
                istringstream is{ s };
                for (string word; is >> word; ++cnt[word]);
            };
            getWords(A);
            getWords(B);
            for (auto [word, freq]: cnt)
                if (freq == 1)
                    ans.push_back(word);
            return ans;
        }
    };
}

namespace Question1_MoreConcise {
    class Solution {
    public:
        using VS = vector<string>;
        using Map = unordered_map<string, int>;
        VS uncommonFromSentences(string A, string B, Map cnt = {}, string word = {}, VS ans = {}) {
            istringstream isA{ A }; while (isA >> word) ++cnt[word];
            istringstream isB{ B }; while (isB >> word) ++cnt[word];
            for (auto [word, freq]: cnt)
                if (freq == 1)
                    ans.push_back(word);
            return ans;
        }
    };
}

/*
 * 1196. How Many Apples Can You Put into the Basket
 *
 * Q: https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/
 * A: https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/discuss/603936/Javascript-and-C%2B%2B-solution
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        int maxNumberOfApples(VI& A, int i = 0, int sum = 0) {
            sort(A.begin(), A.end());
            for (; i < A.size() && sum + A[i] <= 5000; sum += A[i++]);
            return i;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
