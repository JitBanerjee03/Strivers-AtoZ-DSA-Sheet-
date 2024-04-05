#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Using Tabulation method (Dynamic Programming apprach) to solve the problem in terms of indexes where each index is the sub problem
    //Basically Tabulation method is the bottom up approach while recursive approach(memoization) is top down approach
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m,vector<int>(n,-1));
      int temp1,temp2;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          temp1=0;
          temp2=0;

          if(i==0 && j==0)
          dp[i][j]=1;

          else{
            if(j-1>=0)
            temp1=dp[i][j-1];

            if(i-1>=0)
            temp2=dp[i-1][j];

            dp[i][j]=temp1+temp2;
          }
        }
      }
      return dp[m-1][n-1];
    }
};

int main(){
    Solution Obj;
    cout<<Obj.uniquePaths(3,7);
}