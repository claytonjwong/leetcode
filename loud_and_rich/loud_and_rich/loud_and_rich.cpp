/*
 
 851. Loud and Rich
 
 Q: https://leetcode.com/problems/loud-and-rich/description/
 A: https://leetcode.com/problems/loud-and-rich/discuss/138773/Straightforward-C++-DFS-solution-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    VI loudAndRich(VVI& R, VI& Q) {
        int N=(int)Q.size(); VVI G=VVI(N,VI{}); VI A=VI(N,-1);
        for (const auto& richer: R){
            int more=richer[0], less=richer[1];
            G[less].push_back(more);
        }
        for (int i=0; i<N; ++i)
            dfs(G,Q,A,i);
        return A;
    }
private:
    int dfs(const VVI& G, const VI& Q, VI& A, int i){
        if (A[i]>=0) return A[i]; else A[i]=i;
        for (const auto nei: G[i]){
            int cand=dfs(G,Q,A,nei);
            if (Q[cand] < Q[A[i]])
                A[i]=cand;
        }
        return A[i];
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    VVI R{{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    VI Q{3,2,5,4,6,1,7,0};
    auto r=s.loudAndRich(R, Q);
    
    return 0;
}
