/*
 
 */

#include <iostream>

#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> dic{};
        for (auto c : s){
            if (dic.find(c)==dic.end()){ dic[c]=1; }
            else { dic[c]++; }
        }
        int cnt=0;
        unordered_map<char,int>::iterator itr;
        for (itr=dic.begin(); itr != dic.end(); itr++){
            while(itr->second >= 2){
                cnt+=2;
                itr->second-=2;
            }
        }
        bool single_found=false;
        for (itr=dic.begin(); itr != dic.end(); itr++){
            if (itr->second > 0){
                single_found=true;
                break;
            }
        }
        if (single_found) { cnt++; }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    while (true){
        string str;
        cout << "S: ";
        cin >> str;
        cout <<solution.longestPalindrome(str) << endl << endl;
    }
    
    
    
    
    return 0;
}




