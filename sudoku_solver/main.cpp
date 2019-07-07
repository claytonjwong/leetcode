#include <vector>
#include <unordered_set>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    using VC = vector< char >;
    using VVC = vector< VC >;
    void solveSudoku( VVC& A ){
        go( A );
    }
private:

    bool go( VVC& A ){
        for( auto i{ 0 }; i < 9; ++i ){
            for( auto j{ 0 }; j < 9; ++j ){
                if( A[ i ][ j ] != '.' )
                    continue;
                for( auto k{ '1' }; k <= '9'; ++k ){
                    A[ i ][ j ] = k;
                    if( ok( A,i,j ) && go( A ) ) return true;
                    A[ i ][ j ] = '.';
                }
                if( A[ i ][ j ] == '.' )
                    return false;
            }
        }
        return true;
    }
    using Unique = unordered_set< char >;
    bool ok( const VVC& A, int i, int j ){
        Unique row, col, box;
        for( auto x{ 0 }; x < 9; ++x ){
            if( A[ i ][ x ] != '.' && ! row.insert( A[ i ][ x ] ).second )
                return false;
            if( A[ x ][ j ] != '.' && ! col.insert( A[ x ][ j ] ).second)
                return false;
        }
        for( auto r = ( i / 3 ) * 3, end_r = r + 3; r < end_r; ++r )
            for( auto c = ( j / 3 ) * 3, end_c = c + 3; c < end_c; ++c )
                if( A[ r ][ c ] != '.' && ! box.insert( A[ r ][ c ] ).second )
                    return false;
        return true;
    }
};

int main() {
    Solution solution;
    Solution::VVC A{
        { '5','3','.',  '.','7','.',  '.','.','.', },
        { '6','.','.',  '1','9','5',  '.','.','.', },
        { '.','9','8',  '.','.','.',  '.','6','.', },
        { '8','.','.',  '.','6','.',  '.','.','3', },
        { '4','.','.',  '8','.','3',  '.','.','1', },
        { '7','.','.',  '.','2','.',  '.','.','6', },
        { '.','6','.',  '.','.','.',  '2','8','.', },
        { '.','.','.',  '4','1','9',  '.','.','5', },
        { '.','.','.',  '.','8','.',  '.','7','9', },
    };
    solution.solveSudoku( A );
    for( auto i{ 0 }; i < 9; ++i, cout << endl )
        copy( A[ i ].begin(), A[ i ].end(), ostream_iterator< char >( cout, "" ) );
    cout << endl;
    return 0;
}
