/*
 
 266. Palindrome Permutation
 
 https://leetcode.com/problems/palindrome-permutation/description/
 
 Given a string, determine if a permutation of the string could form a palindrome.
 
 For example,
 "code" -> False, "aab" -> True, "carerac" -> True.
 
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> dic{};
        for (auto c : s){
            if (dic.find(c)==dic.end()){ dic[c]=1; }
            else { dic[c]++; }
        }
        unordered_map<char,int>::iterator itr;
        bool single_found=false;
        for (itr=dic.begin(); itr != dic.end(); itr++){
            if (itr->second%2==1){
                if (single_found) { return false; }
                else { single_found=true; }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    
    while (true){
        string str;
        cout << "S: ";
        cin >> str;
        cout << solution.canPermutePalindrome(str) << endl << endl;
    }
    
    
    return 0;
}



