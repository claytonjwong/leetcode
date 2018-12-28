/*
 
 252. Meeting Rooms
 
 https://leetcode.com/problems/meeting-rooms/description/
 
 
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]],
 return false.
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start{0}, end{0} {}
    Interval(int start, int end) : start{start}, end{end} {}
};



class Solution{
public:
    
    bool canAttendMeetings(vector<Interval>& intervals){
        
        sort(intervals.begin(), intervals.end(), compare);
        
        for (int i=1; i < intervals.size(); i++){
            if (overlap(intervals[i-1], intervals[i])){
                return false;
            }
        }
        
        return true;
    }
    
private:
    
    static bool compare(Interval& a, Interval& b){
        return a.start < b.start;
    }
    
    bool overlap(Interval& a, Interval& b){
        return a.end > b.start;
    }
    
};

int main(int argc, const char * argv[]) {
    
    vector<Interval> intervals {
        Interval(7,10),
        Interval(2,4)
    };
    
    Solution solution;
    cout << solution.canAttendMeetings(intervals) << endl;
    
    
    return 0;
}





