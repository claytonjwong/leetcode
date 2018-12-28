/*
 
 17. Letter Combinations of a Phone Number
 
 https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons).

 
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res{};
        helper(digits,res);
        return res;
    }
    
private:
    void helper(string s, vector<string>& res){
        while (!s.empty()){
            string letters=to_string(s.back());
            s.pop_back();
            if (res.empty()){
                for (auto& letter : letters){
                    res.push_back(string(1,letter));
                }
            } else {
                vector<string> prev=move(res), curr{};
                for (auto& p : prev){
                    for (auto& letter : letters){
                        curr.push_back(string(1,letter)+p);
                    }
                }
                res=move(curr);
            }
        }
    }
    
    string to_string(const char& c){
        switch(c){
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default:
                return "";
        }
    }
};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    vector<string> result = solution.letterCombinations("123");
    
    for ( auto el : result ){
        cout << el << ",";
    }
    cout << endl;
    
    return 0;
}




