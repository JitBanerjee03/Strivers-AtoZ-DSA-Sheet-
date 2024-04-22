/*
   You are given an integer array nums of 2 * n integers. 
   You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays.
   To partition nums, put each element of nums into one of the two arrays.
   Return the minimum possible absolute difference.

   Example 1:
             Input
             array 1: 3,9
             nums :   3,9,7,3
             array 2: 73

             Output : 2
             Explanation: One optimal partition is: [3,9] and [7,3].
             The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
    
    Example 2:
              Input: nums = [-36,36]
              Output: 72
              Explanation: One optimal partition is: [-36] and [36].
              The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int Recursion(int index,vector<int> &nums,int sum1,int k1,int sum2,int k2){
       
       //Base case 1 of the recursion
       if(k1==nums.size()/2){
         for(int i=index;i>=0;i--){
            sum2+=nums[i];
         }
         return abs(sum1-sum2);
       }

       //Base case 2 of the recursion
       if(k2==nums.size()/2){
          
          for(int i=index;i>=0;i--){
            sum1+=nums[i];
          }
         return abs(sum1-sum2);
       }
       
       int s1=k1,s2=k2;
       int first=Recursion(index-1,nums,sum1+nums[index],++s1,sum2,k2);
       int second=Recursion(index-1,nums,sum1,k1,sum2+nums[index],++s2);

       return min(first,second);
    }

    int minimumDifference(vector<int>& nums) {
      return Recursion(nums.size()-1,nums,0,0,0,0);
    }
};

int main(){
  vector<int> nums1={3,9,7,3};  //[3,9,7,3]   
  Solution Obj;
  cout<<Obj.minimumDifference(nums1)<<endl;

  vector<int> nums2={-36,36}; //[-36,36]
  cout<<Obj.minimumDifference(nums2)<<endl;

  vector<int> nums3={2,-1,0,4,-2,-9};
  cout<<Obj.minimumDifference(nums3);
}