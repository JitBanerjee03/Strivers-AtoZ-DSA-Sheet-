#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 
TreeNode *create();

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode *,int>> queueTemp;
       int first,last,size,result=0;

       queueTemp.push({root,0});

       while(!queueTemp.empty()){
          size=queueTemp.size();
          first=queueTemp.front().second;
          last=queueTemp.front().second;
              
          if(queueTemp.front().first->left!=nullptr)
          queueTemp.push({queueTemp.front().first->left,2*(queueTemp.front().second-first)+1});
              
          if(queueTemp.front().first->right!=nullptr)
          queueTemp.push({queueTemp.front().first->right,2*(queueTemp.front().second-first)+2});

          size--;
          queueTemp.pop();
          
          while(size>0){
            last=queueTemp.front().second;

            if(queueTemp.front().first->left!=nullptr)
            queueTemp.push({queueTemp.front().first->left,2*(queueTemp.front().second-first)+1});
              
            if(queueTemp.front().first->right!=nullptr)
            queueTemp.push({queueTemp.front().first->right,2*(queueTemp.front().second-first)+2});
            
            size--;
            queueTemp.pop();
          }
          result=max(result,last-first+1);
        }
        return result;
    }
};

int main(){
  TreeNode *root=create();
  Solution Obj;
  cout<<Obj.widthOfBinaryTree(root);
}

//Function to create the binary tree
TreeNode *create(){
  int val,choice;
  TreeNode *node;
  cout<<"\nEnter the data value of the node : ";
  cin>>val;
  node=new TreeNode(val);

  cout<<"\nPress 1 if you want to have left child of "<<node->val<<" : ";
  cin>>choice;
  
  if(choice==1)
  node->left=create();

  cout<<"\nPress 1 if you want to have right child of "<<node->val<<" : ";
  cin>>choice;

  if(choice==1)
  node->right=create();

  return node;
}