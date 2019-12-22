/*
 * 1282. Group the People Given the Group Size They Belong To
 *
 * Q: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
 * A: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/discuss/448636/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI groupThePeople(VI& A, int id=0, map<int, VI> m={}, VVI ans={}) {
        int N = A.size();
        for (auto i = 0; i < N; ++i) m[A[i]].push_back(i);
        for (auto it=m.begin(); it != m.end(); ++it) {
            cout << it->first << ": ";
            copy(it->second.begin(), it->second.end(), ostream_iterator<int>(cout, " ")); cout << endl;
        }
        for (auto it=m.begin(); it != m.end();) {
            ans.emplace_back(VI{it->second.back()}), it->second.pop_back();
            while (ans.back().size() < it->first)
                ans.back().push_back(it->second.back()), it->second.pop_back();
            if (it->second.empty())
                ++it;
        }
        return ans;
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = map<int, VI>;
    VVI groupThePeople(VI& A, Map m={}, VVI ans={}) {
        for (auto i = 0; i < A.size(); ++i)
            m[A[i]].push_back(i);
        auto it = m.begin();
        while (it != m.end()) {
            auto& k = it->first;
            auto& x = it->second;
            ans.emplace_back(VI{x.back()}), x.pop_back();
            while (ans.back().size() < k)
                ans.back().push_back(x.back()), x.pop_back();
            if (x.empty())
                ++it;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VI A{3,3,3,3,3,1,3};
    auto ans = solution.groupThePeople(A);
    return 0;
}
