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
    //Using Memoization 
    //Memoization is a dynamic programming approach to minimize time complexity that can occur due to overlapping recursive function call
    bool Recursion(int index,vector<int>& nums,int target,vector<vector<int>> &dp){
      
      //base case 1
      if(target==0)
      return true;

      if(index==0){  //base case 2
        if(nums[0]==target)
        return true;

        return false;
      }
      
      if(dp[index][target]!=-1)  //base case 3
      return dp[index][target];

      bool first=Recursion(index-1,nums,target,dp);
      bool second=false;

      if(nums[index]<=target)
      second=Recursion(index-1,nums,target-nums[index],dp);

      return dp[index][target]=first|second;
    }
    bool canPartition(vector<int>& nums) {
      int sum=0;

      for(int i=0;i<nums.size();i++)
      sum+=nums[i];
      
      if(sum%2!=0)
      return false;

      vector<vector<int>> dp(nums.size(),vector<int>(sum,-1));
      return Recursion(nums.size()-1,nums,sum/2,dp);
    }
};

/*
   Time Complexity : O(n*target)
   space Complexity : O(n*target) +O(n)
*/

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