#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector< int >;
    void heapsort( VI& A, VI heap={} ){
        for( auto num: A )
            insert( heap, num );
        A.clear();
        for( auto num: heap )
            A.push_back( top( heap ) ), pop( heap );
    }
private:
    void insert( VI& heap, int x ){
        heap.push_back( x );
        auto N = static_cast< int >( heap.size() ),
             i = N-1;
        while( 0 < i && heap[ i ] < heap[ parent( i ) ] ){
            swap( heap[ i ], heap[ parent( i ) ] );
            i = parent( i );
        }
    }
    int top( VI& heap ){
        if( heap.empty() )
            return -1;
        return heap[ 0 ];
    }
    void pop( VI& heap ){
        if( heap.size() < 2 )
            return;
        swap( heap[ 0 ], heap.back() );
        heap.pop_back();
        auto N = static_cast< int >( heap.size() );
        for( auto i{ 0 };; ){
            auto L = numeric_limits< int >::max(),
                 R = numeric_limits< int >::max();
            auto violation{ false };
            if( left_child( i ) < N && heap[ i ] > heap[ left_child( i ) ] ){
                L = heap[ left_child( i ) ];
                violation = true;
            }
            if( right_child( i ) < N && heap[ i ] > heap[ right_child( i ) ] && heap[ right_child( i ) ] < heap[ left_child( i ) ] ){
                R = heap[ right_child( i ) ];
                violation = true;
            }
            if( ! violation )
                break;
            auto j = L < R ? left_child( i ) : right_child( i );
            swap( heap[ i ], heap[ j ] );
            i = j;
        }
    }
    int parent( int i ){
        return ( i-1 ) >> 1;
    }
    int left_child( int i ){
        return ( 2*i ) + 1;
    }
    int right_child( int i ){
        return ( 2*i ) + 2;
    }
};

int main() {
    Solution::VI A{ 4,7,8,0,3,2,1,9,6,5 };
    Solution().heapsort( A );
    copy( A.begin(), A.end(), ostream_iterator< int >( cout, " " ) ); cout << endl;
    return 0;
}
