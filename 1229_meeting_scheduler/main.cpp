/*

1229. Meeting Scheduler

Q: https://leetcode.com/problems/meeting-scheduler/
A: https://leetcode.com/problems/meeting-scheduler/discuss/414073/Javascript-and-C%2B%2B-solutions

*/

#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

/*

Preprocess slots1 by placing each start/end time into an associative map whose key is the start time and value is the end time.  Iterate through each start/end time in slots2 to see if there is an overlap >= duration.  If so, return the first such occurrence.  If no overlap is found, return an empty array.

for each start/end time in slots1
    m[start] = end
        
for each start/end time in slots2:
    find the lower bound of start in m (ie. a time >= the start time which would potentially overlap)
    calculate the overlap as:
        start = max(slot1 start time, slot2 start time)
        end = min(slot1 end time, slot2 end time)
        if end - start + 1 >= duration
            return { start, start + duration }
return {}
    
example:

    slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]]
    
    overlaps = [10, 15], [60, 70]

*/

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = map<int,int>;
    VI minAvailableDuration(VVI& slots1, VVI& slots2, int duration, Map m1={}, Map m2={}) {
        for (auto& s: slots1) m1[s[0]] = s[1];
        for (auto& s: slots2) m2[s[0]] = s[1];
        for (auto it1=m1.begin(), it2=m2.begin(); it1 != m1.end() && it2 != m2.end(); ) {
            auto beg1 = it1->first, end1 = it1->second,
                 beg2 = it2->first, end2 = it2->second;
            auto max_beg = max(beg1, beg2),
                 min_end = min(end1, end2);
            if (min_end - max_beg >= duration)
                return {max_beg, max_beg + duration};
            if (end1 < end2)
                ++it1;
            else
                ++it2;
        }
        return {};
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI minAvailableDuration(VVI& A, VVI& B, int duration) {
        auto order = [](const VI& lhs, const VI& rhs) { return lhs[0] < rhs[0]; };
        sort(A.begin(), A.end(), order);
        sort(B.begin(), B.end(), order);
        for (auto i=0, j=0; i < A.size() && j < B.size(); ) {
            auto beg1 = A[i][0], end1 = A[i][1],
                 beg2 = B[j][0], end2 = B[j][1];
            auto max_beg = max(beg1, beg2),
                 min_end = min(end1, end2);
            if (min_end - max_beg >= duration)
                return {max_beg, max_beg + duration};
            if (end1 < end2)
                ++i;
            else
                ++j;
        }
        return {};
    }
};

int main() {
//    {
//        Solution::VVI
//            s1{{10,50},{60,120},{140,210}},
//            s2{{0,15},{60,70}};
//        auto d = 8;
//        auto ans = Solution().minAvailableDuration(s1, s2, d);
//        copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
//    }
//    {
//        Solution::VVI
//            s1{{10,50},{60,120},{140,210}},
//            s2{{0,15},{60,70}};
//        auto d = 12;
//        auto ans = Solution().minAvailableDuration(s1, s2, d);
//        copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
//    }
//    {
//        Solution::VVI
//            s1{{0,2}},
//            s2{{1,3}};
//        auto d = 1;
//        auto ans = Solution().minAvailableDuration(s1, s2, d);
//        copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
//    }
    {
        Solution::VVI
            s1{{718384535,736105571},{35095260,90518369},{538071029,603359996},{787143800,805873909},{462350441,473273936},{234081547,361269701},{662315884,691519923},{8448628,21912154},{132574102,138895745},{606910106,652509906}},
            s2{{873692195,883509573},{21185676,36072192},{118230057,131648270},{455946678,460714279},{664875016,747582619},{216100177,376327844},{50846518,110130562},{760997807,780162834},{578554164,634157489},{379022912,418539635}};
        auto d = 673228;
        auto ans = Solution().minAvailableDuration(s1, s2, d);
        copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    }
    return 0;
}