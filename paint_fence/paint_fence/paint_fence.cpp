/*
 
 276. Paint Fence
 
 https://leetcode.com/problems/paint-fence/description/
 
 There is a fence with n posts, each post can be painted with one of the k colors.
 
 You have to paint all the posts such that no more than two adjacent fence posts have the same color.
 
 Return the total number of ways you can paint the fence.
 
 Note:
 n and k are non-negative integers.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
    int numWays(int n, int k) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=k;
        for (int i=2; i<n+1; ++i){
            dp[i]=(k-1)*(dp[i-1]+dp[i-2]);
        }
        return dp[n];
    }
};

class Solution {
public:
    int numWays(int n, int k) {
        if(n==0)        return 0;
        else if(n==1)   return k;
        
        int a[2];
        a[0]=1;
        a[1]=k;
        
        for(int i=2;i<n;i++){
            int cur = (k-1)*(a[0] + a[1]);
            a[0]=a[1];
            a[1]=cur;
        }
        
        return a[1]*k;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    Solution2 s2;
    while (true) {
        int n,k;
        cout << "n: "; cin >> n;
        cout << "k: "; cin >> k;
        cout << s.numWays(n, k) << endl;
        cout << s2.numWays(n, k) << endl;
    }
    
    
    
    return 0;
}




