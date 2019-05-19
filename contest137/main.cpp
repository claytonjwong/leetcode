/*

Rank	        Name	        Score	Finish Time 	Q1 (3)	    Q2 (4)	    Q3 (6)  	Q4 (6)
1433 / 4091	    claytonjwong 	7	    0:12:16	        0:07:13	    0:12:16

 */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int lastStoneWeight( vector< int >& s ){
        while( 1 < s.size() ){
            sort( s.begin(), s.end() );
            auto N = s.size();
            auto a = s[ N-2 ],
                 b = s[ N-1 ],
                 c = b - a;
            s.pop_back(), s.pop_back();
            if( 0 < c )
                s.push_back( c );
        }
        return s.empty()? 0 : s.back();
    }
};
*/

/*
class Solution {
public:
    using Stack = vector< char >;
    using Word = string;
    Word removeDuplicates( Word W, Stack S={} ){
        for( auto c: W )
            if( ! S.empty() && c == S.back() )
                S.pop_back();
            else
                S.push_back( c );
        return{ S.begin(), S.end() };
    }
};
*/

bool is_predecessor(const string &a, const string &b) {
    if (a.size() + 1 != b.size())
        return false;

    int n = a.size();

    for (int i = 0; i <= n; i++)
        if (a == b.substr(0, i) + b.substr(i + 1))
            return true;

    return false;
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        vector<vector<bool>> can(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                can[i][j] = is_predecessor(words[i], words[j]);

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (can[j][i])
                    dp[i] = max(dp[i], dp[j] + 1);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

