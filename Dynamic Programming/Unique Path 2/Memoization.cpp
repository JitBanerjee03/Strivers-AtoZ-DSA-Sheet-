#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Recursion(int i,int j,vector<vector<int>> &obstacleGrid,int m,int n,vector<vector<int>> &dp){
      if(i==0 && j==0)
      return 1;

      int left=0,down=0;

      if(dp[i][j]!=-1)
      return dp[i][j];

      if(j-1>=0 && obstacleGrid[i][j-1]!=1)
      left=Recursion(i,j-1,obstacleGrid,m,n,dp);

      if(i-1>=0 && obstacleGrid[i-1][j]!=1)
      down=Recursion(i-1,j,obstacleGrid,m,n,dp);

      return dp[i][j]=left+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m=obstacleGrid.size()-1;
      int n=obstacleGrid[0].size()-1;
      
      if(obstacleGrid[m][n]==1)
      return 0;
      
      vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
      return Recursion(m,n,obstacleGrid,m,n,dp);
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