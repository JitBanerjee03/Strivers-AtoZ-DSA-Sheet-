//Given a binary tree, determine if it is height-balanced.

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

//Function prototype to crete the binary tree
TreeNode *create();

class Solution {
public:
    /*Recursive function to check weather the tree is height balanced or not by modifing 
    the recursive function to find the height of the binary tree*/
    
    /*This function will return the height of the binary tree if the tree is balanced binary tree
      but it will return -1 if the binary tree is not a height balanced tree
    */
    int isHeightBalanced(TreeNode* root){
      if(root==nullptr)
      return 0;

      int leftHeight=isHeightBalanced(root->left);
      int rightHeight=isHeightBalanced(root->right);

      if(leftHeight==-1 || rightHeight==-1)
      return -1;

      if(abs(leftHeight-rightHeight)>=2)
      return -1;

      return max(leftHeight,rightHeight)+1;
    }

    bool isBalanced(TreeNode* root) {
      int isbal=isHeightBalanced(root);
      if(isbal==-1)
      return false;

      return true;
    }
};

int main(){
  Solution Obj;
  //Test case 1 : [3,9,20,null,null,15,7]
  TreeNode *root1=create();
  if(Obj.isBalanced(root1))
  cout<<"\nThe tree is a balanced trees";
  else
  cout<<"\nThe tree is not a balanced tree";

  //Test Case 2 : [1,2,2,3,3,null,null,4,4]
  TreeNode *root2=create();
  if(Obj.isBalanced(root2))
  cout<<"\nThe tree is a balanced trees";
  else
  cout<<"\nThe tree is not a balanced tree";
}

//Function defination of the Tree create function
TreeNode *create(){
  int val,choice;
  cout<<"\nEnter the value of the node : ";
  cin>>val;
  TreeNode *Node=new TreeNode(val);

  cout<<"\nPress 1 if you want to have left child of "<<val<<" : ";
  cin>>choice;

  if(choice==1)
  Node->left=create();

  cout<<"\nPress 1 if you want to have right child of "<<val<<" : ";
  cin>>choice;

  if(choice==1)
  Node->right=create();

  return Node;
}