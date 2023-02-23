#include <bits/stdc++.h>

using namespace std;
void Input(vector<int> adj[],int m){
    cout<<"Enter the egdes between the nodes\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        cout<<u<<"----"<<v<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return;
}
void DFS(int node,vector<int> adj[], int visited[], vector<int> &ls){
    visited[node]=1;
    ls.push_back(node);
    for(auto it : adj[node]){
        if(!visited[it])
            DFS(it,adj,visited,ls);
    }
}
vector<int> DFS_Traversal(int n,vector<int> adj[]){
    int visited[n+1]={0};
    int start=1;//Starting node
    vector<int>ls;
    DFS(start,adj,visited,ls);
    return ls;
}

int main()
{
    int n,m;
    cout<<"First we will take input for graph";
    cout<<"\nEnter number of nodes : ";
    cin>>n;
    cout<<"\nEnter number of edges : ";
    cin>>m;
    vector <int> adj[n+1];
    Input(adj,m);
    vector<int> ls=DFS_Traversal(n,adj);
    cout<<"\nTraversed Graph : ";
    for(auto it : ls){
        cout<<it;
    }
    return 0;
}
