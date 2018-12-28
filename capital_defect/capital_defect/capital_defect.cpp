/*
 
 520. Detect Capital
 
 https://leetcode.com/problems/detect-capital/description/
 
 Given a word, you need to judge whether the usage of capitals in it is right or not.
 
 We define the usage of capitals in a word to be right when one of the following cases holds:
 
 All letters in this word are capitals, like "USA".
 All letters in this word are not capitals, like "leetcode".
 Only the first letter in this word is capital if it has more than one letter, like "Google".
 Otherwise, we define that this word doesn't use capitals in a right way.
 Example 1:
 Input: "USA"
 Output: True
 Example 2:
 Input: "FlaG"
 Output: False
 Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 
 */


#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for_each(word.begin(),word.end(),[&](char c){ if (isupper(c)) ++cnt; });
        return cnt==0 || cnt==word.size() || (cnt==1 && isupper(word[0]));
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    while(true){
        string word;
        cin >> word;
        cout << s.detectCapitalUse(word) << endl;
    }
    
    
    return 0;
}




