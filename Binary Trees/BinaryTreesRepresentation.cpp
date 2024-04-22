#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Self referential struct to represent the binary tree
struct Node
{
  int data;
  struct Node *left,*right;
  Node(int d){
    data=d;
    left=nullptr;
    right=nullptr;
  }
}typedef Tree;

Tree *create();
void inorderRecursive(Tree *);
void preorderRecursive(Tree *);
void postorderRecursive(Tree *);
void levelOrderTraversal(Tree *);
void inorderIterative(Tree *);
void preorderIterative(Tree *);

//Main function
int main(){
  Tree *root=nullptr;
  root=create();
  int choice;
  do{
    system("clear");
    cout<<"\n_ _ _ _ _ _MENU_ _ _ _ _ _\n";
    cout<<"\n1) In-order traversal using recursion";
    cout<<"\n2) Pre-order traversal using recursion";
    cout<<"\n3) Post-order traversal using recursion";
    cout<<"\n4) Level-order (BFS) traversal ";
    cout<<"\n5) In-order traversal with out recursion";
    cout<<"\n6) Pre-order traversal with out recursion";
    cout<<"\n7) Post-order traversal with out recursion\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    switch(choice){

      case 1: inorderRecursive(root);
              break;

      case 2: preorderRecursive(root);
              break;
      
      case 3: postorderRecursive(root);
              break;

      case 4: levelOrderTraversal(root);
              break;
      
      case 5: inorderIterative(root);
              break;   

      case 6: preorderIterative(root);
              break;
  
      default: cout<<"\nInvalid Input !";
               break;
    }
    cout<<"\nPress 1 to continue and any other key to exit : ";
    cin>>choice;
  }while(choice==1);
}

//Function to create the binary tree
Tree *create(){
  int val,choice;
  Tree *node;
  cout<<"\nEnter the data value of the node : ";
  cin>>val;
  node=new Tree(val);

  cout<<"\nPress 1 if you want to have left child of "<<node->data<<" : ";
  cin>>choice;
  
  if(choice==1)
  node->left=create();

  cout<<"\nPress 1 if you want to have right child of "<<node->data<<" : ";
  cin>>choice;

  if(choice==1)
  node->right=create();

  return node;
}

//Function to traverse the binary tree in-order using recursion
void inorderRecursive(Tree *root){
  if(root==nullptr)
  return;

  inorderRecursive(root->left);
  cout<<root->data<<" ";
  inorderRecursive(root->right);
}

//Function to traverse the binary tree Pre-order using recursion
void preorderRecursive(Tree *root){
  if(root==nullptr)
  return;
  
  cout<<root->data<<" ";
  preorderRecursive(root->left);
  preorderRecursive(root->right);
}

//Function to traverse the binary tree post-order using recursion
void postorderRecursive(Tree *root){
  if(root==nullptr)
  return;
  
  preorderRecursive(root->left);
  preorderRecursive(root->right);
  cout<<root->data<<" ";
}

//Function to traverse the binary tree in level order traversal
void levelOrderTraversal(Tree *root){
  vector<Tree *> temp;
  queue<Tree *> tempQueue;
  
  if(root!=nullptr)
  tempQueue.push(root);
  
  while(!tempQueue.empty()){
    
    while(!tempQueue.empty()){
      temp.push_back(tempQueue.front());
      tempQueue.pop();
    }

    for(int i=0;i<temp.size();i++){
      
      if(temp[i]->left!=nullptr)
      tempQueue.push(temp[i]->left);

      if(temp[i]->right!=nullptr)
      tempQueue.push(temp[i]->right);

      cout<<temp[i]->data<<" ";
    }

    temp.clear();
  }
}

//Function to traverse the binary tree in inorder traversal without recursion
void inorderIterative(Tree *root){
   Tree *temp=root;
   stack<Tree *> stackTemp;

   while(temp!=nullptr || !stackTemp.empty()){
     
     if(temp==nullptr){
       cout<<stackTemp.top()->data<<" ";
       temp=stackTemp.top()->right;
       stackTemp.pop();
     }

     else{
       stackTemp.push(temp);
       temp=stackTemp.top()->left;
     }
   }
}

//Function to traverse the binary tree in preorder traversal without recursion
void preorderIterative(Tree *root){
  Tree *temp;
  stack<Tree *> stackTemp;
  stackTemp.push(root);
  while(!stackTemp.empty()){
     temp=stackTemp.top();
     stackTemp.pop();
     cout<<temp->data<<" ";
     
     if(temp->right!=nullptr)
     stackTemp.push(temp->right);

     if(temp->left!=nullptr)
     stackTemp.push(temp->left);
  }
}