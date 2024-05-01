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
 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      vector<vector<int>> ans;
      queue<pair<int,TreeNode *>> queueTemp;
      int position=0,size;
      unordered_map<int,vector<int>> temp;
      map<int,vector<int>> resultMap;

      if(root!=nullptr)
      queueTemp.push({0,root});

      while(!queueTemp.empty()){
        size=queueTemp.size();
        while(size>0){

          if(temp.find(queueTemp.front().first)==temp.end())
          temp[queueTemp.front().first]={queueTemp.front().second->val};

          else{
            vector<int> arr=temp[queueTemp.front().first];
            arr.push_back(queueTemp.front().second->val);
            temp[queueTemp.front().first]=arr;
          }

          if(queueTemp.front().second->left!=nullptr)
          queueTemp.push({queueTemp.front().first-1,queueTemp.front().second->left});

          if(queueTemp.front().second->right!=nullptr)
          queueTemp.push({queueTemp.front().first+1,queueTemp.front().second->right});

          size--;
          queueTemp.pop();
        }

        auto it=temp.begin();
        while(it!=temp.end()){
          if(resultMap.find(it->first)==resultMap.end())
          resultMap[it->first]=it->second;

          else{
            vector<int> arr=it->second;
            sort(arr.begin(),arr.end());
            vector<int> t=resultMap[it->first];
            for(int i=0;i<arr.size();i++)
              t.push_back(arr[i]);

            resultMap[it->first]=t;
          }
          it++;
        }

        temp.clear();
      }

      auto it=resultMap.begin();
      while(it!=resultMap.end()){
        ans.push_back(it->second);
        it++;
      }
      return ans;
    }
};

TreeNode *create();

//main function
int main(){
  TreeNode *root=create();
  vector<vector<int>> arr;
  Solution Obj;
  arr=Obj.verticalTraversal(root);

  cout<<"[ ";
  for(int i=0;i<arr.size();i++){
    cout<<"[ ";
    for(int j=0;j<arr[i].size();j++)
    cout<<arr[i][j]<<" ";
    cout<<"]";
  }
  cout<<" ]";
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