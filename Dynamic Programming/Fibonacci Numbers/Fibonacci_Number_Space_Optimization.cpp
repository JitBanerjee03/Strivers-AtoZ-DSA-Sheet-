/*
  Here we will reduce the extra space for fibonacci number problem 
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
  
  if(n<=1)
  return n;
  
  int cur,prev2=0,prev=1;  
  for(int j=2;j<=n;j++){
    cur=prev+prev2;
    prev2=prev;
    prev=cur;
  }
  return cur;
}

int main(){
  int n;
  cout<<"\nEnter the value of n : ";
  cin>>n;
  cout<<fibonacci(n);
}

/*
  <---Complexity analysis--->
  Time complexity : O(n)
  Space complexity : O(1) [Constant space]
*/