/*
 
 
 */

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution{
public:
    bool isMatch(string& input, string& re){
        return regex_match(input, regex(re) );
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    string in;
    string re;
    while (true){
        
        cout << "Input regex: ";
        cin >> re;
        
        cout << "Input test string: ";
        cin >> in;
        
        cout << endl << endl;
        
        if (solution.isMatch(in, re)){
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    
    return 0;
}



