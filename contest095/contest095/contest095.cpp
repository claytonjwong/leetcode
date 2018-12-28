/*

https://leetcode.com/contest/weekly-contest-95

Rank            Name            Score   Finish Time     Q1 (3)    Q2 (5)    Q3 (7)    Q4 (7)
1175 / 3750     claytonjwong    3       0:02:06         0:02:06                       TLE

Q1: https://leetcode.com/problems/middle-of-the-linked-list/description/
A1: https://leetcode.com/problems/middle-of-the-linked-list/discuss/155461/Simple-C++-Solutions

Q4: https://leetcode.com/problems/profitable-schemes/description/
A4: https://leetcode.com/problems/profitable-schemes/discuss/155458/C++-DFS+BT-time-limit-expired

*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

using VI=vector<int>;
class Solution {
public:
    int profitableSchemes(int size, int target, VI& group, VI& profit, int ans=0) {
        DFS(group,profit,target,size,ans);
        return ans;
    }
private:
    void DFS(const VI& group, const VI& profit, const int target, int size, int& ans,
             int beg=0, int&& sum=0, VI&& path={}, unordered_set<int>&& V={}){
        for (int i=beg; i<(int)group.size(); ++i){
            if (!V.insert(i).second)
                continue;
            path.push_back(i);
            sum+=profit[i];
            size-=group[i];
            if (sum >= target && size >= 0)
                ++ans;
            if (size > 0)
                DFS(group,profit,target,size,ans,i+1,move(sum),move(path),move(V));
            V.erase(i);
            path.pop_back();
            sum-=profit[i];
            size+=group[i];
        }
    }
};





int main(int argc, const char * argv[]) {
    
/*

1
1
[1,1,1,1,2,2,1,2,1,1]
[0,1,0,0,1,1,1,0,2,2]

*/

    Solution s;
    int G=,P=1;
    VI grp{1,1,1,1,2,2,1,2,1,1};
    VI prf{0,1,0,0,1,1,1,0,2,2};
    auto res=s.profitableSchemes(G, P, grp, prf);
    cout << res << endl;
    
    
    return 0;
}
