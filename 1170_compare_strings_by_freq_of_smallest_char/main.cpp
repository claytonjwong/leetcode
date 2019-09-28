#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    VI numSmallerByFrequency(VS& queries, VS& words, VI ans={}) {
        auto values = [](const VS& q, VI v={}) -> VI {
            for (auto s: q) {
                sort(s.begin(), s.end());
                auto i=1; for (; i < s.size() && s[i-1] == s[i]; ++i); v.push_back(i);
            }
            return v;
        };
        auto q = values(queries), w = values(words);
        auto N = static_cast<int>(words.size());
        VI cnt(12); // index 0 is not used since each word length > 0, index 11 has value 0 (ie. nothing can be larger than 10), so cnt index 1 to index 10 inclusive are used to storing the actual counts of each value
        for (auto val: w)
            ++cnt[val];
        for (auto i=10; i > 0; --i)
            cnt[i] += cnt[i+1];
        for (auto cur: q)
            ans.push_back(cnt[cur+1]);
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VS queries{"cbd"},
                 words{"zaaaz"};
    auto ans = solution.numSmallerByFrequency(queries, words);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    return 0;
}