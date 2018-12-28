/*
 
 243. Shortest Word Distance
 
 https://leetcode.com/problems/shortest-word-distance/description/
 
 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 
 For example,
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 
 Given word1 = “coding”, word2 = “practice”, return 3.
 Given word1 = "makes", word2 = "coding", return 1.
 
 Note:
 You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int N=(int)words.size(),mini=N;
        for (int i=0,p=-1,q=-1; i<N; ++i){
            bool found=false;
            if (words[i]==word1){ p=i; found=true; }
            if (words[i]==word2){ q=i; found=true; }
            if (found && p>=0 && q>=0)
                mini=min(mini,abs(p-q));
        }
        return mini;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<string> v { "a", "b", "c" };
    string word1="a";
    string word2="c";
    cout << s.shortestDistance(v, word1, word2) << endl;
    
    return 0;
}




