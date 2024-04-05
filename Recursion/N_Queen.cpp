#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     
     void Recursion(int cols,vector<vector<char>> &temp,vector<vector<string>> &ans,int n){  //Recursive function to solve the n queen problem
       
       if(cols==n){  //base case
        string str;
        vector<string> elements;
        
        for(int i=0;i<n;i++){
          str="";
          for(int j=0;j<n;j++){
            str+=temp[i][j];
          }
          elements.push_back(str);
        }
        ans.push_back(elements);
        return;
      }
     
       for(int i=0;i<n;i++){
          int flag=1;
          for(int j=cols-1;j>=0;j--){
            if(temp[i][j]=='Q'){
              flag=0;
              break;
            }
          }

          if(flag){
            
            for(int k=i-1,j=cols-1;k>=0 && j>=0;k--,j--){
              if(temp[k][j]=='Q'){
                flag=0;
                break;
              }
            }

            if(flag){
              for(int k=i+1,j=cols-1;k<n && j>=0;k++,j--){
               if(temp[k][j]=='Q'){
                flag=0;
                break;
               }
              }
            }

          }
          if(flag){
           temp[i][cols]='Q';
           Recursion(cols+1,temp,ans,n);
           temp[i][cols]='.';
          }
       }
     }
     
     vector<vector<string>> solveNQueens(int n) {
    
      vector<vector<string>> ans;
      
      if(n==1){   //if n is 1
        vector<string> temp;
        temp.push_back("Q");
        ans.push_back(temp);
        return ans;
      }


      vector<vector<char>> temp;
      vector<char> initial;
      for(int i=0;i<n;i++){   //first creating the empty chess board
        for(int j=0;j<n;j++){
          initial.push_back('.');
        }
        temp.push_back(initial);
        initial.clear();
      }

      Recursion(0,temp,ans,n);
      return ans;
    }  
};
int main(){
  Solution Obj;
  vector<vector<string>> ans;
  ans=Obj.solveNQueens(4);
  cout<<"[";
  for(int i=0;i<ans.size();i++){
    cout<<"[";
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<"]";
  }
  cout<<"]";
}