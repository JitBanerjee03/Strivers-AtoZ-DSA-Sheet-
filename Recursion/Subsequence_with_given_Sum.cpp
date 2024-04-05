#include<iostream>
#include<vector>
using namespace std;
vector<int> Arr;
void Print_Subsequence(int,vector<int> &,int,int);
int main()
{
  vector<int> arr;
  Arr.push_back(1);
  Arr.push_back(4);
  Arr.push_back(2);
  Arr.push_back(1);
  Arr.push_back(3);
  Print_Subsequence(0,arr,3,0);
}
void Print_Subsequence(int i,vector<int> &arr,int k,int sum)
{
  if(i>=Arr.size())
  {
    if(sum==k)
    {
      cout<<"{ ";
      for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";
      cout<<"}";
      cout<<endl;
    }
    return;
  }

    arr.push_back(Arr[i]);
    Print_Subsequence(i+1,arr,k,sum+Arr[i]);
    arr.pop_back();
    Print_Subsequence(i+1,arr,k,sum);
}