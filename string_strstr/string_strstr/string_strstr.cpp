/*
 
 
 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        vector<int> matching_hash_index;
        
        // sanity checks
        if (haystack.size() == 0 && needle.size() == 0){
            return 0;
        }
        if (needle.size() > haystack.size()){
            return -1;
        }
        
        
        // calculate hash for each position in haystack,
        // go through the hashes that match to check for string comparison
        int needle_hash=0;
        int haystack_hash=0;
        for (int i=0; i < needle.size(); i++){
            needle_hash += char(needle[i]);
            haystack_hash += char(haystack[i]);
        }
        
        int i=needle.size();
        while (true){
            
            if (haystack_hash == needle_hash){
                matching_hash_index.push_back( i - needle.size() );
            }
            
            // increment until no more needles can fit in the end of the haystack
            if ( i == (int)haystack.size() ){
                break;
            }
            
            // calculate next index's hash using sliding window
            haystack_hash = haystack_hash - haystack[i-needle.size()] + haystack[i];
            
            i++;
        }
        
        for (int index : matching_hash_index ){
            
            if (sameStr(&haystack[index],needle)){
                return index;
            }
        }
        return -1;
        
    }
    
    bool sameStr(string s1, string s2){
        
        int size = (int)min( s1.size(), s2.size() );
        
        for (int i=0; i < size; i++){
            if (s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
    
    
};

int main(int argc, const char * argv[]) {

    
    Solution solution;
    
    string haystack = "misisissippi";
    string needle = "issi";
    
    cout << "0 == " << solution.strStr(haystack, needle) << endl << endl;
    
    return 0;
}










