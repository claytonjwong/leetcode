//
//  main.cpp
//  sliding_puzzle
//
//  Created by Clayton Wong on 11/20/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
    vector<vector<int>> moves { {1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4} };
public:
    int slidingPuzzle( vector<vector<int>>& B, stringstream stream=stringstream(), unordered_set<string> V={} ){
        
        stream << B[ 0 ][ 0 ] << B[ 0 ][ 1 ] << B[ 0 ][ 2 ]
               << B[ 1 ][ 0 ] << B[ 1 ][ 1 ] << B[ 1 ][ 2 ];
        queue<string> q({ stream.str() });
        
        for( size_t d = 0, N = q.size();  ! q.empty();  ++d, N = q.size() ) while( N-- ){
                
            const auto cur = q.front(); q.pop();
            if( cur == "123450" )
                return static_cast< int >( d );
            
            const auto i = cur.find( '0' );
            for( const auto move: moves[ i ] ){
                string next( cur );
                swap( next[ move ], next[ i ] );
                if( V.insert( next ).second )
                    q.push( next );
            }
        }
        
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> board {
        { 3, 2, 4 },
        { 1, 5, 0 }
    };
    Solution s;
    cout << s.slidingPuzzle( board ) << endl;
    
    return 0;
}

