#include<iostream>
#include<vector>
using namespace std;
void quickSort(int,int,vector<int> &);
int two_half(int,int,vector<int> &);
int main()
{
  vector<int> Arr;
  Arr.push_back(7);
  Arr.push_back(8);
  Arr.push_back(1);
  Arr.push_back(3);
  Arr.push_back(9);
  Arr.push_back(10);
  Arr.push_back(5);
  Arr.push_back(2);
  Arr.push_back(4);
  Arr.push_back(6);
  quickSort(0,9,Arr);
  cout<<"\nThe array of sorting is given by : ";
  cout<<"{ ";
  for(int i=0;i<=9;i++)
  cout<<Arr[i]<<" ";
  cout<<"}";
}
int two_half(int low,int high,vector<int> &arr)
{
  int temp,pivot=low,i=low,j=high;
  while(i<=j)
  {
    while(i<=high && arr[i]<=arr[pivot])
    i++;

    while(j>=low && arr[j]>arr[pivot])
    j--;

    if(i<=j)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
  }
  temp=arr[pivot];
  arr[pivot]=arr[j];
  arr[j]=temp;
  return j;
}
void quickSort(int low,int high,vector<int> &arr)
{
  if(low<high)
  {
    int partion=two_half(low,high,arr);
    quickSort(low,partion-1,arr);
    quickSort(partion+1,high,arr);
  }
}