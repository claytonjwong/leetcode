/*
 
 70. Climbing Stairs
 
 Q: https://leetcode.com/problems/climbing-stairs/description/
 A: https://leetcode.com/problems/climbing-stairs/discuss/131943/Concise-C++-Top-Down-+-Bottom-Up-Solutions
 
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 // AC top-down recursive solution
class Solution {
public:
    int climbStairs(int n) {
        memo.clear();
        return go(n);
    }
private:
    unordered_map<int,int> memo;
    int go(int i){
        if (memo.find(i)!=memo.end()) return memo[i];
        if (i<2) return memo[i]=1;
        return memo[i]=go(i-2)+go(i-1);
    }
};
*/

/*
 // AC DP solution
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,1);
        for (int i=2; i<=n; ++i)
            dp[i]=dp[i-2]+dp[i-1];
        return dp[n];
    }
};
 */

/*
 // AC DP solution with optimized memory space via sliding window
class Solution {
public:
    int climbStairs(int n) {
        int c=1; for (int i=2,a=1,b=1; i<=n; ++i,a=b,b=c) c=a+b;
        return c;
    }
};
 */

class Solution {
public:
    int climbStairs(int n) {
        int c=1; for (int a=1,b=1; 1 < n--; a=b,b=c) c=a+b;
        return c;
    }
};


int main(int argc, const char * argv[]) {

    Solution s;
    cout << s.climbStairs(4) << endl;
    
    return 0;
}

