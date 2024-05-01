#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode  *create();

class Solution {
public:
    //Recursive solution
    bool recursiveLowestCommonAncestor(int level,TreeNode *root,TreeNode *p,int flagP,int &levelP,TreeNode *q,int flagQ,int &levelQ,unordered_map<int,unordered_map<int,TreeNode *>> &mapTemp){
       
       if(flagP==1 && flagQ==1)  //basecase 1 of the recursion
       return true;

       if(root==nullptr)  //base case 2 of the recursion
       return false;
    
       mapTemp[level][root->val]=root;
       
       if(root==p){
         flagP=1;
         levelP=level;
       }

       if(root==q){
         flagQ=1;
         levelQ=level;
       }
       
       int temp=level;

       if(recursiveLowestCommonAncestor(++temp,root->left,p,flagP,levelP,q,flagQ,levelQ,mapTemp))
       return true;

       if(recursiveLowestCommonAncestor(++temp,root->right,p,flagP,levelP,q,flagQ,levelQ,mapTemp))
       return true;

       if(root!=p && root!=q && level>levelP && level>levelQ)
       mapTemp.erase(level);

       return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      unordered_map<int,unordered_map<int,TreeNode *>> mapTemp;
      int levelP=0,levelQ=0;
      recursiveLowestCommonAncestor(0,root,p,0,levelP,q,0,levelQ,mapTemp);

      while(levelP>levelQ){
        auto it=mapTemp[levelP-1].begin();
        while(it!=mapTemp[levelP-1].end())
        {
          if(it->second->left==p || it->second->right==p){
            p=it->second;
            break;
          }
          it++;
        }
        levelP--;   
      }

      while(levelQ>levelP){
        auto it=mapTemp[levelQ-1].begin();
        while(it!=mapTemp[levelQ-1].end())
        {
          if(it->second->left==q || it->second->right==q){
            q=it->second;
            break;
          }
          it++;
        }
         levelQ--;   
      }
      int level=levelP;
      while(p!=q){
        auto it=mapTemp[level-1].begin();
        int f1=0,f2=0;
        while(it!=mapTemp[level-1].end()){
          if(f1==1 && f2==1)
          break;

          if(it->second->left==p || it->second->right==p){
            p=it->second;
            f1=1;
          }

          else if(it->second->left==q ||it->second->right==q){
            q=it->second;
            f2=1;
          }

          it++;
        }
      }
      return p;
    }
};

int main(){
  //[3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
  TreeNode *root=create(),*p,*q;
  p=root->left;
  q=root->left->right->right;
  Solution Obj;
  TreeNode *res=Obj.lowestCommonAncestor(root,p,q);

  cout<<res->val;
}

//Function to create the binary tree
TreeNode  *create(){
  int val,choice;
  TreeNode  *node;
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