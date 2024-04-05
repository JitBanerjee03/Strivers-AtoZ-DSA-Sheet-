#include<iostream>
#include<vector>
using namespace std;
vector<int> Arr;
bool Print_Subsequence(int,vector<int> &,int,int);
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

bool Print_Subsequence(int i,vector<int> &arr,int k,int sum)
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
      return true;
    }
    return false;
  }
    
    arr.push_back(Arr[i]);

    if(Print_Subsequence(i+1,arr,k,sum+Arr[i])==true)
    return true;
    
    arr.pop_back();

    if(Print_Subsequence(i+1,arr,k,sum))
    return true;

    return false;
}