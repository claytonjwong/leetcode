/*
 
 322. Coin Change
 
 https://leetcode.com/problems/coin-change/description/
 
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)
 
 Example 2:
 coins = [2], amount = 3
 return -1.
 
 Note:
 You may assume that you have an infinite number of each kind of coin.
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        static const int INIT=-1;
        vector<int> dp(amount+1,INIT);
        dp[0]=0;
        for (int i=1; i<=amount; ++i) // let i be the sub-amounts up to amount
            for (auto &&coin: coins)
                if (coin<=i && dp[i-coin]!=INIT)
                    dp[i]=dp[i]==INIT ? 1+dp[i-coin] : min(dp[i],1+dp[i-coin]);
        return dp[amount];
    }
};

int main(int argc, const char * argv[]) {

    
    Solution solution;
    vector<int> coins { 1, 2, 5 };
    cout << solution.coinChange(coins, 11) << endl;
    
    return 0;
}






