/*
 
 733. Flood Fill
 
 https://leetcode.com/contest/weekly-contest-60/problems/flood-fill/
 
 An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
 
 Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
 
 To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
 
 At the end, return the modified image.
 
 Example 1:
 Input:
 image = [[1,1,1],[1,1,0],[1,0,1]]
 sr = 1, sc = 1, newColor = 2
 Output: [[2,2,2],[2,2,0],[2,0,1]]
 Explanation:
 From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
 by a path of the same color as the starting pixel are colored with the new color.
 Note the bottom corner is not colored 2, because it is not 4-directionally connected
 to the starting pixel.
 Note:
 
 The length of image and image[0] will be in the range [1, 50].
 The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
 The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
 
 */


#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int newColor) {
         vector<vector<int>> res(img);
         int oldColor=res[sr][sc];
         helper(res,sr,sc,oldColor,newColor);
         return res;
    }
private:
    set<pair<int,int>> visited{};
    void helper(vector<vector<int>>& res, int r, int c, int o, int n){
        if (r<0 || c<0 || r==res.size() || c==res[0].size() || res[r][c]==n) return;
        if (visited.find({r,c})!=visited.end()) return;
        visited.insert({r,c});
        if (res[r][c]==o){
            res[r][c]=n;
            helper(res,r-1,c,o,n); // above
            helper(res,r,c+1,o,n); // right
            helper(res,r+1,c,o,n); // below
            helper(res,r,c-1,o,n); // left
        }
    }
};


int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}





