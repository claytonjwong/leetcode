/*
 
 91. Decode Ways
 
 https://leetcode.com/problems/decode-ways/description/
 
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.
 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // TODO
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    while (true){
        string s;
        cout << "s: "; cin >> s;
        cout << solution.numDecodings(s) << endl;
    }
    
    
    
    return 0;
}




