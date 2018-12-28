/*
 
 346. Moving Average from Data Stream
 
 Q: https://leetcode.com/problems/moving-average-from-data-stream/description/
 
 A: https://leetcode.com/problems/moving-average-from-data-stream/discuss/125631/Concise-C++-double-ended-queue-with-accumulate()
 
 */

#include <iostream>
#include <deque>
#include <numeric>

using namespace std;

class MovingAverage {
public:
    MovingAverage(int size) : N{size} {}
    double next(int val) {
        if (q.size()==N)
            q.pop_back();
        q.push_front(val);
        return accumulate(q.begin(),q.end(),0) / (double)q.size();
    }
private:
    deque<int> q;
    int N;
};

int main(int argc, const char * argv[]) {

    MovingAverage ma(3);
    while (true){
        int n;
        cout << "n: "; cin >> n;
        cout << "ma: " << ma.next(n) << endl << endl;
    }
    
    
    
    return 0;
}



