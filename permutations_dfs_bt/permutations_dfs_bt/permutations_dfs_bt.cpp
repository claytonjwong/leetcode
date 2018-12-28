/*
 
 46. Permutations
 
 Q: https://leetcode.com/problems/permutations/description/
 A: https://leetcode.com/problems/permutations/discuss/136424/Straightforward-C++-DFS-with-backtracking
 
 
 47. Permutations II
 
 Q: https://leetcode.com/problems/permutations-ii/description/
 A: https://leetcode.com/problems/permutations-ii/discuss/136432/Straightforward-C++-DFS-with-Backtracking
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
class Solution {
    unordered_set<int> V;
    vector<int> path;
    vector<vector<int>> ans;
    void go(const vector<int>& A){
        int M=(int)path.size(),N=(int)A.size();
        if (M==N){
            ans.push_back(path);
            return;
        }
        for (int i=0; i<N; ++i){
            if (V.insert(i).second){
                path.push_back(A[i]);
                go(A);
                V.erase(i);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& A) {
        ans.clear();
        go(A);
        return ans;
    }
};
*/

class Solution {
    struct hash{
        size_t operator()(const vector<int>& A) const {
            size_t ans=0;
            for (int i=0,N=(int)A.size(); i<N; ++i)
                ans+=A[i]*(i+1);
            return ans;
        }
    };
    unordered_set<vector<int>,hash> ans;
    unordered_set<int> V;
    vector<int> path;
    void go(const vector<int>& A){
        int M=(int)path.size(),N=(int)A.size();
        if (M==N){
            ans.insert(path);
            return;
        }
        for (int i=0; i<N; ++i){
            if (V.insert(i).second){
                path.push_back(A[i]);
                go(A);
                V.erase(i);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& A){
        ans.clear();
        go(A);
        return {ans.begin(),ans.end()};
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> A{1,1,2};
    auto r=s.permuteUnique(A);
    
    
    return 0;
}


