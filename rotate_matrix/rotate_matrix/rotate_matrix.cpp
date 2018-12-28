/*

 48. Rotate Image
 
 https://leetcode.com/problems/rotate-image/description/
 
 Given an image represented by an NxN marix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.  Can you do this in place?
 
 */

#include <iostream>

using namespace std;

const int SIZE = 3;

class Solution{
public:
    void rotate(int m[][SIZE]) {
        
        // swap row/col
        for (int i=0; i < SIZE; i++) {
            for ( int j=i; j < SIZE; j++ ) {
                
                int temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
            }
        }
        
        // reverse order of each row
        for (int i=0; i < SIZE; i++) {
            for ( int j=0; j < SIZE/2; j++) {
                
                int temp = m[i][j];;
                m[i][j] = m[i][SIZE-j-1];
                m[i][SIZE-j-1] = temp;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    int matrix[SIZE][SIZE] =
    {
        {0,1,2},
        {3,4,5},
        {6,7,8}
    };
    
    Solution solution;
    solution.rotate(matrix);
    
    return 0;
}


