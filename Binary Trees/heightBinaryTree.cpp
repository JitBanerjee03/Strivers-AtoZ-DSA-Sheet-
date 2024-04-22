/*
   Given the root of a binary tree, return its maximum depth.
   A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
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
    //Recursive function to find the height of the binary tree
    int maxHeight(TreeNode *root){
      if(root==nullptr)
      return 0;

      int leftHeight= maxHeight(root->left);
      int rightHeight= maxHeight(root->right);

      return max(leftHeight,rightHeight)+1;
    }
    int maxDepth(TreeNode* root) {
      return maxHeight(root);
    }
};

//Main function
int main(){
  //Test Case 1 : [3,9,20,null,null,15,7]
  TreeNode *root1=create();
  Solution Obj;
  cout<<Obj.maxDepth(root1);

  //Test Case 2 : [1,null,2]
  TreeNode *root2=create();
  cout<<Obj.maxDepth(root2);
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