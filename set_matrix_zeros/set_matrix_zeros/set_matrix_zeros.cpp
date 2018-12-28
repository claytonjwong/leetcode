/*
 
 73. Set Matrix Zeroes
 
 Q: https://leetcode.com/problems/set-matrix-zeroes/description/
 A: https://leetcode.com/problems/set-matrix-zeroes/discuss/142905/Straightforward-C++-using-set-to-track-rowscols-to-zero-out
 
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
    void setZeroes(VVI& m, USI rows={}, USI cols={}) {
        for (int i=0,M=(int)m.size(); i<M; ++i)
            for (int j=0,N=(int)m[0].size(); j<N; ++j)
                if (m[i][j]==0)
                    rows.insert(i),cols.insert(j);
        for (auto i: rows)
            for (int j=0,N=(int)m[0].size(); j<N; ++j)
                m[i][j]=0;
        for (auto j: cols)
            for (int i=0,M=(int)m.size(); i<M; ++i)
                m[i][j]=0;
    }
};

int main(int argc, const char * argv[]) {
    
    VVI m{
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    Solution s;
    s.setZeroes(m);
    
    
    return 0;
}
