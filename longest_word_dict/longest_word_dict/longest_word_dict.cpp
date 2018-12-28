/*
 
 720. Longest Word in Dictionary
 
 https://leetcode.com/problems/longest-word-in-dictionary/description/
 
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

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s{""};
        auto sorted=sortByLength(words);
        string maxs;
        for (auto& w: sorted) if (s.count(w.substr(0,w.size()-1))){
            s.insert(w);
            maxs=(w.size()>maxs.size() || (w.size()==maxs.size() && w<maxs)) ? w : maxs;
        }
        return maxs;
    }
private:
    vector<string> sortByLength(vector<string>& w){
        vector<vector<string>> buckets(31,vector<string>()); // maxlen is 30
        for (int i=0; i<w.size(); ++i)
            buckets[w[i].size()].push_back(w[i]);
        vector<string> res;
        for (int i=0; i<buckets.size(); ++i)
            res.insert(res.end(),buckets[i].begin(),buckets[i].end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<string> w { "yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y" };
    cout << s.longestWord(w) << endl;
    
    return 0;
}



