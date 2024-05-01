#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create();

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      queue<TreeNode *> queueTemp;
      string result="",temp,str;
      int val,size;

      if(root!=NULL){  //checking if the root of the binary tree is pointing to null or not
        temp="";
        val=root->val;

        if(root->val<0){
          temp+='-';
          val=val*(-1);  
        }
        
        str="";
        while(true){
          str+=(val%10)+'0';
          val=val/10;
          if(val==0)
          break;
        }

        reverse(str.begin(),str.end());
        temp+=str;
        result+=temp;

        if(root->left==NULL)
        result+=(",#");
        else{
          temp="";
          val=root->left->val;

          if(val<0){
          temp+='-';
          val=val*(-1);  
          }
        
          str="";
          while(true){
          str+=(val%10)+'0';
          val=val/10;
          if(val==0)
          break;
          }

          reverse(str.begin(),str.end());
          temp+=str;
          result+=','+temp; 
          queueTemp.push(root->left); 
        }


        if(root->right==NULL)
        result+=(",#");
        else{
          temp="";
          val=root->right->val;

          if(val<0){
          temp+='-';
          val=val*(-1);  
          }
        
          str="";
          while(true){
          str+=(val%10)+'0';
          val=val/10;
          if(val==0)
          break;
          }

          reverse(str.begin(),str.end());
          temp+=str;
          result+=','+temp; 
          queueTemp.push(root->right); 
        }
      }

      while(!queueTemp.empty()){
        size=queueTemp.size();
        while(size>0){
            
            if(queueTemp.front()->left==NULL)
            result+=(",#");
            else{
              temp="";
              val=queueTemp.front()->left->val;

              if(val<0){
              temp+='-';
              val=val*(-1);  
              }
        
              str="";
              while(true){
              str+=(val%10)+'0';
              val=val/10;
              if(val==0)
              break;
            }

            reverse(str.begin(),str.end());
            temp+=str;
            result+=','+temp; 
            queueTemp.push(queueTemp.front()->left); 
           }

            if(queueTemp.front()->right==NULL)
            result+=(",#");
            else{
              temp="";
              val=queueTemp.front()->right->val;

              if(val<0){
              temp+='-';
              val=val*(-1);  
              }
        
              str="";
              while(true){
              str+=(val%10)+'0';
              val=val/10;
              if(val==0)
              break;
            }

            reverse(str.begin(),str.end());
            temp+=str;
            result+=','+temp; 
            queueTemp.push(queueTemp.front()->right); 
           }       

          queueTemp.pop();
          size--;  
        }
      }
      return result;  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if(data.size()==0)  //if the string is empty then return NULL since the binary tree is empty
      return NULL;

      queue<TreeNode *> queueTemp;
      int i=0,val=0,sign=1,size;
      TreeNode *root;
      if(data[i]=='-'){
        sign=-1;
        i++; 
      }

      while(i<data.size() && data[i]!=','){
        val=val*10+data[i]-'0';
        i++;
      }
      i++;
      val=val*sign;
      root=new TreeNode(val);
      queueTemp.push(root);

      while(!queueTemp.empty() && i<data.size()){
        size=queueTemp.size();
        while(size>0){

          if(data[i]!='#'){
            val=0,sign=1;
            
            if(data[i]=='-'){
            sign=-1;
            i++; 
            }
   
            while(data[i]!=','){
            val=val*10+data[i]-'0';
            i++;
            }
            i++;

             val=val*sign;
             queueTemp.front()->left=new TreeNode(val);
             queueTemp.push(queueTemp.front()->left);
          }else{
            i+=2;
          }

          if(data[i]!='#'){
            val=0,sign=1;
            
            if(data[i]=='-'){
            sign=-1;
            i++; 
            }
   
            while(data[i]!=','){
            val=val*10+data[i]-'0';
            i++;
            }
            i++;

             val=val*sign;
             queueTemp.front()->right=new TreeNode(val);
             queueTemp.push(queueTemp.front()->right);
          }else{
            i+=2;
          }

          queueTemp.pop();
          size--;
        }
      }
      return root;
    }
};

int main(){
  TreeNode *root1=create(),*root2=NULL;
  Codec Obj;
  
  cout<<Obj.serialize(root1)<<endl;

  cout<<Obj.serialize(root2);
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
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));