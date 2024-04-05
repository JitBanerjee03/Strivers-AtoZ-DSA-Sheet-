#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Recursion_Permutation(unordered_map<int,int> &Map,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans){
      
      if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
      }
      for(int i=0;i<nums.size();i++){
        auto it=Map.find(temp[i]);
        if(it==Map.end()){
            Map[nums[i]]=1;
            temp.push_back(nums[i]);
            Recursion_Permutation(Map,nums,temp,ans);
            temp.pop_back();
            Map.erase(it);
        }
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> temp;
       unordered_map<int,int> Map;
       Recursion_Permutation(Map,nums,temp,ans);
       return ans;
     }
};
int main(){
    Solution Obj;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    vector<vector<int>> ans=Obj.permute(temp);
    cout<<"[ ";
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<" ]";
}