#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
   Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. 
   (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. 
   As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
   Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
Your task is to calculate the maximum number of merit points that Ninja can earn.

If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<int> dp(3,0);
  vector<int> tempDp(3,0);
  
  dp[0]=max(points[0][1],points[0][2]);
  dp[1]=max(points[0][0],points[0][2]);
  dp[2]=max(points[0][0],points[0][1]);

  for(int i=1;i<n;i++){
    for(int j=0;j<3;j++){
        int first=0,second=0,third=0;
            
            if(j!=2)
            first=points[i][2]+dp[2];

            if(j!=1)
            second=points[i][1]+dp[1];

            if(j!=0)
            third=points[i][0]+dp[0];
        tempDp[j]=max(max(first,second),third);
    }
    for(int k=0;k<3;k++)
    dp[k]=tempDp[k];
  }

  int max=dp[0];
  for(int i=1;i<3;i++){
    if(dp[i]>max)
    max=dp[i];
  }
  return max;
}

//main function
int main(){
   
   /* Input points
      10 40 70
      20 50 80
      30 60 90
   */
    vector<vector<int>> points;
    points.push_back({10,40,70});
    points.push_back({20,50,80});
    points.push_back({30,60,90});

   // cout<<ninjaTraining(points.size(),points);
   int n=ninjaTraining(points.size(),points);
   cout<<n;
}