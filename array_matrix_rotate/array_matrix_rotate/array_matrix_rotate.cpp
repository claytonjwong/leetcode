/*
 
 Given a NxN matrix, rotate it counter clockwise 90 degrees in place
 
 
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    static void rotate(vector<vector<int>>& m){
        
        // rotate from the outside inwards, no rotations are performed for size 0 or 1
        int first = 0;
        int last = (int)m.size()-1;
        
        while ( first < last){
            
            /*
             
             iterate from [first:last)
             
             last index is non-inclusive
             since we don't want to process the last column/row
             since that last column/row is being rotated
             
             example: size is 4,
             
             first          = 0
             last           = 3
             first + offset = 0,1,2  ==> as offset iterates from [0:3)
             last - offset  = 3,2,1  ==> as offset iterates from [0:3)

             
              0 1 2 3
            0 A A A B
            1 D     B
            2 D     B
            3 D C C C
             
             then for the sub-problem, size is 2 as first and last converge towards eachother
             
             first          = 1
             last           = 2
             first + offset = 1  ==> offset == 0, and there is only one iteration for matrix size 2
             last - offset  = 2  ==> offset == 0, and there is only one iteration for matrix size 2
             
               0 1 2 3
             0
             1   A B
             2   D C
             3
             
             */
            for (int offset=0; first + offset < last; offset++){
                
                /*
                 
                 CLOCKWISE
                 
                 */
                
                // store topmost-row in a temp var
                int temp = m[first][first + offset];
                
                // set topmost-row to leftmost-column
                m[first][first + offset] = m[last - offset][first];
                
                // set leftmost-column to bottommost-row
                m[last - offset][first] = m[last][last - offset];
                
                // set bottommost-row to rightmost-column
                m[last][last - offset] = m[first + offset][last];
                
                // set rightmost-column to the topmost-row
                m[first + offset][last] = temp;
                
                
                /*
                 
                 COUNTER-CLOCKWISE
                 
                 */
                
                /*
                // store topmost-row in a temp var
                int temp = m[first][first + offset];
                
                // set topmost-row = rightmost-column
                m[first][first + offset] = m[first + offset][last];
                
                // set rightmost-column = bottommost-row
                m[first + offset][last] = m[last][last - offset];
                
                // set bottommost-row = leftmost-column
                m[last][last - offset] = m[last - offset][first];
                
                // set leftmost-column = topmost-row ( temp var )
                m[last - offset][first] = temp;
                 */
            }
        
            // iterate inwards to the sub-problem
            first++;
            last--;
        }
    }
    
    static void print(vector<vector<int>>& m){
        int size = (int)m.size();
        
        for (int i=0; i < size; i++){
            for (int j=0; j < size; j++){
                
                cout << to_string(m[i][j]) + " ";
            }
            cout << endl;
        }
        cout << endl << endl << endl;
    }
};

class Test{
public:
    
    static void TestCase_01(){
        
        vector<vector<int>> matrix
        {
            {1,2},
            {3,4}
        };
        Test::Execute(matrix);
    }
    
    static void TestCase_02(){
        
        vector<vector<int>> matrix
        {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}
        };
        Test::Execute(matrix);
    }
    
    static void Execute(vector<vector<int>>& matrix){
        
        cout << "Before: " << endl;
        Solution::print(matrix);
        
        Solution::rotate(matrix);
        
        cout << "After: " << endl;
        Solution::print(matrix);
    }
};


int main(int argc, const char * argv[]) {

    Test::TestCase_01();
    Test::TestCase_02();
    
    return 0;
}




