#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
class Solution {
public:
    using VI = vector<int>;
    VI lexicalOrder(int N, map<string, int> m={}, unordered_set<int> seen={}, VI ans={}) {
        auto gen = [](auto i) -> pair<string, int> {
            ostringstream os;
            os << i;
            return {os.str(), i};
        };
        for (auto i=1; i <= N; i *= 10) {
            m.emplace(gen(i));
            seen.insert(i);
        }
        while (ans.size() < N) {
            ans.push_back(m.begin()->second);
            auto next = m.begin()->second + 1;
            m.erase(m.begin());
            if (next <= N && seen.find(next) == seen.end())
                m.insert(gen(next));
        }
        return ans;
    }
};
*/

// the above solution is silly... just use a priority queue and also just use to_string to make a r-value pair instead of gen()
class Solution {
public:
    using VI = vector<int>;
    struct Cmp { bool operator()(const int lhs, const int rhs) const { return to_string(lhs) > to_string(rhs); } };
    using Queue = priority_queue<int, VI, Cmp>;
    VI lexicalOrder(int N, Queue q={}, unordered_set<int> seen={}, VI ans={}) {
        for (auto i=1; i <= N; i *= 10) {
            q.push(i);
            seen.insert(i);
        }
        while (ans.size() < N) {
            auto cur = q.top(); q.pop();
            ans.push_back(cur);
            auto next = cur + 1;
            if (next <= N && seen.find(next) == seen.end())
                q.push(next);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto ans = solution.lexicalOrder(20);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    return 0;
}
