/*
 
 696. Count Binary Substrings
 
 https://leetcode.com/problems/count-binary-substrings/description/
 
 Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
 
 Substrings that occur multiple times are counted the number of times they occur.
 
 Example 1:
 Input: "00110011"
 Output: 6
 Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 
 Notice that some of these substrings repeat and are counted the number of times they occur.
 
 Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
 Example 2:
 Input: "10101"
 Output: 4
 Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 Note:
 
 s.length will be between 1 and 50,000.
 s will only consist of "0" or "1" characters.
 
 */

#include <iostream>

using namespace std;

/*
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        char currVal=s[0],prevVal;
        int currCnt=1,prevCnt=0;
        for (int i=1; i<s.size(); ++i){
            if (s[i]==currVal){
                ++currCnt;
                continue;
            }
            if (prevCnt)
                cnt+=min(currCnt,prevCnt);
            prevVal=currVal;
            prevCnt=currCnt;
            currVal=s[i];
            currCnt=1;
        }
        return cnt+min(currCnt,prevCnt);
    }
};
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        char same=s[0];
        int curr=1,prev=0;
        for (int i=1; i<s.size(); ++i){
            if (s[i]==same){
                ++curr;
                continue;
            }
            cnt+=min(curr,prev);
            prev=curr;
            same=s[i];
            curr=1;
        }
        return cnt+min(curr,prev);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    string str("00110011");
    cout << s.countBinarySubstrings(str) << endl;
    
    return 0;
}




