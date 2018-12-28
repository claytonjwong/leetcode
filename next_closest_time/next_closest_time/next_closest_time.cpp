/*
 
 681. Next Closest Time
 
 https://leetcode.com/contest/leetcode-weekly-contest-51/problems/next-closest-time/
 
 Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
 
 You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
 
 Example 1:
 
 Input: "19:34"
 Output: "19:39"
 Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
 Example 2:
 
 Input: "23:59"
 Output: "22:22"
 Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 
 */

#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        set<char> digits(time.begin(),time.end());
        int hour=stoi(time.substr(0,2)), minute=stoi(time.substr(3,2)); // HH:MM
        auto next=make_pair(hour,minute);                               // 01234
        while(true){
            nextMinute(next);
            char nextTime[6];
            snprintf(nextTime,sizeof(nextTime),"%02d:%02d",next.first,next.second);
            string candidate{nextTime};
            set<char> nextDigits(candidate.begin(),candidate.end());
            if (includes(digits.begin(),digits.end(),
                nextDigits.begin(),nextDigits.end())) { return candidate; }
        }
    }
private:
    void nextMinute(pair<int,int>& t){
        if (++t.second==60){
            t.second=0;
            ++t.first;
        }
        if (t.first==24){
            t.first=0;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    while(true){
        string time;
        cout << "time: ";
        cin >> time;
        cout << solution.nextClosestTime(time) << endl;
    }
    return 0;
}



