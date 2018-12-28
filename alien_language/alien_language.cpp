/*
 * 953. Verifying an Alien Dictionary
 *
 * Q: https://leetcode.com/problems/verifying-an-alien-dictionary/
 * A: https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/204199/Concise-C%2B%2B
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
    bool isAlienSorted( vector<string>& words, string order, unordered_map<char,char> map={} ){
        for( char i=0; i < order.size(); ++i ) map[ order[i] ] = i;
        for( auto& word: words ) for( auto& c: word ) c = map[ c ];
        return is_sorted( words.cbegin(), words.cend() );
    }
};
*/

class Solution {
public:
    bool isAlienSorted( vector<string>& words, string order, unordered_map<char,char> map={} ){
        for( char i{ 0 }; i < order.size(); ++i ) map[ order[i] ] = i;
        for( auto& word: words ) for_each( word.begin(), word.end(), [&]( char& c ){ c = map[ c ]; });
        return is_sorted( words.cbegin(), words.cend() );
    }
};

/*
class Solution {
public:
    bool isAlienSorted( vector<string>& words, string order, unordered_map<char,char> map={} ){
        for( char i{ 0 }; i < order.size(); ++i ) map[ order[i] ] = i;
        for( auto& word: words ) transform( word.begin(), word.end(), word.begin(), [&]( char& c ){ return map[ c ]; });
        return is_sorted( words.cbegin(), words.cend() );
    }
};
*/

int main() {


    Solution s;
    vector<string> words{ "hello","leetcode" };
    string order{ "hlabcdefgijkmnopqrstuvwxyz" };
    cout << s.isAlienSorted( words, order ) << endl;

    return 0;
}