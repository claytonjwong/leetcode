/*
 
 835. Image Overlap
 
 Q: https://leetcode.com/problems/image-overlap/description/
 A: https://leetcode.com/problems/image-overlap/discuss/133614/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using VI=vector<int>;
using VVI=vector<vector<int>>;
class Solution {
public:
    int largestOverlap(VVI& A, VVI& B, int ans=0) {
        int M=(int)A.size(),N=(int)A[0].size(),P=(int)B.size(),Q=(int)B[0].size();
        VVI G(2*M+P,VI(2*N+Q,0));
        for (int i=0; i<P; ++i)
            for (int j=0; j<Q; ++j)
                G[i+M][j+N]=B[i][j];
        for (int x=1; x<M+P; ++x)
            for (int y=1; y<N+Q; ++y)
                ans=max(ans,traverse(A,G,x,y,M,N));
        return ans;
    }
private:
    int traverse(VVI& A, VVI& G, int x, int y, int M, int N, int cnt=0){
        for (int i=0; i<M; ++i)
            for (int j=0; j<N; ++j)
                cnt+=A[i][j]*G[i+x][j+y];
        return cnt;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<vector<int>> A{
        {1},
    };

    vector<vector<int>> B{
        {1},
    };
    cout << s.largestOverlap(A, B) << endl;
    
    return 0;
}


