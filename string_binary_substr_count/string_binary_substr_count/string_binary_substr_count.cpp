/*
 
 696. Count Binary Substrings
 
 https://leetcode.com/contest/leetcode-weekly-contest-54/problems/count-binary-substrings/
 
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
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 0;
        vector<int> chunks{};
        char curr=s[0];
        int res=0, cnt=1;
        for (int i=1; i<s.size(); ++i){
            if (s[i]==curr){
                ++cnt;
            } else {
                chunks.push_back(cnt);
                cnt=1;
                curr=s[i];
            }
        }
        chunks.push_back(cnt);
        for (int i=1; i<chunks.size(); ++i){
            res+=min(chunks[i-1],chunks[i]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    cout << solution.countBinarySubstrings("0011100") << endl;
    
    
    return 0;
}




