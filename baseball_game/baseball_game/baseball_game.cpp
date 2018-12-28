/*
 
 682. Baseball Game
 
 https://leetcode.com/contest/leetcode-weekly-contest-51/problems/baseball-game/
 
 You're now a baseball game point recorder.
 
 Given a list of strings, each string can be one of the 4 following types:
 
 Integer (one r's score): Directly represents the number of points you get in this r.
 "+" (one r's score): Represents that the points you get in this r are the sum of the last two valid r's points.
 "D" (one r's score): Represents that the points you get in this r are the doubled data of the last valid r's points.
 "C" (an operation, which isn't a r's score): Represents the last valid r's points you get were invalid and should be removed.
 Each r's operation is permanent and could have an impact on the r before and the r after.
 
 You need to return the sum of the points you could get in all the rs.
 
 Example 1:
 Input: ["5","2","C","D","+"]
 Output: 15
 Explanation:
 r 1: You could get 5 points. The sum is: 5.
 r 2: You could get 2 points. The sum is: 7.
 Operation 1: The r 2's data was invalid. The sum is: 5.
 r 3: You could get 10 points (the r 2's data has been removed). The sum is: 15.
 r 4: You could get 5 + 10 = 15 points. The sum is: 30.
 Example 2:
 Input: ["5","-2","4","C","D","9","+","+"]
 Output: 27
 Explanation:
 r 1: You could get 5 points. The sum is: 5.
 r 2: You could get -2 points. The sum is: 3.
 r 3: You could get 4 points. The sum is: 7.
 Operation 1: The r 3's data is invalid. The sum is: 3.
 r 4: You could get -4 points (the r 3's data has been removed). The sum is: -1.
 r 5: You could get 9 points. The sum is: 8.
 r 6: You could get -4 + 9 = 5 points. The sum is 13.
 r 7: You could get 9 + 5 = 14 points. The sum is 27.
 Note:
 The size of the input list will be between 1 and 1000.
 Every integer represented in the list will be between -30000 and 30000
 
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution{
public:
    int calPoints(vector<string>& ops){
        vector<int> r{};
        for (string& op : ops){
            if      (op=="C"){ r.pop_back(); }
            else if (op=="D"){ r.push_back(2*r.back()); }
            else if (op=="+"){ r.push_back(r.end()[-2]+r.end()[-1]); }
            else             { r.push_back(stoi(op)); }
        }
        return accumulate(r.begin(), r.end(), 0);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    vector<string> test {  };
    cout << solution.calPoints(test) << endl;
    
    
    return 0;
}




