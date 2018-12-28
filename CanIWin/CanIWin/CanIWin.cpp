/*
 
 
 
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class SolutionAC {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger, tar = desiredTotal, sum = 0;
        for (int i = 1; i <= n; ++i) sum += i;
        // this case is impossible
        if (tar > sum) return false;
        // used[i] marks whether i+1 was used;
        // the key of dp is binary format of int, representing which numbers have been used
        unordered_map<int, bool> dp;
        vector<int> used(n, 1);
        return helper(used, dp, 0, tar);
    }
private:
    bool helper(vector<int>& used, unordered_map<int, bool>& dp, int key, int tar) {
        if (dp.count(key)) return dp[key];
        int n = used.size();
        // search backward, greedy choice
        for (int i = n-1; i >= 0; --i) {
            if (used[i]) {
                // can win
                if (i+1 >= tar) {
                    dp[key] = true;
                    return true;
                }
                // backtracking
                used[i] = 0;
                // if next state key|(1<<i) results in lose, this state can win;
                // however, if next state can win, this state is not necessary to lose; we need search all choices.
                if (!helper(used, dp, key|(1<<i), tar-i-1)) {
                    dp[key] = true;
                    // if next line commented, it won't pass test case (10, 40)
                    // I thought if it returns true, I don't have to reset used[i]; However, when it is true for current state,
                    // backtracking or DFS/dp for previous state will continue searching, so it is necessary to reset used[i]
                    used[i] = 1;
                    return true;
                }
                used[i] = 1;
            }
        }
        dp[key] = false;
        return false;
    }
};

class Solution {
    unordered_map<int,bool> winner;
    bool go(int N, int T, int V=0){
        if (T<=0)
            return false;
        if (winner.find(V)!=winner.end())
            return winner[V];
        for (int i=1; i<=N; ++i){
            if (V&(1<<i)) continue; // already visisted
            V|=1<<i; // visit
            if (T-i<=0 || !go(N,T-i,V)){ // second player looses, first player wins
                winner[V]=true;
                V&=(~(1<<i)); // un-visit
                return true;
            }
            V&=(~(1<<i)); // un-visit
        }
        return winner[V]=false;
    }
public:
    bool canIWin(int N, int T) {
        return T==0 ? true : N*(N+1)/2 < T ? false : go(N,T);
    }
};
int main(int argc, const char * argv[]) {
    
    SolutionAC a;
    Solution s;
    //int maxi=10,target=0; // true
    int maxi=10,target=40; // false
    cout << s.canIWin(maxi, target) << endl;
    cout << a.canIWin(maxi, target) << endl;
    
    
    return 0;
}


