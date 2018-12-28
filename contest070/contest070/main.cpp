/*
 
 https://leetcode.com/contest/weekly-contest-70
 
 */

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        return __builtin_popcount(K-1)%2;
    }
};


int main(int argc, const char * argv[]) {
    
    
    
    Solution s;
    int k;
    while(true){
        cout << "k: "; cin >> k;
        cout << s.kthGrammar(0, k) << endl;
    }
    
    
    
    return 0;
}







