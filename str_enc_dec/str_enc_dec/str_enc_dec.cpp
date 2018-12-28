/*
 
 271. Encode and Decode Strings
 
 https://leetcode.com/problems/encode-and-decode-strings/description/
 
 Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 
 Machine 1 (sender) has the function:
 
 string encode(vector<string> strs) {
 // ... your code
 return encoded_string;
 }
 Machine 2 (receiver) has the function:
 vector<string> decode(string s) {
 //... your code
 return strs;
 }
 So Machine 1 does:
 
 string encoded_string = encode(strs);
 and Machine 2 does:
 
 vector<string> strs2 = decode(encoded_string);
 strs2 in Machine 2 should be the same as strs in Machine 1.
 
 Implement the encode and decode methods.
 
 Note:
 The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
 Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
 Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
 
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;


class Codec {
public:
    string encode(vector<string>& strs) {
        string res;
        for (auto& s: strs) res+=s+ESC;
        return res;
    }
    vector<string> decode(string str) {
        vector<string> res;
        stringstream ss(str);
        for (string curr; getline(ss,curr,ESC);) res.push_back(curr);
        return res;
    }
private:
    const char ESC='\0';
};


/*
class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto& s: strs){
            res+=to_string(s.size())+ESC+s;
        }
        return res;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string str) {
        vector<string> res;
        stringstream ss(str);
        for (int size; ss >> size;){
            auto curr=unique_ptr<char[]>(new char[size]);
            ss.read(curr.get(),1); // ESC
            ss.read(curr.get(),size);
            res.push_back(string(curr.get()));
        }
        return res;
    }
private:
    const string ESC="/";
};
*/

int main(int argc, const char * argv[]) {
    
    Codec c; vector<string> v{ "a", "b", "c" };
    string s=c.encode(v);
    auto res=c.decode(s);
    
    
    return 0;
}



