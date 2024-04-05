/*This is Dynamic Programing approach (Memoization) method to solve the fibonacci number problem
  Fibonacci number are : 0,1,1,2,3,5,8,13,...*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n,vector<int> &dp){
  if(n<=1)
  return n;

  if(dp[n]!=-1)
  return dp[n];

  return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}
int main(){
  int n;
  cout<<"Enter the value of n :";
  cin>>n;
  vector<int> dp(n+1,-1);
  cout<<fibonacci(n,dp);
}

/*
   <---Complexity Analysis--->
   Time complexity : O(n)  [Only those recursion calls will be happen where dp[n]!=1]
   space complexity : O(n) + O(n)  [First O(n) is the stack space of the recursion and the second O(n) is the space for the extra dp array]
*/