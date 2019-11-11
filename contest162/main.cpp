#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int oddCells(int M, int N, VVI& A, int odd=0) {
        VVI m(M, VI(N));
        for (auto& cell: A) {
            auto [row, col] = tie(cell[0], cell[1]);
            for (auto i=0; i < M; ++i) ++m[i][col];
            for (auto j=0; j < N; ++j) ++m[row][j];
        }
        for (auto& row: m)
            odd += count_if(row.begin(), row.end(), [](auto x){ return x % 2; });
        return odd;
    }
};


/*

colsum is either 0, 1, 2

case 0: both upper and lower are 0
case 1: either upper is 1 and lower is 0
        xor    upper is 0 and lower is 1
case 2: both upper and lower are 1

the only non-trivial case then is case 1.

for case 1, its an arbitrary and irrelevant choice, what matters is that the amount of case 1 occurrences must be equal to 2x the needs of upper and also must be equal to the 2x the needs of lower, since case 1 is xor.

*/
/*
class Solution {
public:
    using VI = vector<int>;
    using VVI= vector<VI>;
    VVI reconstructMatrix(int upper, int lower, VI& A, VVI NoSolution={}) {
        int N = A.size(),
            total = accumulate(A.begin(), A.end(), 0);
        VVI m(2, VI(N));
        for (auto i=0; i < N; ++i) {
            if (A[i] == 2) {
                m[0][i] = 1, --upper;
                m[1][i] = 1, --lower;
            }
        }
        for (auto i=0; i < N; ++i) {
            if (A[i] == 1) {
                if (upper > 0)
                    m[0][i] = 1, --upper;
                else
                    m[1][i] = 1, --lower;
            }
        }
        return upper == 0 && lower == 0 ? m : NoSolution;
    }
};
*/


/*

basically look for "islands of zeros" which do NOT touch the edges

let's try using union-find + dfs/bfs to create islands

create array P(N+1) as the parent representative of each unique cell (ie. row/col in m who's unique index will be row * 10 + col + 1 (+1 for 1 based index and to make room for 0 parent representative, which represents "not an island"))

iterate through m
    for each 1, set cell value to 0, and set P[index] to 0
    for each 0, set cell value to index, and set P[index] = index (ie. the cell begins its life as a parent representative of itself)

iterate through m again keeping track of seen cells and performing dfs to form islands
if an island touches the edge, then union that cell to the 0 parent reprensentative (ie. "not an island")

iterate through m again and count all cells > 0 to be returned as the answer





hold on that's way harder than i need...


let's just color each island a unique number, if dfs of the island results in an edge touched, then mark that info

create a set of islands (ie. no edge touched)

iterate through rows of m
    ans += the amount of columns in the row who's color is one of the island sets


*/
/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    int closedIsland(VVI& A, Set edge={1}, int ans=0) {
        int M = A.size(),
            N = A[0].size(),
            cand = 2;
        for (auto i=0; i < M; ++i)
            for (auto j=0; j < N; ++j)
                if (A[i][j] == 0)
                    dfs(A, i, j, cand++, edge);
        return cand - edge.size() - 1;
    }
private:
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    void dfs(VVI& A, int i, int j, int color, Set& edge, Seen&& S={}) {
        if (S[i][j] || A[i][j] == 1)
            return;
        S[i][j] = true;
        A[i][j] = color;
        int M = A.size(),
            N = A[0].size();
        if (i == 0 || j == 0 || i == M-1 || j == N-1)
            edge.insert(color);
        if (i-1 >= 0) dfs(A, i-1, j, color, edge, move(S));
        if (j+1 < N)  dfs(A, i, j+1, color, edge, move(S));
        if (i+1 < M)  dfs(A, i+1, j, color, edge, move(S));
        if (j-1 >= 0) dfs(A, i, j-1, color, edge, move(S));
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    cout << solution.closedIsland(A) << endl;
    return 0;
}
*/

int main() {
    return 0;
}