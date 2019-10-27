#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    VVI queensAttacktheKing(VVI& queens, VI& king, Seen seen={}, VI not_found={-1,-1}, VVI ans={}) {
        for (auto& q: queens)
            seen[q[0]][q[1]] = true;
        VVI attack(8, not_found);
        for (auto d=1, x=king[0], y=king[1]; d < 8; ++d) { // d distance away from king
            VVI dirs{{ x, y - d, 0 }, { x + d, y - d, 1 }, { x + d, y, 2 }, { x + d, y + d, 3 },
                     { x, y + d, 4 }, { x - d, y + d, 5 }, { x - d, y, 6 }, { x - d, y - d, 7 }};
            for (auto& dir: dirs) {
                auto [i, j, k] = tie(dir[0], dir[1], dir[2]);
                if (attack[k] != not_found)
                    continue; // already found an attack queen for this direction
                if (seen[i][j])
                    attack[k] = { i, j };
            }
        }
        for (auto k=0; k < 8; ++k)
            if (attack[k] != not_found)
                ans.push_back(attack[k]);
        return ans;
    }
};

int main() {
    Solution::VVI queens{
        {{5,6},{7,7},{2,1},{0,7},{1,6},{5,1},{3,7},{0,3},{4,0},{1,2},{6,3},{5,0},{0,4},{2,2},{1,1},{6,4},{5,4},{0,0},{2,6},{4,5},{5,2},{1,4},{7,5},{2,3},{0,5},{4,2},{1,0},{2,7},{0,1},{4,6},{6,1},{0,6},{4,3},{1,7}}
    };
    Solution::VI king{3,4};
    auto ans = Solution().queensAttacktheKing(queens, king);
    for (auto i=0; i < ans.size(); ++i) {
        cout << "{" << ans[i][0] << "," << ans[i][1] << "}" << endl;
    }
    return 0;
}