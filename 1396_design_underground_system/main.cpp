#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * 1396. Design Underground System
 *
 * Q3: https://leetcode.com/problems/design-underground-system/
 * A3: https://leetcode.com/problems/design-underground-system/discuss/554805/Javascript-and-C%2B%2B-solutions
 */

//class UndergroundSystem {
//public:
//    void checkIn(int id, string s1, int t1) {
//        notes[id] = {s1, t1};
//    }
//    void checkOut(int id, string s2, int t2) {
//        auto [s1, t1] = notes[id];
//        edges[s1][s2].push_back(t2 - t1); // add edge (s1 👉 s2) with time delta abs(t1 -t2) ⏰
//    }
//    double getAverageTime(string s1, string s2) {
//        return accumulate(edges[s1][s2].begin(), edges[s1][s2].end(), 0.0) / edges[s1][s2].size();
//    }
//private:
//    using Note = tuple<string, int>;
//    using Notes = unordered_map<int, Note>;
//    Notes notes; // { id: { source-station, check-in time }}
//    using Edges = unordered_map<string, unordered_map<string, vector<int>>>;
//    Edges edges; // { source: { destination: { time deltas }}}
//};

class UndergroundSystem {
public:
    void checkIn(int id, string s1, int t1) {
        notes[id] = {s1, t1};
    }
    void checkOut(int id, string s2, int t2) {
        auto [s1, t1] = notes[id];
        auto& [total, cnt] = edges[s1][s2]; // update edge (s1 👉 s2) to include time delta abs(t1 -t2) ⏰
        total += (t2 - t1), ++cnt;
    }
    double getAverageTime(string s1, string s2) {
        auto [total, cnt] = edges[s1][s2];
        return total / cnt;
    }
private:
    using Note = tuple<string, int>;
    using Notes = unordered_map<int, Note>;
    Notes notes; // { id: { source-station, check-in time }}
    using Edge = tuple<double, int>;
    using Edges = unordered_map<string, unordered_map<string, Edge>>;
    Edges edges; // { source: { destination: { total time, count of time entries }}}
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
