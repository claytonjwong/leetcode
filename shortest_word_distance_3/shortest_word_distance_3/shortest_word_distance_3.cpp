/*
 
 245. Shortest Word Distance III
 
 https://leetcode.com/problems/shortest-word-distance-iii/description/
 
 This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
 
 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 
 word1 and word2 may be the same and they represent two individual words in the list.
 
 For example,
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 
 Given word1 = “makes”, word2 = “coding”, return 1.
 Given word1 = "makes", word2 = "makes", return 3.
 
 Note:
 You may assume word1 and word2 are both in the list.
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string,vector<int>> indexOf;
        int N=(int)words.size(),mini=N;
        for (int i=0; i<N; ++i) indexOf[words[i]].push_back(i);
        for (auto i: indexOf[word1])
            for (auto j: indexOf[word2])
                if (i!=j) mini=min(mini,abs(i-j));
        return mini<N ? mini : 0;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<string> v { "practice", "makes", "perfect", "coding" };
    string word1="makes";
    string word2="makes";
    cout << s.shortestWordDistance(v, word1, word2) << endl;
    
    return 0;
}





