#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Recursive_Function(int index,vector<char> &temp,unordered_map<char,string> &Temp_Map,string digits,vector<string> &ans){
      
      if(temp.size()==digits.size()){  //This is the base case of the recursion
        
        string str="";

        for(int i=0;i<temp.size();i++)
        str+=temp[i];
        
        ans.push_back(str);

        return;
      }

      string hash_map=Temp_Map[digits[index]];
      
      for(int i=0;i<hash_map.size();i++){
        temp.push_back(hash_map[i]);
        Recursive_Function(index+1,temp,Temp_Map,digits,ans);
        temp.pop_back();
      }
    }
    vector<string> letterCombinations(string digits) {
      unordered_map<char,string> Temp_Map;
      vector<char> temp;
      vector<string> ans;

      Temp_Map['2']="abc";
      Temp_Map['3']="def";
      Temp_Map['4']="ghi";
      Temp_Map['5']="jkl";
      Temp_Map['6']="mno";
      Temp_Map['7']="pqrs";
      Temp_Map['8']="tuv";
      Temp_Map['9']="wxyz";
    
      Recursive_Function(0,temp,Temp_Map,digits,ans);
      return ans;
    }
};

int main(){
    Solution Obj;
    vector<string> arr=Obj.letterCombinations("");
    
    cout<<"{ ";
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<" }";
}