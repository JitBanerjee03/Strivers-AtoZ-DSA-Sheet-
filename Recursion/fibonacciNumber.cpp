/*
   This is program to generate nth fibonacci number using recursion.
   
   A fibonacci number series is given by :
   0,1,1,2,3,5,8,13,...

   where , 0=0th term
           1=1st term
           2=3rd term and so on
*/

#include<iostream>
using namespace std;
int Fibonacci_Number(int);
int main()
{
  int n;
  cout<<"\nEnter the value of n : ";
  cin>>n;
  cout<<"\nThe "<<n<<"th fibonacci number is "<<Fibonacci_Number(n);
}
int Fibonacci_Number(int n)
{
  if(n<=1)
  return n;

  int first=Fibonacci_Number(n-2);
  int second=Fibonacci_Number(n-1);
  return first+second;
}