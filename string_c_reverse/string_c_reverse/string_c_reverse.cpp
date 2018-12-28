/*
 
 CCI 12.2 Reverse String: implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.
 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* C-style reverse string */
void reverse(char* str){
    
    if (strlen(str)==0 || strlen(str)==1){
        return;
    }
    
    char* begin = &str[0];
    char* end = &str[strlen(str)-1]; // subtract 1 to keep '\0' at the end
    
    while (begin < end){
        
        char temp = *begin;
        *begin = *end;
        *end = temp;
        
        begin++;
        end--;
    }
}

/* C++ style reverse string */
void reverse(string& str){
    
    reverse(str.begin(), str.end());
}

int main(int argc, const char * argv[]) {
    
    string sstr =  "howdy!";

    /* c++ style */
/*
    vector<char> vstr(sstr.begin(), sstr.end());
    vstr.push_back('\0');
    char* cstr = &vstr[0];
*/
    
    /* C-style */
    char* cstr = new char[sstr.size()+1];
    strlcpy(cstr, sstr.c_str(), sstr.size()+1);
    
    // C
    cout << "Before: " << cstr << endl;
    reverse(cstr);
    cout << "After: " << cstr << endl;

    // C++
    cout << "Before: " << sstr << endl;
    reverse(sstr);
    cout << "After: " << sstr << endl;
    
    delete[] cstr;
    
    return 0;
}




