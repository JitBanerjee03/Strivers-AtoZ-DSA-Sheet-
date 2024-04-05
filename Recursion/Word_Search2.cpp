
//This Problem is 79.Leetcode problem and can be solved using bruteforce backtracking 
//This solution resolves the TLE(Time limit exceed problem) that occured in the Word_Search1 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Recursion(int i,int j,vector<vector<char>> &board,string word,int index){
      if(index==word.size()-1)
      return true;

      if(index==0){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[index]){
                    char ch=board[i][j];
                    if((i-1)>=0 && board[i-1][j]==word[index+1]){
                        board[i][j]='$';
                        if(Recursion(i-1,j,board,word,index+1))
                        return true;
                        board[i][j]=ch;
                    }

                    if((j+1)<board[0].size() && board[i][j+1]==word[index+1]){
                        board[i][j]='$';
                        if(Recursion(i,j+1,board,word,index+1))
                        return true;
                        board[i][j]=ch; 
                    }

                    if((i+1)<board.size() && board[i+1][j]==word[index+1]){
                        board[i][j]='$';
                        if(Recursion(i+1,j,board,word,index+1))
                        return true;
                        board[i][j]=ch;
                    }

                    if((j-1)>=0 && board[i][j-1]==word[index+1]){
                       board[i][j]='$';
                        if(Recursion(i,j-1,board,word,index+1))
                        return true;
                        board[i][j]=ch;
                    }
                }
            }
        }
      }

       else{
              char ch=board[i][j];

              if((i-1)>=0 && board[i-1][j]==word[index+1]){
                board[i][j]='$';
                if(Recursion(i-1,j,board,word,index+1))
                return true;
                board[i][j]=ch;
                }
              

              if((j+1)<board[0].size() && board[i][j+1]==word[index+1]){
                board[i][j]='$';
                if(Recursion(i,j+1,board,word,index+1))
                return true;
                board[i][j]=ch;
                }
              

              if((i+1)<board.size() && board[i+1][j]==word[index+1]){
                board[i][j]='$';
                if(Recursion(i+1,j,board,word,index+1))
                return true;
                board[i][j]=ch;
                }

              if((j-1)>=0 && board[i][j-1]==word[index+1]){
                board[i][j]='$';
                if(Recursion(i,j-1,board,word,index+1))
                return true;
                board[i][j]=ch;
                }
            }
         return false;   
    }

    bool exist(vector<vector<char>>& board, string word) {
      unordered_map<string,int> temp;
      return Recursion(0,0,board,word,0);
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

    bool ans=Obj.exist(board,"ABCCED");  //ABCCED

    if(ans)
    cout<<"The word exit in the board";

    else
    cout<<"The word does not exit in the board";
}