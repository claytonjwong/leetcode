/*
 * 1360. Number of Days Between Two Dates
 *
 * Q: https://leetcode.com/problems/number-of-days-between-two-dates/
 * A: https://leetcode.com/problems/number-of-days-between-two-dates/discuss/517586/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int daysBetweenDates(string a, string b, int y1 = 0, int m1 = 0, int d1 = 0, int y2 = 0, int m2 = 0, int d2 = 0) {
        vector<int> monthDays{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        for (auto i = 1; i < monthDays.size(); ++i)
            monthDays[i] += monthDays[i - 1];
        a[4] = a[7] = ' ';
        b[4] = b[7] = ' ';
        stringstream ss1{a}, ss2{b};
        ss1 >> y1 >> m1 >> d1;
        ss2 >> y2 >> m2 >> d2;
        auto leapYears = [](auto y, auto m) {
            if (m <= 2)
                --y; // don't count current year if month is Jab/Feb
            return y / 400 + y / 4 - y / 100;
        };
        auto x = (y1 * 365) + d1 + monthDays[m1 - 1] + leapYears(y1, m1),
             y = (y2 * 365) + d2 + monthDays[m2 - 1] + leapYears(y2, m2);
        return abs(x - y);
    }
};
