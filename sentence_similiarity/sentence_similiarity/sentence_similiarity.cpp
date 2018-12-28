/*

 734. Sentence Similarity
 
 https://leetcode.com/contest/weekly-contest-60/problems/sentence-similarity/
 
 Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.
 
 For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].
 
 Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.
 
 Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
 
 Note:
 
 The length of words1 and words2 will not exceed 1000.
 The length of pairs will not exceed 2000.
 The length of each pairs[i] will be 2.
 The length of each words[i] and pairs[i][j] will be in the range [1, 20].
 
 */

#include <iostream>
#include <vector>

#define F first
#define S second

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2,
                             vector<pair<string, string>> pairs) {
        if (words1.size()!=words2.size()) return false;
        int m=(int)words1.size(),n=(int)pairs.size();
        for (int i=0; i<m; ++i){
            bool found=false;
            string a=words1[i], b=words2[i];
            if (a==b) continue;
            for (int j=0; j<n; ++j){
                auto p=pairs[j];
                if ( (a==p.F && b==p.S) || (a==p.S && b==p.F) ){
                    found=true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
  
    vector<string> s1 { "good" };
    vector<string> s2 { "good" };
    vector<pair<string,string>> p {
        {"good","bad"},
        {"night","day"},
        {"break","fix"},
    };
    p.clear();
    Solution s;
    cout << s.areSentencesSimilar(s1, s2, p) << endl;
    
    return 0;
}
