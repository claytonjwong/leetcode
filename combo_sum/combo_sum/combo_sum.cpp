/*
 
 39. Combination Sum
 
 Q: https://leetcode.com/problems/combination-sum/description/
 A: https://leetcode.com/problems/combination-sum/discuss/139125/Straightforward-C++-DFS-+-Backtracking-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    VVI combinationSum(VI& A, int T, VI path={}, VVI ans={}) {
        sort(A.begin(),A.end());
        return dfs(A,T,path,ans);
    }
private:
    VVI dfs(const VI& A, const int T, VI& path, VVI& ans, int beg=0, int sum=0){
        if (sum==T){
            ans.push_back(path);
            return VVI{};
        }
        for (int i=beg,N=(int)A.size(); i<N; ++i){
            path.push_back(A[i]);
            if (sum+A[i]<=T)
                dfs(A,T,path,ans,i,sum+A[i]);
            path.pop_back();
        }
        return path.empty() ? ans : VVI{};
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    VI A{2,3,5}; int T=8;
    auto r=s.combinationSum(A, T);


    return 0;
}


