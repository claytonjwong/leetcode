/*
 
 CCI CH 8.1 Triple Step: A child is running up a staircase with n steps and can hop either
 1 step, 2 steps, or 3 steps at a time.  Implement a method to count how many possible
 ways the child can run up the stairs.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int pathCount(int n){
        
        //
        // n <= 3
        //
        if ( n <=0 ) { return 0; }
        if ( n == 1 ) { return 1; } // 1 way to take 1 step
        if ( n == 2 ) { return 2; } // 2 ways to take 2 steps (1,1 or 2)
        if ( n == 3 ) { return 4; } // 4 ways to take 3 steps (1,1,1 or 1,2 or 2,1, or 3)
        
        //
        // n >= 4
        //
        vector<int> pathCount(n+1);
        calcPathCounts(pathCount);
        return pathCount[n];
    }

private:
    
    void calcPathCounts(vector<int>& dp){
        
        //
        // initial values based on requirement constraints
        //
        dp[0] = 0;
        dp[1] = 1; // 1 way to take 1 step
        dp[2] = 2; // 2 ways to take 2 steps (1,1 or 2)
        dp[3] = 4; // 4 ways to take 3 steps (1,1,1 or 1,2 or 2,1, or 3)
        
        /*
         
         dp[4] = dp[3]
               + dp[2]
               + dp[1]
         
         1,1,1,1
         1,1,2
         1,2,1
         2,1,1
         2,2
         1,3
         3,1
         
         Therefore, dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
         
         */
        
        for (int i=4; i < dp.size(); i++){ // [4:size()-1]
            
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            
            cout << "[" + to_string(i) + "]=" << dp[i] << endl;
        }
    }
};

int main(int argc, const char * argv[]) {

    
    Solution solution;
    
    solution.pathCount(36);
    
    
    return 0;
}




