#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector< int >;
    void quicksort( VI& A ){
        go( A, 0, A.size() );
    }
private:
    void go( VI& A, int L, int R ){
        if( R-L < 2 )
            return;
        int pivot = partition( A, L, R );
        go( A, L, pivot );
        go( A, pivot + 1, R );
    }
    int partition( VI &A, int L, int R ){
        auto p = A[ L ],
             i = L + 1;
        for( auto j{ i }; j < R; ++j )
            if( A[ j ] < p )
                swap( A[ i++ ], A[ j ] );
        swap( A[ L ], A[ i-1 ] );
        return i-1;
    }
};

int main() {
    Solution::VI A{ 6,1,4,2,7,3,9,0,5,4,8 };
    Solution().quicksort( A );
    copy( A.begin(), A.end(), ostream_iterator< int >( cout, " " ) ); cout << endl;
    return 0;
}
