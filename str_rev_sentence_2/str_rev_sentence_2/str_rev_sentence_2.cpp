/*
 
 186. Reverse Words in a String II
 
 https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
 
 Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
 
 The input string does not contain leading or trailing spaces and the words are always separated by a single space.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 Could you do it in-place without allocating extra space?
 
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& str) {
        if (str.empty()) return;
        stringstream in(string(str.begin(),str.end()));
        stack<string> s;
        string word;
        while (getline(in,word,' '))
            s.push(word);
        str.clear();
        while (!s.empty()){
            for (auto c: s.top()) str.push_back(c);
            str.push_back(' ');
            s.pop();
        }
        str.pop_back(); // trailing whitespace
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s; vector<char> str{ 'h','i',' ','h','o','w',' ','a','r','e',' ','y','o','u'};
    cout << "before: ";
    for (auto c: str) cout << c;
    cout << endl;
    s.reverseWords(str);
    cout << "after: ";
    for (auto c: str) cout << c;
    cout << endl;
    return 0;
}


