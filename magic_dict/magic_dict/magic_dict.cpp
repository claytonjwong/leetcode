/*
 
 676. Implement Magic Dictionary
 
 https://leetcode.com/contest/leetcode-weekly-contest-49/problems/implement-magic-dictionary/
 
 Implement a magic directory with buildDict, and search methods.
 
 For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.
 
 For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.
 
 Example 1:
 Input: buildDict(["hello", "leetcode"]), Output: Null
 Input: search("hello"), Output: False
 Input: search("hhllo"), Output: True
 Input: search("hell"), Output: False
 Input: search("leetcoded"), Output: False
 Note:
 You may assume that all the inputs are consist of lowercase letters a-z.
 For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.
 Please remember to RESET your class variables declared in class MagicDictionary, as static/class variables are persisted across multiple test cases. Please see here for more details.
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() : hash{} {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        hash.clear();
        for (auto s : dict){
            hash[s]=HashVal(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals
     the given word after modifying exactly one character */
    bool search(string word) {
        int target=HashVal(word);
        unordered_map<string,int>::iterator itr;
        for (itr=hash.begin(); itr != hash.end(); itr++){
            if (abs(itr->second - target) < 'z' - 'a' + 1){
                if (OffByOne(itr->first, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    
    int HashVal(string s){
        int val=0;
        for (auto c : s){ val+=c-'a'; }
        return val;
    }
    
    bool OffByOne(string a, string b){
        if (a.size() != b.size()) { return false; }
        bool diff_found=false;
        for (int i=0; i < a.size(); i++){
            if (a[i] != b[i]){
                if (diff_found) { return false; }
                else { diff_found=true; }
            }
        }
        return diff_found ? true : false;
    }
    
    unordered_map<string,int> hash;
    
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main(int argc, const char * argv[]) {

    vector<string> input { "hello","leetcode", "allow" };
    MagicDictionary magic_dic;
    magic_dic.buildDict(input);
    
    while (true){
        string target;
        cout << "Search: ";
        cin >> target;
        cout << magic_dic.search(target) << endl << endl;
    }
    
    return 0;
}




