/*
 
 500. Keyboard Row
 
 https://leetcode.com/problems/keyboard-row/description/
 
 Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> result;
        
        unordered_map<char, int> dic;
        for (char c : "qwertyuiop"){
            dic[c] = 1;
        }
        for (char c : "asdfghjkl"){
            dic[c] = 2;
        }
        for (char c : "zxcvbnm"){
            dic[c] = 3;
        }
        
        for (string word : words){
            
            if (word.empty()) { continue; }
            
            int i=0;
            int same_row = dic[ tolower(word[0]) ];
            for (char c : word){
                if (dic[ tolower(c) ] != same_row){
                    break;
                }
                i++;
            }
            if (i == word.size()){ // all chars in the same row
                result.push_back(word);
            }
        }
        
        return result;
    }
};

int main(){
    
    vector<string> words { "about", "canada", "query", "POP", "DAD", "alaska" };
    
    Solution solution;
    vector<string> result = solution.findWords(words);
    
    for (auto word : result ){
        cout << word << endl;
    }
    
    return 0;
}
