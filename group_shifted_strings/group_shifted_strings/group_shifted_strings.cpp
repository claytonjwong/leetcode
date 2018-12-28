/*
 
 249. Group Shifted Strings
 
 https://leetcode.com/problems/group-shifted-strings/description/
 
 Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
 
 "abc" -> "bcd" -> ... -> "xyz"
 Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
 
 For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 A solution is:
 
 [
 ["abc","bcd","xyz"],
 ["az","ba"],
 ["acef"],
 ["a","z"]
 ]
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& s) {
        unordered_map<string,vector<string>> m;
        for (auto& x: s)
            m[shiftString(x)].push_back(x);
        vector<vector<string>> res;
        for (auto x: m)
            res.push_back(x.second);
        return res;
    }
private:
    string shiftString(const string& s){
        string res(s);
        int d=res[0]-'a';
        for (int i=0; i<s.size(); ++i) shiftChar(res[i],d);
        return res;
    }
    void shiftChar(char& c, int n){
        int d=c-'a';
        c=(n<=d) ? c-n : 'z'-(n-d-1);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<string> v{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    
    auto res=s.groupStrings(v);
    
    return 0;
}



