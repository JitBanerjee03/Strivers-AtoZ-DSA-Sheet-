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
    int climbStairs(int n) {
      vector<int> dp(n+1,-1);
      dp[0]=1;
      dp[1]=1;
      int left,right;
      for(int i=2;i<=n;i++){
        left=dp[i-1];
        right=dp[i-2];
        dp[i]=left+right;
      }
      return dp[n];
    }
};
int main(){
    Solution Obj;
    int n;
    cout<<"\nEnter the stair number to which you want to go : ";
    cin>>n;
    cout<<Obj.climbStairs(n);
}