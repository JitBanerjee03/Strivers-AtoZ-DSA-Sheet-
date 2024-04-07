/*
   You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
   The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
   The robot can only move either down or right at any point in time.
   An obstacle and space are marked as 1 or 0 respectively in grid. 
   A path that the robot takes cannot include any square that is an obstacle.
   Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
   The testcases are generated so that the answer will be less than or equal to 2 * 109.

   Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
   Output: 2
   Explanation: There is one obstacle in the middle of the 3x3 grid above.
   There are two ways to reach the bottom-right corner:
   1. Right -> Right -> Down -> Down
   2. Down -> Down -> Right -> Right

   Input: obstacleGrid = [[0,1],[0,0]]
   Output: 1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Recursion(int i,int j,vector<vector<int>> &obstacleGrid,int m,int n){
      if(i==0 && j==0)
      return 1;

      int left=0,down=0;

      if(j-1>=0 && obstacleGrid[i][j-1]!=1)
      left=Recursion(i,j-1,obstacleGrid,m,n);

      if(i-1>=0 && obstacleGrid[i-1][j]!=1)
      down=Recursion(i-1,j,obstacleGrid,m,n);

      return left+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m=obstacleGrid.size()-1;
      int n=obstacleGrid[0].size()-1;
      
      if(obstacleGrid[m][n]==1)
      return 0;
      
      return Recursion(m,n,obstacleGrid,m,n);
    }
};

int main(){
  Solution Obj;
  vector<vector<int>> obstacleGrid;
  obstacleGrid.push_back({0,0,0});
  obstacleGrid.push_back({0,1,0});
  obstacleGrid.push_back({0,0,0});
  cout<<Obj.uniquePathsWithObstacles(obstacleGrid);
}