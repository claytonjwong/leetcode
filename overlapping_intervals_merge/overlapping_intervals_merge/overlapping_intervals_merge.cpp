/*
 
 56. Merge Intervals
 
 https://leetcode.com/problems/merge-intervals/description/
 
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 
 */

#include <iostream>
#include <vector>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> res;
        if (intervals.empty()) { return res; }
        
        // sort by beginning in ascending order
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) { return a.start < b.start;});
        
        //
        // if there is overlap between curr/next, make curr's end the max end between curr/next
        // curr is res.back() and next is intervals[next]
        //
        res.push_back(intervals[0]); // curr
        for (int next=1; next < intervals.size(); next++){
            
            if (res.back().end < intervals[next].start) { // no overlap, keep interval "as is"
                
                res.push_back(intervals[next]);
                
            } else { // overlap, update curr's end to the largest end between curr/next
                     // in order to "merge" these overlapping intervals
                
                res.back().end = max( res.back().end, intervals[next].end );
                
            }
        }
        
        return res;
    }
};



int main(int argc, const char * argv[]) {

    vector<Interval> intervals {
        Interval(7,10),
        Interval(0,4),
        Interval(1,5)
    };
    
    Solution solution;
    vector<Interval> result = solution.merge(intervals);
    
    
    return 0;
}




