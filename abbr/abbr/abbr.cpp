/*
 
 Abbreviation
 
 https://www.hackerrank.com/challenges/abbr/editorial
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    //
    // TODO: this logic does NOT work for:
    // A=sYOCa
    // B=YOCN
    //
    
    bool isPossible(const string& A, const string& B){
        int m=(int)A.size(),n=(int)B.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int i=0; i<=m; ++i) dp[i][0]=1;
        for (int j=0; j<=n; ++j) dp[0][j]=1;
        for (int i=1; i<=m; ++i){
            for (int j=1; j<=n; ++j){
                if (dp[i-1][j-1] && (islower(A[i-1]) || toupper(A[i-1])==B[j-1]))
                    dp[i][j]=1;
            }
        }
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    int tests;
    string a,b;
    cin >> tests;
    while(tests>=0){
        cin >> a >> b;
        string res=s.isPossible(a, b) ? "YES" : "NO";
        cout << res << endl;
        --tests;
    }
    
    return 0;
}
