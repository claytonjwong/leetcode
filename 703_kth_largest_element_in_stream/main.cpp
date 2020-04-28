/*
 * 703. Kth Largest Element in a Stream
 *
 * Q: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * A: https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/600499/C%2B%2B-multiset
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class KthLargest {
public:
    using VI = vector<int>;
    using Set = multiset<int>;
    KthLargest(int K, VI& A) : K{ K } {
        int N = A.size();
        sort(A.begin(), A.end()),
        S.insert(A.rbegin(), A.rbegin() + min(K, N));
    }
    int add(int x) {
        if (S.size() == K && x > *S.begin())
            S.erase(S.begin());
        if (S.size() < K)
            S.insert(x);
        return *S.begin();
    }
private:
    int K;
    Set S;
};

int main() {
    KthLargest::VI A{ 0 };
    KthLargest solution{2, A};
    cout << solution.add(-1) << endl;
    cout << solution.add(1) << endl;
    cout << solution.add(-2) << endl;
    cout << solution.add(-4) << endl;
    cout << solution.add(3) << endl;
    return 0;
}
