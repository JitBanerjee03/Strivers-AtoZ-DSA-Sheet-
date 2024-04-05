#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ispalindrome(string s,int index,int i){
      int flag=1,j=index,k=i;
      while(j<k){
        if(s[j]!=s[k])
        return false;
        j++;
        k--;
      }
      return true;
    }
    void Recursion(vector<vector<string>> &ans,vector<string> &temp,string s,int index){
      
      if(index>=s.size()){
        ans.push_back(temp);
        temp.pop_back();
        return;
      }

      for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index,i)){
           string str="";
           for(int j=index;j<=i;j++)
           str+=s[j];
           temp.push_back(str);
           Recursion(ans,temp,s,index+1);
           temp.pop_back();
        }
      }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> temp;
      Recursion(ans,temp,s,0); 
      return ans; 
    }
};
int main(){
    Solution Obj;
    vector<vector<string>> ans=Obj.partition("aabb");
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
}