/*

 Q: https://leetcode.com/problems/reverse-words-in-a-string/

*/

#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords( string &A, string word={}, vector<string> words={} ) {
        for( istringstream stream{ A };  stream >> word;  words.push_back( word ) );
        A.clear();
        for_each( words.rbegin(), words.rend(), [&]( const auto& word ){  A.append( word ).append(" ");  });
        A.pop_back();
    }
};

int main(){
    Solution s;
    string A="hi there how are you?";
    s.reverseWords( A );
    cout << "'" << A << "'" << endl;
}