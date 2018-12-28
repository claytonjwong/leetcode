/*
 
 443. String Compression
 
 Given an array of characters, compress it in-place.
 
 The length after compression must always be smaller than or equal to the original array.
 
 Every element of the array should be a character (not int) of length 1.
 
 After you are done modifying the input array in-place, return the new length of the array.
 
 
 Follow up:
 Could you solve it using only O(1) extra space?
 
 
 Example 1:
 Input:
 ["a","a","b","b","c","c","c"]
 
 Output:
 Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
 
 Explanation:
 "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 Example 2:
 Input:
 ["a"]
 
 Output:
 Return 1, and the first 1 characters of the input array should be: ["a"]
 
 Explanation:
 Nothing is replaced.
 Example 3:
 Input:
 ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 
 Output:
 Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
 
 Explanation:
 Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
 Notice each digit has it's own entry in the array.
 Note:
 All characters have an ASCII value in [35, 126].
 1 <= len(chars) <= 1000.
 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n=(int)chars.size(), write_idx=0, cnt=1;
        if (n<=1) return n;
        for (int i=1; i<n; ++i){
            if (chars[i-1]==chars[i]){
                ++cnt;
            } else {
                write(chars, write_idx, chars[i-1], cnt);
                cnt=1;
            }
        }
        write(chars, write_idx, chars.back(), cnt);
        chars.resize(write_idx);
        return write_idx;
    }

    void write(vector<char>& chars, int& write_idx, char c, int cnt){
        chars[write_idx++]=c;
        if (cnt==1) return;
        string s=to_string(cnt);
        for (int i=0; i<s.size(); ++i){
            chars[write_idx++]=s[i];
        }
    }
};

int main(int argc, const char * argv[]) {
    
    vector<char> chars = { 'a', 'b', 'b' };
    
    Solution solution;
    int sz=solution.compress(chars);
    for (int i=0; i<chars.size(); ++i){
        cout << chars[i];
    }
    cout << endl << "size: " << sz << endl;
    
    
    return 0;
}




