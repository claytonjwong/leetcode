/*
 
 3. Longest Substring Without Repeating Characters
 
 https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 */

#include <iostream>
#include <set>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        set<char> unique{};
        int max_len=0,i=0,j=0;
        while(j<s.size()){
            char ch=s[j];
            if (unique.find(ch)==unique.end()){
                ++j;
                unique.insert(ch);
            } else {
                max_len=max(max_len,j-i);
                ++i;
                j=i;
                unique.clear();
            }
        }
        max_len=max(max_len,j-i);
        
        return max_len;
    }
    
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    //             012345
    string test = "pwwkew";
    
    cout << "3 == " << solution.lengthOfLongestSubstring(test) << endl;
    
    
    
    
    return 0;
}




