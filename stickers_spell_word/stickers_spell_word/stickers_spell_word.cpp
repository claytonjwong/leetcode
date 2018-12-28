/*
 
 691. Stickers to Spell Word
 
 https://leetcode.com/contest/leetcode-weekly-contest-53/problems/stickers-to-spell-word/
 
 We are given N different types of stickers. Each sticker has a lowercase English word on it.
 
 You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.
 
 You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
 
 What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.
 
 Example 1:
 
 Input:
 
 ["with", "example", "science"], "thehat"
 Output:
 
 3
 Explanation:
 
 We can use 2 "with" stickers, and 1 "example" sticker.
 After cutting and rearrange the letters of those stickers, we can form the target "thehat".
 Also, this is the minimum number of stickers necessary to form the target string.
 Example 2:
 
 Input:
 
 ["notice", "possible"], "basicbasic"
 Output:
 
 -1
 Explanation:
 
 We can't form the target "basicbasic" from cutting letters from the given stickers.
 Note:
 
 stickers has length in the range [1, 50].
 stickers consists of lowercase English words (without apostrophes).
 target has length in the range [1, 15], and consists of lowercase English letters.
 In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
 The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
private:
    vector<int> to_vector(const string &s){
        vector<int> res(26, 0);
        for (auto&& ch : s) ++res[ch-'a']; // one vector index per char [a:z]
        return res;
    }
    
    string applySticker(const vector<int>& sticker, const vector<int>& target){
        string res{};
        for (int i=0; i < target.size(); ++i){ // for each char position
            if (target[i] && sticker[i]){
                int leftovers=target[i]-sticker[i];
                if (leftovers > 0) res+=string(leftovers,i+'a'); // apply char, keep leftovers
            }
            else if (target[i]) res+=string(target[i],i+'a'); // char NOT applied
        }
        return res; // alphabetically sorted target MINUS common chars from applying sticker
    }
    
    int getMinStickersToCreateTarget(const vector<string>& stickers,
        const string& target, unordered_map<string,int>& hash){
        if (hash.count(target)) return hash[target]; // base case 1
        int minCnt=INT_MAX;
        vector<int> vt=to_vector(target);
        for (int i=0; i<stickers.size(); ++i){ // iterative backtracking
            vector<int> vs=to_vector(stickers[i]);
            string next_target=applySticker(vs,vt);
            if (next_target.size() < target.size()){ // recursive constraint
                int currCnt=getMinStickersToCreateTarget(stickers,next_target,hash);
                if (currCnt!=-1) minCnt=min(minCnt,currCnt+1); // +1 sticker applied
            }
        }
        return hash[target]=minCnt==INT_MAX ? -1 : minCnt; // base case 2
    }
    
public:
    int minStickers(vector<string>& stickers, string target) {
        unordered_map<string,int> hash({{"",0}});
        return getMinStickersToCreateTarget(stickers,target,hash);
    }
};



int main(int argc, const char * argv[]) {
    
    Solution solution;
    string target="thehat";
    vector<string> vs{"with","example","science"};
    cout << solution.minStickers(vs,target) << endl;

    
    
    
    return 0;
}



