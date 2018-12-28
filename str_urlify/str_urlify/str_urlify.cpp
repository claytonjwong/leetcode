/*
 
 Write a method to replace all spaces in a string with '%20'
 and remove all trailing spaces on the right hand side of the string
 
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    void urlify(string& str){
        
        // rtrim whitespace
        int trim_index = (int)str.find_last_not_of(" ");
        str = str.substr(0, trim_index+1); // [0:trim_index]
        
        // replace all other whitespaces with "%20"
        int space_index = str.find(' ');
        while (space_index > 0){
            
            str.replace(space_index, 1, "%20");
            
            space_index = str.find(' ');
        }

    }
};



int main(int argc, const char * argv[]) {
    
    string test = "mr john smith    ";
    
    Solution solution;
    
    solution.urlify(test);
    
    cout << ("mr%20john%20smith" == test) << ": \"" << test << "\"" << endl;
    
    return 0;
}
