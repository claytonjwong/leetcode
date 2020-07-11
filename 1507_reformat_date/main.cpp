/*
 * 1507. Reformat Date
 *
 * Q: https://leetcode.com/problems/reformat-date/
 * A: https://leetcode.com/problems/reformat-date/discuss/730585/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string reformatDate(string date, string d = {}, string m = {}, string y = {}) {
        istringstream is{ date };
        is >> d >> m >> y;
        d = d.substr(0, d.size() - 2);
        if (d.size() == 1)
            d = "0" + d;
        if (m == "Jan") m = "01";
        if (m == "Feb") m = "02";
        if (m == "Mar") m = "03";
        if (m == "Apr") m = "04";
        if (m == "May") m = "05";
        if (m == "Jun") m = "06";
        if (m == "Jul") m = "07";
        if (m == "Aug") m = "08";
        if (m == "Sep") m = "09";
        if (m == "Oct") m = "10";
        if (m == "Nov") m = "11";
        if (m == "Dec") m = "12";
        return y.append("-").append(m).append("-").append(d);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
