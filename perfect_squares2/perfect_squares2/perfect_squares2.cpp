/*
 
 279. Perfect Squares
 
 https://leetcode.com/problems/perfect-squares/description/
 
 Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 
 For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 
 */



#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numSquares(int n){
        vector<int> dp(n+1,0);
        set<int> squares{};
        for (int i=1; i*i<=n; ++i) squares.insert(i*i);
        for (int i=0; i<4; i++) dp[i]=i;
        for (int i=4; i<=n; ++i){
            int mini=INT_MAX;
            for (auto &&x: squares){
                if (i-x<0) break;
                mini=min(mini,1+dp[i-x]);
            }
            dp[i]=mini;
        }
        
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    while(true){
        int n;
        cout << "n: "; cin >> n;
        cout << s.numSquares(n) << endl;
    }
    
    
    return 0;
}



