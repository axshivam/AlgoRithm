// Prim's Algorithm by matrix representation of graph
#include<bits/stdc++.h>
using namespace std;
#define V 5
int minKey(int key[],bool mtSet[])
{
  int min=INT_MAX, min_index;
  for(int v=0;v<V;v++)
  {
    if(mtSet[v]==false && key[v]<min)
    {
      min = key[v],min_index=v;
    }
  }
  return min_index;
}
void printMST(int parent[],int graph[V][V])
{
  cout<<"Edge  Weight" <<endl;
  for(int i=1;i<V;i++)
  {
    cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
  }
}
void primMST(int graph[V][V])
{
  int parent[V],key[V];
  bool mtSet[V];
  for(int i=0;i<V;i++)
  {
    key[i]=INT_MAX, mtSet[i]=false;
  }
  key[0]=0;
  parent[0]=-1;
  for(int count=0;count<V-1;count++)
  {
    int u = minKey(key, mtSet);
    mtSet[u]=true;
    for(int v=0;v<V;v++)
    {
      if(graph[u][v]&& mtSet[v]==false && graph[u][v]<key[v])
      {
        parent[v]=u,key[v]=graph[u][v];
      }
    }
  }
  printMST(parent,graph);
}
int main()
{
  int graph[V][V] = {
    {0,2,0,6,0},
    {2,0,3,8,5},
    {0,3,0,0,7},
    {6,8,0,0,9},
    {0,5,7,9,0}
  };
  primMST(graph);
  return 0;
}
