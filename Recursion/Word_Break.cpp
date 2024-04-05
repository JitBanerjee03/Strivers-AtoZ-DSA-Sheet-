#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
      bool Recursion(int index,unordered_map<string,int> &temp,string s,unordered_map<string,int> &storage){
        
        /*
          base case of the recursion ,if the index range is equal to the size of the string s then the base case will be executed 
          ->now for all the elements (strings) in the given vector of strings wordDict a for loop is executed and will be checked it that 
            element is not present in the hashmap temp  
        */
        
        if(index>=s.size()){
          auto it=temp.begin();
          while(it!=temp.end()){
            if(storage.find(it->first)==storage.end())
            return false;
            it++;
          }
          return true;
        }

        for(int i=index;i<s.size();i++){  //For loop for generating all the partitions till index=s.size()
            string str="";
            for(int j=index;j<=i;j++){
                str+=s[j];
            }
            temp[str]=1;
            if(Recursion(i+1,temp,s,storage))  
            return true;
            temp.erase(str);
        }
        return false;
      }
      bool wordBreak(string s,vector<string> &wordDict){
        unordered_map<string,int> temp;
        unordered_map<string,int> storage;
        
        for(int i=0;i<wordDict.size();i++){
          storage[wordDict[i]]=1;
        }
        return Recursion(0,temp,s,storage);
      }
};

//main function
int main(){  
  
  Solution Obj;
  vector<string> wordDict;

  wordDict.push_back("aaaa");
  wordDict.push_back("aa");

  bool ans=Obj.wordBreak("aaaaaaa",wordDict);   //["aaaa","aa"]
  if(ans)
  cout<<"True";

  else
  cout<<"False";
}