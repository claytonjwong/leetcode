/*

 921. Minimum Add to Make Parentheses Valid

 Q: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 A: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/discuss/182255/Concise-C%2B%2B

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int minAddToMakeValid( string A, vector<char> stack={}, int ans=0 ){
        for( const auto c: A ){
            if( c == '(' ){
                stack.push_back(c);
            }else{
                if( ! stack.empty()  &&  stack.back() == '(' ){
                    stack.pop_back();
                }else{
                    ++ans;
                }
            }
        }
        return ans + stack.size();
    }
};
*/

class Solution {
public:
    int minAddToMakeValid( string A, vector<char> stack={}, int ans=0 ){

        for( const auto c: A )

            if( c == '(' )
                stack.push_back(c);

            else if( ! stack.empty()  &&  stack.back() == '(' )
                stack.pop_back();

            else
                ++ans;

        return ans + static_cast< int >( stack.size() );
    }
};


int main() {



    return 0;
}