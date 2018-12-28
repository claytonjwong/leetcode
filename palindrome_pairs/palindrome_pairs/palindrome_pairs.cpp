/*
 
 336. Palindrome Pairs
 
 https://leetcode.com/problems/palindrome-pairs/description/
 
 Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
 
 Example 1:
 Given words = ["bat", "tab", "cat"]
 Return [[0, 1], [1, 0]]
 The palindromes are ["battab", "tabbat"]
 Example 2:
 Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<vector<int>> res;
        unordered_map<string,unordered_set<int>> pre,post;
        for (int i=0; i<words.size(); ++i){
            for (int k=0; k<=words[i].size(); ++k){
                string beg=words[i].substr(0,k),end=words[i].substr(k);
                string rbeg={beg.rbegin(),beg.rend()},rend={end.rbegin(),end.rend()};
                if (isPalindrome(beg)) post[rend].insert(i);
                if (isPalindrome(end)) pre[rbeg].insert(i);
            }
        }
        for (int j=0; j<words.size(); ++j){
            string w=words[j];
            if (pre.count(w) ) for (auto i: pre[w] ) if (i!=j) res.insert(vector<int>{i,j});
            if (post.count(w)) for (auto i: post[w]) if (i!=j) res.insert(vector<int>{j,i});
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
private:
    bool isPalindrome(const string& s){
        return s==string(s.rbegin(),s.rend());
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution s;
    vector<string> words { "abcd", "dcba", "lls", "s", "sssll" };
    s.palindromePairs(words);
    
    
    return 0;
}







