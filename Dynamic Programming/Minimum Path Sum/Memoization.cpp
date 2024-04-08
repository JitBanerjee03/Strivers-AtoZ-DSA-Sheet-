/*
   Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
   which minimizes the sum of all numbers along its path.
   Note: You can only move either down or right at any point in time.

   Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
   Output: 7
   Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

   Example 2:
   Input: grid = [[1,2,3],[4,5,6]]
   Output: 12
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Using memoization (Dynamic Programming approach to minimize overlapping recursive function call) 
    int recursion(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
      if(i==0 && j==0)
      return grid[i][j];
    
      if(dp[i][j]!=-1)
      return dp[i][j];
      
      int temp=grid[i][j],left=INT_MAX,up=INT_MAX;

      if(j-1>=0)
      left=recursion(i,j-1,grid,dp);

      if(i-1>=0)
      up=recursion(i-1,j,grid,dp);
    
      return dp[i][j]=temp+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
      vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));  //Initializing the dp 2D vector with -1 which will be passed as reference
      return recursion(grid.size()-1,grid[0].size()-1,grid,dp); 
    }
};
int main(){
  //[[1,3,1],[1,5,1],[4,2,1]]
  //[[1,2,3],[4,5,6]]
  vector<vector<int>> grid1,grid2;
  
  grid1.push_back({1,3,1});
  grid1.push_back({1,5,1});
  grid1.push_back({4,2,1});

  grid2.push_back({1,2,3});
  grid2.push_back({4,5,6});
  
  Solution Obj;
  
  cout<<Obj.minPathSum(grid1);
  cout<<endl;
  cout<<Obj.minPathSum(grid2);
}