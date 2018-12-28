/*
 
 657. Judge Route Circle
 
 https://leetcode.com/contest/leetcode-weekly-contest-45/problems/judge-route-circle/
 
 Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 
 The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 
 Example 1:
 Input: "UD"
 Output: true
 Example 2:
 Input: "LL"
 Output: false
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        
        //
        // the amount of UP == amount of DOWN
        //
        // AND
        //
        // the amount of LEFT == amount of RIGHT
        //
        int U = (int)count(moves.begin(), moves.end(), 'U');
        int D = (int)count(moves.begin(), moves.end(), 'D');
        int L = (int)count(moves.begin(), moves.end(), 'L');
        int R = (int)count(moves.begin(), moves.end(), 'R');
        
        return U == D && L == R;
        
    }
};


int main(int argc, const char * argv[]) {
   
    Solution solution;

    cout << solution.judgeCircle("RLUURDDDLU");
    
    return 0;
}
