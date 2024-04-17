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
    //Using Tabulation 
    //Tabulation is a dynamic programming approach to overcome the stack space that can occur due to recursive function calls
    bool canPartition(vector<int>& nums) {
      int sum=0;

      for(int i=0;i<nums.size();i++)
      sum+=nums[i];
      
      if(sum%2!=0)
      return false;

      vector<vector<bool>> dp(nums.size(),vector<bool>(sum/2+1,0));
      
      for(int i=0;i<nums.size();i++)
      dp[i][0]=true;

      dp[0][nums[0]]=true;

      for(int i=1;i<nums.size();i++)
      {
        for(int target=1;target<=sum/2;target++){
           
           bool first=dp[i-1][target];
           bool second=false; 
           
           if(nums[i]<=target)
           second=dp[i-1][target-nums[i]];

           dp[i][target]=first|second;
        }
      }
      return dp[nums.size()-1][sum/2];
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