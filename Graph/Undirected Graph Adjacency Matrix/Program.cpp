#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

void graphDisplay(vector<vector<int>> &,int);  //function prototype to display the graph in form of adjacency matrix
void BFS(vector<vector<int>> &,int *,int,int);  //function prototype for BFS traversal of the graph
void DFS(vector<vector<int>> &,int *,vector<int> &,int,int,stack<int> &);  //function prototype for DFS traversal of the graph

int main(){
  int nodes,edges,choice,startNode;
  cout<<"\nEnter number of nodes of the graph : ";
  cin>>nodes;
  cout<<"\nEnter number of edges of the graph : ";
  cin>>edges;  

  int nodesValues[nodes];
  cout<<"\nStart entering the values of the nodes (nodes index starting from 0 )\n";
  
  for(int i=0;i<nodes;i++){
    cout<<"\nEnter the nodes value of node "<<i<<" : ";
    cin>>nodesValues[i]; 
  }

  vector<vector<int>> adjacencyMatrix(nodes,vector<int>(nodes,0));

  for(int i=0;i<nodes;i++){
    for(int j=0;j<nodes;j++){
      cout<<"\nEnter edge weight from the node "<<nodesValues[i]<<" to node "<<nodesValues[j]<<" : ";
      cin>>adjacencyMatrix[i][j];
    }
  }

  do{
    system("cls");
    cout<<"_ _ _ _ _ _MENU_ _ _ _ _ _\n";
    cout<<"\n1) Display the graph";
    cout<<"\n2) BFS traversal";
    cout<<"\n3) DFS traversal\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;

    switch(choice){

      case 1: graphDisplay(adjacencyMatrix,nodes);
              break;

      case 2: cout<<"\nEnter the starting node from which you want to use for BFS traversal : ";
              cin>>startNode;
              BFS(adjacencyMatrix,nodesValues,startNode,nodes);
              break;
      
      case 3: cout<<"\nEnter the starting node from which you want to use for BFS traversal : ";
              cin>>startNode;
              for(int i=0;i<nodes;i++){
                if(nodesValues[i]==startNode){
                  stack<int> stackTemp;
                  vector<int> isVisited(nodes,0);
                  DFS(adjacencyMatrix,nodesValues,isVisited,i,nodes,stackTemp);
                  break;                 
                }
              }
              break;
      
      default: cout<<"\nInvalid input";
    }
    cout<<"\nPress 1 to continue and any other kay to exit : ";
    cin>>choice;
  }while(choice==1);
}

void graphDisplay(vector<vector<int>> &adjacencyMatrix,int nodes){  //function definition to display the graph in form of adjacency matrix
  for(int i=0;i<nodes;i++){
    for(int j=0;j<nodes;j++){
      cout<<adjacencyMatrix[i][j]<<"   ";
    }
    cout<<"\n";
  }
}

void BFS(vector<vector<int>> &adjacencyMatrix,int *nodesValues,int startNode,int nodes){  //function prototype for BFS traversal of the graph
  vector<int> isVisited(nodes,0);
  queue<int> queueTemp;

  for(int i=0;i<nodes;i++){
    if(nodesValues[i]==startNode){
      queueTemp.push(i);
      isVisited[i]=1;
      break;
    }
  }

  while(!queueTemp.empty()){
    cout<<nodesValues[queueTemp.front()]<<" ";

    for(int i=0;i<nodes;i++){
      if(adjacencyMatrix[queueTemp.front()][i]==1 && isVisited[i]==0){
        queueTemp.push(i);
        isVisited[i]=1;
      }
    }

    queueTemp.pop();
  }
}

void DFS(vector<vector<int>> &adjacencyMatrix,int *nodesValues,vector<int> &isVisited,int i,int nodes,stack<int> &stackTemp){  //function prototype for DFS traversal of the graph
  
  cout<<nodesValues[i];
  isVisited[i]=1;
  stackTemp.push(i);

  for(int j=0;j<nodes;j++){
    if(adjacencyMatrix[i][j]!=0 && isVisited[j]!=1){
      DFS(adjacencyMatrix,nodesValues,isVisited,j,nodes,stackTemp);
    }
  }
  stackTemp.pop();
}