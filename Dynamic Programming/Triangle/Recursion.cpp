/*
   Given a triangle array, return the minimum path sum from top to bottom.
   For each step, you may move to an adjacent number of the row below. 
   More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

   Example 1:
   Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
   Output: 11
   Explanation: The triangle looks like:
     2
    3 4
   6 5 7
  4 1 8 3
  The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
  Example 2:
  
  Input: triangle = [[-10]]
  Output: -10
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std;
class Solution {
public:
    int Recursion(int i,int j,vector<vector<int>>& triangle){
      
      if(i>=triangle.size())
      return 0; 
    
      int temp1,temp2=INT_MAX;
      temp1=triangle[i][j]+Recursion(i+1,j,triangle);

      if(j+1<triangle[i].size())
      temp2=triangle[i][j+1]+Recursion(i+1,j+1,triangle);

      return min(temp1,temp2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
      return Recursion(0,0,triangle);
    }
};

int main(){
  //[[2],[3,4],[6,5,7],[4,1,8,3]]
  vector<vector<int>> triangle1;
  triangle1.push_back({2});
  triangle1.push_back({3,4});
  triangle1.push_back({6,5,7});
  triangle1.push_back({4,1,8,3});

  vector<vector<int>> triangle2;
  triangle2.push_back({-10});
  Solution Obj;
  cout<<Obj.minimumTotal(triangle1);
  cout<<endl;
  cout<<Obj.minimumTotal(triangle2);
}