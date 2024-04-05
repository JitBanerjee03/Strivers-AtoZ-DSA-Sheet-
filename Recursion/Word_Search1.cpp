
//This Problem is 79.Leetcode problem and can be solved using bruteforce backtracking
//This problem will give TLE(Time limit exceed) this is because we are using an extra space unordered_map<string,int> temp and 
//generating strings for each index which makes the code complex so Word_Search2 resolves all the problems
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Recursion(int i,int j,unordered_map<string,int> &temp,vector<vector<char>> &board,string word,int index){
      if(index==word.size()-1)
      return true;

      if(index==0){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[index]){
                    
                    if((i-1)>=0 && board[i-1][j]==word[index+1]){
                        string str="";
                        str='0'+i;
                        str+='0'+j;
                        temp[str]=1;
                        if(Recursion(i-1,j,temp,board,word,index+1))
                        return true;
                        temp.erase(str);
                    }

                    if((j+1)<board[0].size() && board[i][j+1]==word[index+1]){
                        string str="";
                        str='0'+i;
                        str+='0'+j;
                        temp[str]=1;
                        if(Recursion(i,j+1,temp,board,word,index+1))
                        return true;
                        temp.erase(str); 
                    }

                    if((i+1)<board.size() && board[i+1][j]==word[index+1]){
                        string str="";
                        str='0'+i;
                        str+='0'+j;
                        temp[str]=1;
                        if(Recursion(i+1,j,temp,board,word,index+1))
                        return true;
                        temp.erase(str);
                    }

                    if((j-1)>=0 && board[i][j-1]==word[index+1]){
                        string str="";
                        str='0'+i;
                        str+='0'+j;
                        temp[str]=1;
                        if(Recursion(i,j-1,temp,board,word,index+1))
                        return true;
                        temp.erase(str);
                    }
                }
            }
        }
      }

       else{
              string str="";
              str='0'+i;
              str+='0'+j;

              if((i-1)>=0 && board[i-1][j]==word[index+1]){
                string t_str="";
                t_str='0'+i-1;
                t_str+='0'+j;
                if(temp.find(t_str)==temp.end()){
                temp[str]=1;
                if(Recursion(i-1,j,temp,board,word,index+1))
                return true;
                temp.erase(str);
                }
              }

              if((j+1)<board[0].size() && board[i][j+1]==word[index+1]){
                string t_str="";
                t_str='0'+i;
                t_str+='0'+j+1;
                if(temp.find(t_str)==temp.end()){
                temp[str]=1;
                if(Recursion(i,j+1,temp,board,word,index+1))
                return true;
                temp.erase(str);
                }
              }

              if((i+1)<board.size() && board[i+1][j]==word[index+1]){
                string t_str="";
                t_str='0'+i+1;
                t_str+='0'+j;
                if(temp.find(t_str)==temp.end()){
                temp[str]=1;
                if(Recursion(i+1,j,temp,board,word,index+1))
                return true;
                temp.erase(str);
                }
              }

              if((j-1)>=0 && board[i][j-1]==word[index+1]){
                string t_str="";
                t_str='0'+i;
                t_str+='0'+j-1;
                if(temp.find(t_str)==temp.end()){
                temp[str]=1;
                if(Recursion(i,j-1,temp,board,word,index+1))
                return true;
                temp.erase(str);
                }
              }
            
        }
       return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
      unordered_map<string,int> temp;
      return Recursion(0,0,temp,board,word,0);
    }
};
int main(){
    Solution Obj;

    vector<vector<char>> board;
    vector<char> temp;
    
    temp.push_back('A');
    temp.push_back('B');
    temp.push_back('C');
    temp.push_back('E');
    board.push_back(temp);
    temp.clear();

    temp.push_back('S');
    temp.push_back('F');
    temp.push_back('C');
    temp.push_back('S');
    board.push_back(temp);
    temp.clear();

    temp.push_back('A');
    temp.push_back('D');
    temp.push_back('E');
    temp.push_back('E');
    board.push_back(temp);
    temp.clear();

    bool ans=Obj.exist(board,"ABCB");  //ABCCED

    if(ans)
    cout<<"The word exit in the board";

    else
    cout<<"The word does not exit in the board";
}