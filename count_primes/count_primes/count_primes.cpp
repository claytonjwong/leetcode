/*
 
 204. Count Primes
 
 https://leetcode.com/problems/count-primes/description/
 
 Description:
 
 Count the number of prime numbers less than a non-negative number, n.
 
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int countPrimes(int n){
        if (n<=2) return 0;
        int cnt=0;
        vector<bool> nums(n,true);
        nums[0]=nums[1]=false;
        for (int i=2; i<=n; ++i)
            if (nums[i]){
                ++cnt;
                for (int j=2; i*j<n; ++j)
                    nums[i*j]=false;
            }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    while(true){
        int n;
        cout << "n: "; cin >> n;
        cout << s.countPrimes(n) << endl;
    }
    
    
    
    return 0;
}



