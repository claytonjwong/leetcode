/*
 
 https://leetcode.com/contest/weekly-contest-110

 Rank           Name            Score    Finish Time    Q1 (4)         Q2 (4)    Q3 (5)    Q4 (7)
 1550 / 3720    claytonjwong    8        1:04:48        0:45:03  *1    0:59:48
 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//
//class Log {
//    string id, words, to_string_value;
//public:
//    Log( const string& log, string word={} ) : to_string_value{ log } {
//        stringstream stream{ log };
//        for(  stream >> id;  stream >> word;  words.append( word + " " )  );
//        words.pop_back(); // final trailing whitespace
//    }
//    bool isLetter() const { return isalpha( words[0] ); }
//    const string& to_string() const { return to_string_value; }
//    const string& getWords() const { return words; }
//    const string& getID() const { return id; }
//};
//using VS = vector< string >;
//using VL = vector< Log >;
//class Solution {
//public:
//    VS reorderLogFiles( VS& logs, VL letters={}, VL digits={}, VS result={} ){
//        for( const auto& log: logs ){
//            Log sample{ log };
//            sample.isLetter()  ?  letters.emplace_back( sample )  :  digits.emplace_back( sample );
//        }
//        sort( letters.begin(), letters.end(), []( const Log& lhs, const Log& rhs ){
//            return lhs.getWords() == rhs.getWords() ? lhs.getID() < rhs.getID() : lhs.getWords() < rhs.getWords();
//        });
//        for( const auto& log: letters ) result.emplace_back( log.to_string() );
//        for( const auto& log: digits ) result.emplace_back( log.to_string() );
//        return result;
//    }
//};

//class Solution {
//public:
//    vector<string> reorderLogFiles( vector<string>& logs ){
//        auto pivot = stable_partition( logs.begin(), logs.end(), []( const auto& log ){ return isalpha( log.back() ); });
//        sort( logs.begin(), pivot, []( const auto& lhs, const auto& rhs ){
//            auto i = lhs.find_first_of(' '), j = rhs.find_first_of(' ');
//            return lhs.substr( i ) == rhs.substr( j ) ? lhs.substr( 0, i ) < rhs.substr( 0, j ) : lhs.substr( i ) < rhs.substr( j );
//        });
//        return logs;
//    }
//};


/*
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using VI = vector< int >;
using VI_it = VI::const_iterator;
class Solution {
    void go( TreeNode* root, VI* const collection ){
        if( root->left ) go( root->left, collection );
        collection->push_back( root->val );
        if( root->right ) go( root->right, collection );
    }
public:
    int rangeSumBST(TreeNode* root, int L, int R, VI sorted={}, VI_it L_it={}, VI_it R_it={} ) {
        if( ! root ) return 0;
        go( root, &sorted );
        for( auto it=sorted.begin();  it != sorted.end();  ++it ){
            if( *it == L ) L_it = it;
            if( *it == R ) R_it = it;
        }
        return accumulate( L_it, R_it + 1, 0 );
    }
};
*/


//struct TreeNode {
//    int val;
//    TreeNode *left, *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//    int go( TreeNode* root, const int L, const int R, int sum=0 ){
//        if( root->left ) sum += go( root->left, L, R );
//        sum += ( L <= root->val && root->val <= R ) ? root->val : 0;
//        if( root->right ) sum += go( root->right, L, R );
//        return sum;
//    }
//public:
//    int rangeSumBST(TreeNode* root, int L, int R ) {
//        return root ? go( root, L, R ) : 0;
//    }
//};

//struct TreeNode {
//    int val;
//    TreeNode *left, *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
//    int rangeSumBST(TreeNode* root, int L, int R, int sum=0 ) {
//        if( ! root ) return 0;
//        sum += rangeSumBST( root->left, L, R );
//        sum += ( L <= root->val && root->val <= R ) ? root->val : 0;
//        sum += rangeSumBST( root->right, L, R );
//        return sum;
//    }
//};


//struct TreeNode {
//    int val;
//    TreeNode *left, *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//    int go( TreeNode* root, const int L, const int R, int sum=0 ){
//        return root
//            ?
//             root->left ? go( root->left, L, R ) : 0
//             + L <= root->val && root->val <= R ? root->val : 0
//             + root->right ? go( root->right, L, R ) : 0
//            : 0;
//    }
//public:
//    int rangeSumBST(TreeNode* root, int L, int R, int ans=0 ) {
//        return go( root, L, R );
//    }
//};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int rangeSumBST( TreeNode* root, int L, int R ){
        return root ? rangeSumBST( root->left, L, R)
                    + rangeSumBST( root->right, L, R )
                    + ( L <= root->val && root->val <= R ? root->val : 0 ) : 0;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
//    VS logs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
//    vector<string> logs = { "a same same same", "c same same same", "b same same same" };
//    auto result = s.reorderLogFiles( logs );
    

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(18);

    auto result = s.rangeSumBST(root, 7, 15);
    
    
    return 0;
}









