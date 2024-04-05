/*
   You are climbing a staircase. It takes n steps to reach the top.
   Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

//Here we will convert the previous recursive problem to DP approach using memoization
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Using_Memoization(int n,vector<int> &dp){
      if(n==0 || n==1)
      return 1;

      if(dp[n]!=-1)
      return dp[n];

      int left=Using_Memoization(n-1,dp);
      int right=Using_Memoization(n-2,dp);

      return dp[n]=left+right;
    }

    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
       int ans=Using_Memoization(n,dp);
       return ans;
    }
};
int main(){
    Solution Obj;
    int n;
    cout<<"\nEnter the stair number to which you want to go : ";
    cin>>n;
    cout<<Obj.climbStairs(n);
}