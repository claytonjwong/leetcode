/*
 
 46. Permutations
 
 Q: https://leetcode.com/problems/permutations/description/
 A: https://leetcode.com/problems/permutations/discuss/136424/Straightforward-C++-DFS-with-backtracking
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
using USI=unordered_set<int>;
class Solution {
public:
    VVI permute(VI& A, VVI ans={}) {
        dfs(A,ans);
        return ans;
    }
private:
    void dfs(const VI& A, VVI& ans, USI&& V={}, VI&& P={}){
        if (P.size()==A.size())
            ans.push_back(P);
        else
            for (auto x: A) if (V.insert(x).second){
                P.push_back(x);
                dfs(A,ans,move(V),move(P));
                P.pop_back();
                V.erase(x);
            }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    VI A{0,-1,1};
    auto ans=s.permute(A);
    
    // [[1,-1,0],[1,-1,0],[1,0,-1],[1,0,-1],]
    
    //  [0,-1,1] [-1,0,1],
    // [[0,-1,1],[-1,0,1],[-1,1,0],[0,1,-1],[1,0,-1],[1,-1,0]]
    
    return 0;
}
