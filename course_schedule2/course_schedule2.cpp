#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Node
{
    int uniqueId, inCount;
    vector<Node*> neighbors;
    Node ( int id ) : uniqueId{ id }, inCount{ 0 }, neighbors{ } {}
};

using VI = vector<int>;
using VPII = vector<pair<int,int>>;
class Solution
{
public:
    VI findOrder( int N, VPII& P, VI answer = {} )
    {
        vector<Node> nodes;  nodes.reserve( N );
        for ( auto index = 0;  index < N;  ++index )
        {
            nodes.emplace_back( Node{ index } );
        }

        for ( const auto& p: P )
        {
            const auto beforeIndex = p.second, afterIndex = p.first;
            nodes[ beforeIndex ].neighbors.push_back( &nodes[ afterIndex ] );
            ++nodes[ afterIndex ].inCount;
        }

        queue<Node*> q;
        for ( auto& node: nodes )
        {
            if ( node.inCount == 0 )
            {
                q.push( &node );
            }
        }
        while ( !q.empty() && nodes[ q.front()->uniqueId ].inCount == 0 )
        {
            auto currNode = q.front(); q.pop();
            answer.emplace_back( currNode->uniqueId );
            for ( auto& neighborNode: currNode->neighbors )
            {
                if ( --neighborNode->inCount == 0 )
                {
                    q.push( neighborNode );
                }
            }
        }

        return answer.size() == N ? answer : VI{};
    }
};

/*
struct Node {
    int uniqueId, inCount;
    vector<Node*> neighbors;
    Node ( int id ) : uniqueId{ id }, inCount{ 0 }, neighbors{ } {}
};

using VI = vector<int>;
using VPII = vector<pair<int,int>>;
class Solution {
public:
    VI findOrder( int N, VPII& P, VI answer = {} ){
        vector<Node> nodes;  nodes.reserve( N );
        for ( auto index = 0;  index < N;  ++index ) nodes.emplace_back( Node{ index } );

        for ( const auto& p: P ){
            const auto beforeIndex = p.second, afterIndex = p.first;
            nodes[ beforeIndex ].neighbors.push_back( &nodes[ afterIndex ] ), ++nodes[ afterIndex ].inCount;
        }

        queue<Node*> q;  for ( auto& node: nodes ) if ( node.inCount == 0 ) q.push( &node );
        while ( !q.empty() && nodes[ q.front()->uniqueId ].inCount == 0 ){
            auto currNode = q.front(); q.pop();
            answer.emplace_back( currNode->uniqueId );
            for ( auto& neighborNode: currNode->neighbors ) if ( --neighborNode->inCount == 0 ) q.push( neighborNode );
        }

        return answer.size() == N ? answer : VI{};
    }
};
*/

int main()
{
    Solution s;

    VPII preReqs1{ {1,0} };
    auto result1 = s.findOrder( 2, preReqs1 );

    VPII preReqs2{ {1,0}, {2,0}, {3,1}, {3,2} };
    auto result2 = s.findOrder( 4, preReqs2 );

    VPII preReqs3{ {1,0}, {1,2}, {0,1} };
    auto result3 = s.findOrder( 3, preReqs3 );

    return 0;
}