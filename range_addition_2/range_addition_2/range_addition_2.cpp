/*
 
 Q: https://leetcode.com/problems/range-addition-ii/description/
 
 A: https://leetcode.com/problems/range-addition-ii/discuss/126194/2-liner-C++
 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op: ops){
            m=min(m,op[0]);
            n=min(n,op[1]);
        }
        return m*n;
    }
};
*/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (int i=0; i<ops.size(); m=min(m,ops[i][0]),n=min(n,ops[i][1]),++i);
        return m*n;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    int m=4,n=4;
    vector<vector<int>> ops{
        {1,2},
        {3,3},
    };
    auto r=s.maxCount(m, n, ops);
    
    
    return 0;
}



