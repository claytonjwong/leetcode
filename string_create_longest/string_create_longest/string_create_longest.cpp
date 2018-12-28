/*
 
 720. Longest Word in Dictionary
 
 https://leetcode.com/contest/leetcode-weekly-contest-57/problems/longest-word-in-dictionary/
 
 Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.
 
 If there is no answer, return the empty string.
 Example 1:
 Input:
 words = ["w","wo","wor","worl", "world"]
 Output: "world"
 Explanation:
 The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
 Example 2:
 Input:
 words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 Output: "apple"
 Explanation:
 Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
 Note:
 
 All the strings in the input will only contain lowercase letters.
 The length of words will be in the range [1, 1000].
 The length of words[i] will be in the range [1, 30].
 
 */

/*
 
 Input:
 ["yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"]
 Output:
 "ewqz"
 Expected:
 "yodn"
 
 Input:
 ["rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"]
 Output:
 "onpdu"
 Expected:
 "otif"
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution{
public:
    string longestWord(vector<string>& words){
        auto cmp = [](const string& lhs, const string& rhs){
            if (lhs.size()==rhs.size()) return lhs > rhs;
            return lhs.size() < rhs.size();
        };
        set<string,decltype(cmp)> s(cmp);
        sort(words.begin(),words.end(),cmp);
        for (auto &&word: words){
            if (word.size()==1 || s.count(word.substr(0,word.size()-1))){
                s.insert(word);
            }
        }
        return *max_element(s.begin(),s.end(),cmp);
    }
};

int main(int argc, const char * argv[]) {
    
    //vector<string> dic { "yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y" };
    vector<string> dic { "ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o" };
    Solution solution;
    cout << solution.longestWord(dic) << endl;
    
    
    
    return 0;
}




