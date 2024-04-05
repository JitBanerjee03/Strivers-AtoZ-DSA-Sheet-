/*
   This program will print the subsequence of an array using recursion

   if an array is given as arr[]={1,7,4,5};
   then the possible subsequences of the array arr are:-
   1) {}
   2) {1}
   3) {1,7}
   4) {1,7,4}
   5) {1,7,4,5}
   6) {7}
   7) {7,4}
   8) {7,4,5}
   9) {4}
   10) {4,5}
   11) {5}
   12) {1,4}
   13) {1,4,5}
   14) {1,5}
   15) {7,5}
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> Arr;
void Subsequence(int,vector<int> &arr);  //decration of the function prototype

int main()
{
  vector<int> Temp;
  Arr.push_back(1);
  Arr.push_back(7);
  Arr.push_back(4);
  Arr.push_back(5);
  Subsequence(0,Temp);
}

void Subsequence(int i,vector<int> &arr) //Declaration of the function prototype
{
  if(i>=Arr.size())
  { 
    cout<<"{ ";
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<"}"
    <<endl;
    return ;
  }
   Subsequence(i+1,arr);
 
   arr.push_back(Arr[i]);
   Subsequence(i+1,arr);
   
   arr.pop_back();
}