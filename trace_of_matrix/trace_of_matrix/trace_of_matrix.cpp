/*
 
 https://www.codechef.com/LTIME60B/problems/TRACE
 
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

using VI=vector<int>;
using VVI=vector<vector<int>>;
int main(int argc, const char * argv[]) {
    int T,N;
    cin >> T;
    while (T--){
        cin >> N;
        VVI A(N,VI(N));
        int maxi=0;
        for (int i=0; i<N; ++i)
            for (int j=0; j<N; ++j){
                cin >> A[i][j];
                if (maxi < A[i][j]){
                    maxi=A[i][j];
                }
            }
        VVI dp(A);
        for (int i=1; i<N; ++i)
            for (int j=1; j<N; ++j){
                dp[i][j]=dp[i-1][j-1]+A[i][j];
                if (maxi < dp[i][j]){
                    maxi=dp[i][j];
                }
            }
        cout << maxi << endl;
    }
    return 0;
}
/*
 
1
3
1 2 60
6 3 4
2 7 1
 
 
 */


