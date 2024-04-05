/*
  Problem statement:

  There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 
  'HEIGHT[i]' is the height of the '(i+1)th' stair.
  If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ).
  If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
  Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) 
and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.

<----Test Cases---->
4
10 20 30 10
3
10 50 10
Sample Output 1:
20
0
Explanation of sample input 1:
For the first test case,
The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
So, the total energy lost is 20 which is the minimum. 
Hence, the answer is 20.

For the second test case:
The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
So, the total energy lost is 0 which is the minimum. 
Hence, the answer is 0.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Memoization(int n,vector<int> &heights,vector<int> &dp){
  if(n==0)
  return 0;

  if(dp[n]!=-1)
  return dp[n];

  int left= abs(heights[n]-heights[n-1])+Memoization(n-1,heights,dp);

  int right;
  if(n>1)
  right= abs(heights[n]-heights[n-2])+Memoization(n-2,heights,dp);
  return dp[n]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(heights.size()+1,-1);
  return Memoization(n,heights,dp);
}
int main(){
   vector<int> height={10,20,30,10};
   cout<<frogJump(height.size()-1,height);
}