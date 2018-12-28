/*
 
 The Coin Change Problem
 
 https://www.hackerrank.com/challenges/coin-change/problem
 
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class SolutionREC {
public:
    long long coinChange(vector<int>& coins, int target){
        if (coins.empty()) return 0;
        return helper(coins,target,0);
    }
private:
    map<pair<int,int>,long long> memo{};
    long long helper(vector<int>& coins, int target, int i){
        if (memo[{target,i}]) return memo[{target,i}];
        if (target==0) return 1;
        if (target<0 || i==coins.size()) return 0;
        return memo[{target,i}]=(helper(coins,target-coins[i],i)+helper(coins,target,i+1));
    }
};



int main(int argc, const char * argv[]) {

    int n,target;
    cin >> target;
    cin >> n;
    vector<int> coins(n);
    for (int i=0; i<n; ++i){
        int coin;
        cin >> coin;
        coins[i]=coin;
    }
    SolutionREC solution;
    cout << solution.coinChange(coins,target) << endl;
    
    return 0;
}



