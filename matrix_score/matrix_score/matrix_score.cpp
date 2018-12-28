/*

 861. Score After Flipping Matrix
 
 Q: https://leetcode.com/problems/score-after-flipping-matrix/description/
 A: https://leetcode.com/problems/score-after-flipping-matrix/discuss/144212/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
// AC
using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    int matrixScore(VVI& A, int ans=0) {
        int M=(int)A.size(),N=(int)A[0].size();
        for (auto& row: A)
            if (row[0]==0)
                for (int j=0; j<N; ++j)
                    row[j]^=1;
        for (int j=0; j<N; ++j){
            int cnt=0;
            for (int i=0; i<M; ++i){
                if (A[i][j])
                    ++cnt;
            }
            if (cnt < ceil(M/2.0))
                cnt=M-cnt;
            ans+=cnt*(1<<N-j-1);
        }
        return ans;
    }
};
 */

/*
// AC
using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    int matrixScore(VVI& A, int ans=0) {
        int M=(int)A.size(),N=(int)A[0].size();
        for (auto& row: A) if (row[0]==0) for (int j=0; j<N; row[j]^=1,++j);
        for (int j=0,cnt=0; j<N; ++j,cnt=0){
            for (int i=0; i<M; cnt=A[i][j]?cnt+1:cnt,++i);
            ans+=max(cnt,M-cnt)*(1<<(N-j-1));
        }
        return ans;
    }
};
 */

using VI=vector<int>;
using VVI=vector<VI>;
class Solution {
public:
    int matrixScore(VVI& A, int ans=0) {
        int M=(int)A.size(),N=(int)A[0].size();
        for (int j=0,cnt=0; j<N; ++j,cnt=0){
            for (int i=0; i<M; cnt=A[i][j]==A[i][0]?cnt+1:cnt,++i);
            ans+=max(cnt,M-cnt)*(1<<(N-j-1));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    VVI A{{0,1,0},{0,0,1}};
    cout << s.matrixScore(A) << endl;

    return 0;
}
