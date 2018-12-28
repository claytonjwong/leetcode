/*
 
 812. Largest Triangle Area
 
 Q: https://leetcode.com/problems/largest-triangle-area/description/
 A: https://leetcode.com/problems/largest-triangle-area/discuss/123082/Calculate-area-using-matrix-for-shoe-+-lace
 
 */

#include <iostream>
#include <vector>

using namespace std;

using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p, double ans=0.0) {
        for (int i=0,N=(int)p.size(); i<N-2; ++i)
            for (int j=i+1; j<N-1; ++j)
                for (int k=j+1; k<N; ++k)
                    ans=max(ans,area(p[i],p[j],p[k]));
        return ans;
    }
private:
    double area(VI& p1, VI& p2, VI& p3) {
        int x1=p1[0],y1=p1[1];
        int x2=p2[0],y2=p2[1];
        int x3=p3[0],y3=p3[1];
        return abs( (x1*y2+x2*y3+x3*y1) - (y1*x2+y2*x3+y3*x1) ) / 2.0;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<vector<int>> p{
        {0,0},
        {2,0},
        {0,2},
        {0,1},
        {1,0},
    };
    cout << s.largestTriangleArea(p) << endl;
    
    
    return 0;
}
