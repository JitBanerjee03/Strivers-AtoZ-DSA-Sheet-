#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m=obstacleGrid.size()-1;
      int n=obstacleGrid[0].size()-1;
      
      if(obstacleGrid[m][n]==1)
      return 0;
      
      vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
      int right,down;
      for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            right=0;
            down=0;
            if(i==0 && j==0)
            dp[i][j]=1;

           else{
             if(j-1>=0 && obstacleGrid[i][j-1]!=1)
             right=dp[i][j-1];

             if(i-1>=0 && obstacleGrid[i-1][j]!=1)
             down=dp[i-1][j];

             dp[i][j]=right+down;
           }
        }
      }
      return dp[m][n];
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