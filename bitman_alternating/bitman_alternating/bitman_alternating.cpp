/*
 
 693. Binary Number with Alternating Bits
 
 https://leetcode.com/contest/leetcode-weekly-contest-53/problems/binary-number-with-alternating-bits/
 
 Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
 
 Example 1:
 Input: 5
 Output: True
 Explanation:
 The binary representation of 5 is: 101
 
 Example 2:
 Input: 7
 Output: False
 Explanation:
 The binary representation of 7 is: 111.
 
 Example 3:
 Input: 11
 Output: False
 Explanation:
 The binary representation of 11 is: 1011.
 
 Example 4:
 Input: 10
 Output: True
 Explanation:
 The binary representation of 10 is: 1010.
 */

#include <iostream>
#include <regex>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n){
            if ((n&1)==((n&2)>>1)) return false;
            n>>=1;
        }
        return true;
    }
};


class Solution1 {
public:
    bool hasAlternatingBits(int n) {
        n+=(n>>1)+1;
        return (n&(n-1))==0;
    }
};



class Solution2 {
public:
    bool hasAlternatingBits(int n) {
        return regex_match(bitset<32>(n).to_string(),regex("(0)*(10)*1{0,1}"));
    }
};



class Solution3 {
public:
    bool hasAlternatingBits(int n) {
        bool last=(n&1);
        return n==0 ? false : helper(n,!last);
    }
    
    bool helper(int n, bool last){
        return n==0 ? last==true : (n&1)==last ? false : helper(n>>1,!last);
    }
    
};


class Solution4 {
public:
    bool hasAlternatingBits(int n) {
        if (n==0) return false;
        bool last=n&1;
        while(n>>=1 > 0){
            if ((n&1)==last) return false;
            last=!last;
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    
    while(true){
        cout << "n: ";
        int n;
        cin >> n;
        cout << solution.hasAlternatingBits(n) << endl;
    }
    
    return 0;
}
