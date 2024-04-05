#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Using Memoization (Dynamic Programming approach to overcome the stack space that can occur due to overlapping recursive function call).
    int Recursion(int i,int j,vector<vector<int>> &dp){
       
       //multiple base cases of the recursion
       if(i==0 && j==0)  //base case 1
       return 1;

       if(i<0 || j<0)   //base case 2
       return 0;

       if(dp[i][j]!=-1)  //if dp[i][j] is not -1 that means Recursion(i,j,dp) is already evaluated so no need to further call Recursion(i,j,dp)
       return dp[i][j];
       
       int left=Recursion(i,j-1,dp);

       int right=Recursion(i-1,j,dp);
    
       return dp[i][j]=left+right;  //when Recursion(i,j,dp) is evaluated then store it into dp[i][j] which is nothing but memoization
    }

    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m,vector<int>(n,-1));
      return Recursion(m-1,n-1,dp);
    }
};

int main(){
    Solution Obj;
    cout<<Obj.uniquePaths(3,7);
}