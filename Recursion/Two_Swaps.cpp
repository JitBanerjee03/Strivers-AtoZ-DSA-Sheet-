#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    
    int findPartition(vector<int> &A,int low,int high,int &count){
      int pivot=low,i=low,j=high,temp;
      while(i<j){
        
        while(i<high && A[i]<=A[pivot])
        i++;

        while(j>low && A[j]>A[pivot])
        j--;

        if(i<j)
        {
          temp=A[i];
          A[i]=A[j];
          A[j]=temp;
          count++; 
          i++;
          j--;
        }
      }

      if(j>low && A[j]<A[pivot]){
        temp=A[j];
        A[j]=A[pivot];
        A[pivot]=temp;
        count++;
        return j;
      }
      
      return pivot;
    }

    void noSwaps(vector<int> &A,int low,int high,int &count){
      
      if(count>2)
      return;

      if(low<high){
        int partition=findPartition(A,low,high,count);
        noSwaps(A,low,partition-1,count);
        noSwaps(A,partition+1,high,count);
      }
    }
    
    bool checkSorted(int N, vector<int> A)
    {  
      int count=0;
      noSwaps(A,0,N-1,count);
      cout<<count;
      if(count==2)
      return true;

      return false;
    }   
};

int main(){
//7 2 4 6 5 3 1  
  vector<int> arr;
  arr.push_back(7);
  arr.push_back(2);
  arr.push_back(4);
  arr.push_back(6);
  arr.push_back(5);
  arr.push_back(3);
  arr.push_back(1);
  Solution Obj;
  if(Obj.checkSorted(7,arr))
  cout<<"True";

  else
  cout<<"False";
}