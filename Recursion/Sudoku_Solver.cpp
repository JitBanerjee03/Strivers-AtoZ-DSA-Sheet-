#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Recursion(int cols,vector<vector<char>>& board,int f){  //Recursive function to solve the sudoku problem
      
      if(cols>=9)  //base case of the recursion
      {
        f=1;
        return f;
      }  

      for(int i=0;i<9;i++){
        
        if(board[i][cols]=='.'){
          int j=1;
          while(f==0 && j<=9){
            int flag=1;
            for(int k=0;k<9;k++){  //Loop to check weather in the correspoding row have the value j  
                if(board[i][k]!='.' && board[i][k]-'0'==j){
                    flag=0;
                    break;
                }
            }

            if(flag){
                for(int k=0;k<9;k++){  //Loop to check weather in the correspoding column have the value j  
                if(board[k][cols]!='.' && board[k][cols]-'0'==j){
                    flag=0;
                    break;
                }
            }
              if(flag){
                int r,c;

                if(i<3)
                r=0;

                else if(i<6)
                r=3;

                else
                r=6;

                if(cols<3)
                c=0;

                else if(cols<6)
                c=3;

                else
                c=6;
              
                for(int k=r;k<r+3;k++){
                    for(int l=c;l<c+3;l++){
                        if(board[k][l]!='.' && board[k][l]-'0'==j)
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==0)
                    break;
                }
              }
            }
            if(flag){
                board[i][cols]='0'+j;
                f=Recursion(cols+1,board,f);
                
                if(f==0)
                board[i][cols]='.';
            }
            j++;
          }
        }
        
        else{
          f=Recursion(cols+1,board,f);
        }
      }
      return f;
    }
    void solveSudoku(vector<vector<char>>& board) {
      Recursion(0,board,0);  
    }
};
int main(){
    vector<char> element;
    vector<vector<char>> board;

    //["5","3",".",".","7",".",".",".","."]
    element.push_back('5');
    element.push_back('3');
    element.push_back('.');
    element.push_back('.');
    element.push_back('7');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');

    board.push_back(element);
    element.clear();

   //["6",".",".","1","9","5",".",".","."]
    element.push_back('6');
    element.push_back('.');
    element.push_back('.');
    element.push_back('1');
    element.push_back('9');
    element.push_back('5');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');

    board.push_back(element);
    element.clear();

    //[".","9","8",".",".",".",".","6","."]
    element.push_back('.');
    element.push_back('9');
    element.push_back('8');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('6');
    element.push_back('.');

    board.push_back(element);
    element.clear();

    //["8",".",".",".","6",".",".",".","3"]
    element.push_back('8');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('6');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('3');

    board.push_back(element);
    element.clear();

    //["4",".",".","8",".","3",".",".","1"]
    element.push_back('4');
    element.push_back('.');
    element.push_back('.');
    element.push_back('8');
    element.push_back('.');
    element.push_back('3');
    element.push_back('.');
    element.push_back('.');
    element.push_back('1');

    board.push_back(element);
    element.clear();

    //["7",".",".",".","2",".",".",".","6"]
    element.push_back('7');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('2');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('6');

    board.push_back(element);
    element.clear();

    //[".","6",".",".",".",".","2","8","."]
    element.push_back('.');
    element.push_back('6');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('2');
    element.push_back('8');
    element.push_back('.');

    board.push_back(element);
    element.clear();

    //[".",".",".","4","1","9",".",".","5"]
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('4');
    element.push_back('1');
    element.push_back('9');
    element.push_back('.');
    element.push_back('.');
    element.push_back('5');

    board.push_back(element);
    element.clear();

    //[".",".",".",".","8",".",".","7","9"]
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('.');
    element.push_back('8');
    element.push_back('.');
    element.push_back('.');
    element.push_back('7');
    element.push_back('9');

    board.push_back(element);
    element.clear();

    Solution Obj; 
    Obj.solveSudoku(board);
    cout<<"[";
    for(int i=0;i<9;i++){
        cout<<"[";
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
}