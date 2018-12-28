/*
 
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
class Solution {
public:
    int splitArray(vector<int>& A, int K, int ans=INT_MAX) {
        vector<int> S(A.size()+1,0);
        for (int i=1,N=(int)S.size(); i<N; ++i) S[i]=S[i-1]+A[i-1];
        go(ans,S,K);
        return ans;
    }
private:
    int go(int& ans, const vector<int>& S, int K, int beg=0, int sum=0, int maxi=INT_MIN){
        int N=(int)S.size();
        if (K==0 && beg==N-K){
            ans=min(ans,maxi);
            return maxi;
        }
        if (K==0)
            return 0;
        for (int i=1; beg+i<=N-K; ++i){
            sum=S[beg+i]-S[beg];
            maxi=max(sum,go(ans,S,K-1,beg+i));
        }
        return maxi;
    }
};
*/

/*
class Solution {
public:
    int ans;
    int n, m;
    void dfs(vector<int>& nums, int i, int cntSubarrays, int curSum, int curMax) {
        if (i == n && cntSubarrays == m) {
            ans = min(ans, curMax);
            return;
        }
        if (i == n) {
            return;
        }
        if (i > 0) {
            dfs(nums, i + 1, cntSubarrays, curSum + nums[i], max(curMax, curSum + nums[i]));
        }
        if (cntSubarrays < m) {
            dfs(nums, i + 1, cntSubarrays + 1, nums[i], max(curMax, nums[i]));
        }
    }
    int splitArray(vector<int>& nums, int M) {
        ans = INT_MAX;
        n = (int)nums.size();
        m = M;
        dfs(nums, 0, 0, 0, 0);
        return ans;
    }
};
*/

class Solution {
public:
    int splitArray(vector<int>& A, int K) {
        int N = (int)A.size();
        vector<vector<int>> f(N + 1, vector<int>(K + 1, INT_MAX));
        vector<int> S(N + 1, 0);
        for (int i=1; i<=N; ++i) S[i]=S[i-1]+A[i-1];
        f[0][0] = 0;
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= K; k++) {
                for (int i = 0; i < j; i++) {
                    int prev=f[i][k - 1];
                    int curr=f[j][k];
                    int next=S[j] - S[i];
                    f[j][k] = min(curr, max(prev, next));
                }
            }
        }
        return f[N][K];
    }
};
int main(int argc, const char * argv[]) {
    
    vector<int> A{10,5,13,4,8,4,5,11,14,9,16,10,20,8}; int K=8;
    //vector<int> A{7,2,5,10,8}; int K=2;
    Solution s;
    auto r=s.splitArray(A,K);
    
    return 0;
}


