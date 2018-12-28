/*
 
 279. Perfect Squares
 
 https://leetcode.com/problems/perfect-squares/description/
 
 Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 
 For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

class Solution {
public:
    int numSquares(int n){
        vector<int> dp(n+1,0), squares{};
        for (int i=1; i*i<=n; ++i) squares.push_back(i*i);
        for (int i=0; i<=3; ++i) dp[i]=i;
        for (int i=4; i<=n; ++i){
            int mini=INT_MAX;
            for (auto &&x: squares){
                int prev=i-x;
                if (prev<0) break;
                mini=min(mini,1+dp[prev]);
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
        //cout << s.numSquares(n) << endl;
        
        set<int> nums{1,4,9,16};
        cout << s.numSquares(n) << endl;
    }
    
    return 0;
}



