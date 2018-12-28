/*
 
 293. Flip Game
 
 https://leetcode.com/problems/flip-game/description/
 
 You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 
 Write a function to compute all possible states of the string after one valid move.
 
 For example, given s = "++++", after one move, it may become one of the following states:
 
 [
 "--++",
 "+--+",
 "++--"
 ]
 If there is no valid move, return an empty list [].
 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        
        vector<string> result;
        
        for (int i=1; i < s.size(); i++){
            
            string temp = s;
            if ( s[i-1] == '+' && s[i] == '+' ){
                temp[i-1] = '-';
                temp[i] = '-';
                result.push_back(temp);
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {

    
    Solution solution;
    vector<string> result = solution.generatePossibleNextMoves("+-+-");
    
    for (auto s : result){
        cout << s << endl;
    }
    
    return 0;
}





