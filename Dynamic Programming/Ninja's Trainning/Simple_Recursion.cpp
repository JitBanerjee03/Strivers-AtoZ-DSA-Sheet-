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
int Recursion(int rows,int previousActivity,vector<vector<int>> &points){  //Here 
   
   if(rows==0){
      int maxi=0;
     for(int i=0;i<3;i++){
       if(i!=previousActivity){
         maxi=max(maxi,points[0][i]);
       }
     }
     return maxi;
   }

   int first=0,second=0,third=0;
   
   if(previousActivity!=2)
   first=points[rows][2]+Recursion(rows-1,2,points);

   if(previousActivity!=1)
   second=points[rows][1]+Recursion(rows-1,1,points);

   if(previousActivity!=0)
   third=points[rows][0]+Recursion(rows-1,0,points);

   return max(max(first,second),third);
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
  return Recursion(n-1,3,points); 
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

    cout<<ninjaTraining(points.size(),points);
}