/*
 
 748. Shortest Completing Word
 
 https://leetcode.com/contest/weekly-contest-63/problems/shortest-completing-word/
 
 Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate
 
 Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.
 
 It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.
 
 The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.
 
 Example 1:
 Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
 Output: "steps"
 Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
 Note that the answer is not "step", because the letter "s" must occur in the word twice.
 Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
 Example 2:
 Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
 Output: "pest"
 Explanation: There are 3 smallest length words that contains the letters "s".
 We return the one that occurred first.
 Note:
 licensePlate will be a string with length in range [1, 7].
 licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
 words will have a length in the range [10, 1000].
 Every words[i] will consist of lowercase letters, and have length in range [1, 15].
 
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int min_idx=-1;
        vector<map<char,int>> alpha_counts{};
        auto target=createMap(licensePlate);
        for (auto &&word: words){
            auto m=createMap(word);
            alpha_counts.push_back(m);
        }
        for (int i=0; i<words.size(); ++i){
            if (isSubset(target, alpha_counts[i])){
                if (min_idx==-1 || words[i].size()<words[min_idx].size())
                    min_idx=i;
            }
        }
        return words[min_idx];
    }
private:
    map<char,int> createMap(string& s){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        map<char,int> m{};
        for (auto &&c: s)
            if (isalpha(c))
                if (m.find(c)==m.end()){
                    m[c]=1;
                }else{
                    ++m[c];
                }
        return m;
    }
    bool isSubset(map<char,int>& a, map<char,int>& b){
        for (auto &&x: a){
            char c=x.first;
            int n=x.second;
            if (b.find(c)==b.end())
                return false;
            else
                if (n>b[c])
                    return false;
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
