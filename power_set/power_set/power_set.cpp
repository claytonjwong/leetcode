/*
 
 78. Subsets
 
 Q: https://leetcode.com/problems/subsets/description/
 A: https://leetcode.com/problems/subsets/discuss/143148/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    VVI subsets(VI& A, VVI prev={{}}, VVI next={}, VVI ans={{}}){
        sort(A.begin(),A.end());
        for (int N=(int)A.size(); N--; swap(prev,next),next.clear()){
            for (auto num: A){
                for (auto& vec: prev) if (vec.empty() || vec.back() < num){
                    auto tmp(vec);
                    tmp.push_back(num);
                    next.emplace_back(std::move(tmp));
                }
            }
            ans.insert(ans.end(),next.begin(),next.end());
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> A{1,2,3};
    auto r=s.subsets(A);
    
    VI x={},y={x.begin(),x.end()};
    
    
    return 0;
}


