/*
 
 535. Encode and Decode TinyURL
 
 https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 
 Note: This is a companion problem to the System Design problem: Design TinyURL.
 TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
 
 Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL
 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
    
    Solution() : seed{0}, tiny_url_base{"http://tinyurl.com/"} {}
    
    
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        map[seed] = longUrl;
        return tiny_url_base + to_string(seed++);
    }
    
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        string valueAfter = "";
        for (int i=(int)tiny_url_base.size(); i < (int)shortUrl.size(); i++){
            valueAfter += shortUrl[i];
        }
        
        int index = stoi(valueAfter);
        
        return map[index];
    }
    
private:
    const string tiny_url_base;
    int seed;
    unordered_map<int, string> map;
};



int main(int argc, const char * argv[]) {

    Solution solution;
    
    string encoded = solution.encode("www.cnn.com");
    cout << solution.decode(encoded) << endl;
    
    
    return 0;
}





