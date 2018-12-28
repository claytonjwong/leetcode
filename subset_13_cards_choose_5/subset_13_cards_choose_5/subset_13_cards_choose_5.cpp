/*
 
 Given 13 cards, return all unique subsets of 5 cards each
 
 */






/*
 
 public class KSubsetsRecursiveLoop {
 
 public static void main ( String[] args ) {
 new KSubsetsRecursiveLoop();
 }
 
 KSubsetsRecursiveLoop () {
 //--- Initialize the data we're using.
 set = new String[] { "Anna", "Bob", "Carla", "Dennis" };
 n = set.length;
 k = 2;
 
 //--- Now let's have some fun!
 buildSubsets( 0, 0, "" );
 System.out.println();
 }
 
 //----------------------------------------------------------------------
 
 int n, k;
 String[] set;
 
 //----------------------------------------------------------------------
 
 void buildSubsets ( int i, int j, String subset ) {
 //--- Is the subset complete?
 if( j == k ){
 System.out.print( subset + " " );
 return;
 }
 //--- Ok, let's add more.
 for( ; i<n; ++i )
 buildSubsets( i+1, j+1, subset+set[i].charAt(0) );
 }
 }
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

/* generic template for generating nCk recursively */

class KSubsetsRecursiveLoop {
public:
    KSubsetsRecursiveLoop() {
        _set = { "Anna", "Bob", "Carla", "Dennis" };
        _n = (int)_set.size();
        _k = 2;
    }
    
    void buildSubsets(int i, int j, string subset){
        
        if ( j == _k ){
            cout << subset + " | ";
            return;
        }
        
        for ( ; i < _n; i++){
            buildSubsets(i+1, j+1, subset + _set[i][0]);
        }
    }
    
private:
    int _n;
    int _k;
    vector<string> _set;
};


class Solution{
public:
 
    vector<vector<int>> generateSubsets(vector<int> cards, int k){
        
        _cards = cards;
        _n = (int)cards.size();
        _k = k;
        
        buildSubsets(0,0,vector<int>());
        
        return _setList;
    }
    
    void buildSubsets(int i, int j, vector<int> set){
        
        if (j == _k){
            _setList.push_back(set);
            return;
        }
        
        for ( ; i < _n; i++){
            set.push_back(_cards[i]);
            buildSubsets(i+1, j+1, set);
            set.pop_back();
        }
    }
    
private:
    int _n;
    int _k;
    vector<vector<int>> _setList;
    vector<int> _cards;
    
};

int main(int argc, const char * argv[]) {

    
    /*
     
     13C5 = 13 * 12 * 11 * 10 * 9 = 1287 unique subsets
            ---------------------
             1 *  2 *  3 *  4 * 5
     
     choose 1 from 13
     choose 1 from 12 remaining
     choose 1 from 11 remaining
     choose 1 from 10 remaining
     choose 1 from  9 remaining
     
     so we have 13 * 12 * 11 * 10 * 9 = 154440 different ways to choose 5 out of 13
     
     of the 5 choosen, there are 1 * 2 * 3 * 4 * 5 = 120 different ways to order those 5,
     so divide the amount of choices by this number, since the order of sets is irrelevnt
     
     for example, the set of N=2: {1,2} and {2,1} are equivalent
     
     2C1 = 2 * 1 = 2 different ways to choose 1 out of 2 ( either choose the first or second )
           -----
               1
     
     2C2 = 2 * 1 = 1 different way to choose 2 out of 2 ( since {1,2} and {2,1} are equivalent )
           -----
           1 * 2
     
     */
    
    vector<int> cards {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    };
    
    Solution solution;
    vector<vector<int>> result = solution.generateSubsets(cards, 5);
    
    int i=1;
    for ( auto s : result ){
        cout << i++ << ": ";
        cout << "[";
        for ( auto el : s ){
            cout << el << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}




