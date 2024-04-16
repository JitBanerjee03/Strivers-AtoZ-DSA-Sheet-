/*
  Given an integer array nums,return true if you can partition the array into two subsets 
  such that the sum of the elements in both subsets is equal or false otherwise.

  Example 1:
  Input: nums = [1,5,11,5]
  Output: true
  Explanation: The array can be partitioned as [1, 5, 5] and [11].

  Example 2:
  Input: nums = [1,2,3,5]
  Output: false
  Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //Using recursion
    bool Recursion(int index,vector<int>& nums,int target){
      
      //base case
      if(target==0)
      return true;

      if(index==0){
        if(nums[0]==target)
        return true;

        return false;
      }
      
      bool first=Recursion(index-1,nums,target);
      bool second=false;

      if(nums[index]<=target)
      second=Recursion(index-1,nums,target-nums[index]);

      return first|second;
    }
    bool canPartition(vector<int>& nums) {
      int sum=0;

      for(int i=0;i<nums.size();i++)
      sum+=nums[i];
      
      if(sum%2!=0)
      return false;

      return Recursion(nums.size()-1,nums,sum/2);
    }
};

int main(){
  Solution Obj;
  vector<int> nums={1,5,11,5};

  bool ans=Obj.canPartition(nums);
  if(ans)
  cout<<"True"<<endl;
  else
  cout<<"False"<<endl;

  nums.clear();
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(5);
  ans=Obj.canPartition(nums);
  if(ans)
  cout<<"True"<<endl;
  else
  cout<<"False"<<endl;
}