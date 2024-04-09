/*Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
  A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, 
  the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

  Example 1:
  2 1 3
  6 5 4
  7 8 9 
  Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
  Output: 13
  Explanation: There are two falling paths with a minimum sum as shown.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Recursion(int i,int j,vector<vector<int>> &matrix,int n){
      
      if(i==0)  //base case of the recurrance relation
      return matrix[i][j];

      int leftDiagonal=INT_MAX,vertical=INT_MAX,rightDiagonal=INT_MAX;

      if(j-1>=0)
      leftDiagonal=Recursion(i-1,j-1,matrix,n);

      vertical=Recursion(i-1,j,matrix,n);

      if(j+1<n)
      rightDiagonal=Recursion(i-1,j+1,matrix,n);

      return matrix[i][j]+min(min(leftDiagonal,rightDiagonal),vertical);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n=matrix.size();  //n is the size of the matrix
      int ans=Recursion(n-1,0,matrix,n);
      for(int i=1;i<n;i++)
        ans=min(ans,Recursion(n-1,i,matrix,n));

      return ans;
    }
};

int main(){
  //[[2,1,3],[6,5,4],[7,8,9]]
  vector<vector<int>> matrix1,matrix2;
  matrix1.push_back({2,1,3});
  matrix1.push_back({6,5,4});
  matrix1.push_back({7,8,9});

  //[[-19,57],[-40,-5]]
  matrix2.push_back({-19,57});
  matrix2.push_back({-40,-5});
  Solution Obj;
  cout<<Obj.minFallingPathSum(matrix1);
  cout<<endl;
  cout<<Obj.minFallingPathSum(matrix2);
}