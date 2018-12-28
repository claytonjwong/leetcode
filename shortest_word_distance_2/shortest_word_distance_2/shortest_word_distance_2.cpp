/*
 
 244. Shortest Word Distance II
 
 https://leetcode.com/problems/shortest-word-distance-ii/description/
 
 This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
 
 Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
 
 For example,
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 
 Given word1 = “coding”, word2 = “practice”, return 3.
 Given word1 = "makes", word2 = "coding", return 1.
 
 Note:
 You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i=0; i<words.size(); ++i)
            indexOf[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        if (res.count(word1+word2)) return res[word1+word2];
        int mini=INT_MAX;
        for (auto i: indexOf[word1])
            for (auto j: indexOf[word2])
                mini=min(mini,abs(i-j));
        return res[word1+word2]=res[word2+word1]=mini;
    }
    
private:
    unordered_map<string,vector<int>> indexOf;
    unordered_map<string,int> res;
};

int main(int argc, const char * argv[]) {
    
    vector<string> words {"practice", "makes", "perfect", "coding", "makes"};
    WordDistance wd(words);
    cout << wd.shortest("coding","practice") << endl;
    cout << wd.shortest("makes","coding") << endl;
    cout << wd.shortest("coding","makes") << endl;
    
    return 0;
}
