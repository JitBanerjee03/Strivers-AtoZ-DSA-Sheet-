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
    //Using Tabulation (Dynamic Programming approach to overcome the problem of  overlapping recursive function call as well as the extra stack space that occurs in case of recursion) 
    //Tabulation is bottom up approach while recursion is top down apprach
    int minPathSum(vector<vector<int>>& grid) {
      vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));  //Declaring the 2D dp 
      int right,down,temp;
      for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            
            if(i==0 && j==0)  //Tabulation base case
            dp[i][j]=grid[i][j];
           
           else{
             right=INT_MAX;
             down=INT_MAX;
             temp=grid[i][j];

             if(j-1>=0)
             right=dp[i][j-1];

             if(i-1>=0)
             down=dp[i-1][j];

             dp[i][j]=temp+min(right,down);
           }
        }
      }
      return dp[grid.size()-1][grid[0].size()-1];
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