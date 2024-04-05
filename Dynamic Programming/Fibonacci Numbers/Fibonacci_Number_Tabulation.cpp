/*This is a dynamic programming approach (Tabulation) method for fibonacci number
  The tabulation method is the bottom to top approach to solve the DP problems
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n){
  vector<int> dp(n+1,-1);
  
  dp[0]=0;  //
  dp[1]=1;
  
  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  return dp[n];
}
int main(){
    int n;
    cout<<"\nEnter the value of n :";
    cin>>n;
    cout<<fibonacci(n);
}

/*
  <---Complexity Analysis--->
  Time Complexity = O(n)
  Space Complexity = O(n)
*/