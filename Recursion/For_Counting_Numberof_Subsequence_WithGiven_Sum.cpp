#include<iostream>
#include<vector>
using namespace std;
vector<int> Arr;
int Print_Subsequence(int,vector<int> &,int,int);
int main()
{
  vector<int> arr;
  Arr.push_back(1);
  Arr.push_back(4);
  Arr.push_back(2);
  Arr.push_back(1);
  Arr.push_back(3);
  cout<<"Number of subsequence with the given sum "<<3<<" is "<<Print_Subsequence(0,arr,3,0);
}

int Print_Subsequence(int i,vector<int> &arr,int k,int sum)
{
  if(i>=Arr.size())
  {
    if(sum==k)
    return 1;
    
    return 0;
  }
    
    arr.push_back(Arr[i]);
    int first=Print_Subsequence(i+1,arr,k,sum+Arr[i]);
    
    arr.pop_back();
    int second=Print_Subsequence(i+1,arr,k,sum);
    
    return first+second;
}