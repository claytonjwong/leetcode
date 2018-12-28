/*
 
 357. Count Numbers with Unique Digits
 
 https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 
 Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 
 Example:
 Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        n=min(n,10);
        vector<int> unique{9,8,7,6,5,4,3,2,1};
        vector<int> combos(unique.size()+2,0);
        for (int i=1; i<combos.size()-1; ++i)
            combos[i]=accumulate(unique.begin(), unique.begin()+i, 1, multiplies<int>());
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=10;
        for (int i=2; i<=n; ++i)
            dp[i]=dp[i-1]+(i-1)*combos[i-1]+combos[i];
        return dp[n];
    }
};
*/


/*
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        n=min(n,10);
        int combos[]={0,9,72,504,3024,15120,60480,181440,362880,362880,0};
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=10;
        for (int i=2; i<=n; ++i)
            dp[i]=dp[i-1]+(i-1)*combos[i-1]+combos[i];
        return dp[n];
    }
};
*/

/*
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        n=min(n,10);
        int currAns=0,prevAns=10,prevCombos=9,currCombos=0;
        for (int i=2; i<=n; ++i){
            currCombos=prevCombos*(9-(i-1));
            currAns=prevAns+(i-1)*prevCombos+currCombos;
            prevAns=currAns,prevCombos=currCombos;
        }
        return currAns;
    }
};
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        n=min(n,10);
        int ca=0,cc=0;
        for (int i=2,pc=9,pa=10; i<=n; ++i,pc=cc,pa=ca){
            cc=pc*(9-(i-1));
            ca=pa+(i-1)*pc+cc;
        }
        return ca;
    }
};

/*
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        return
          n==0 ? 1
        : n==1 ? 10
        : n==2 ? 91
        : n==3 ? 739
        : n==4 ? 5275
        : n==5 ? 32491
        : n==6 ? 168571
        : n==7 ? 712891
        : n==8 ? 2345851
        : n==9 ? 5611771
        :        8877691;
    }
};
*/

int main(int argc, const char * argv[]) {
    Solution s;
    for (int n=2; n<=12; ++n){
        cout << s.countNumbersWithUniqueDigits(n) << endl;
    }

    return 0;
}
