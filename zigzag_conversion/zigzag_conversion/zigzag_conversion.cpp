/*
 
 6. ZigZag Conversion
 
 Q: https://leetcode.com/problems/zigzag-conversion/description/
 A: https://leetcode.com/problems/zigzag-conversion/discuss/138880/Concise-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    string convert(string S, int M, vector<string> bucket=vector<string>(1000), string ans="") {
        for (int i=0,d=1,k=1; i<S.size(); ++i,d=(M==1)?0:(k==1)?1:(k==M)?-1:d,k+=d)
            bucket[k].push_back(S[i]);
        return accumulate(bucket.begin(), bucket.end(), ans);
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution s;
    string S="PAYPALISHIRING"; int numRows=1;
    cout << s.convert(S, numRows) << endl;
    
    // PAHNAPLSIIGYIR
    // PAHNAPLSIIGYIR
    
    // PINALSIGYAHRPI
    // PINALSIGYAHRPI
    
    return 0;
}



