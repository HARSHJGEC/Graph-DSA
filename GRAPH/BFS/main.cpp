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
vector<int> BFS_Traversal(int n, vector<int> adj[]){
    int visited[n+1]={0};
    visited[1]=1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
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
    vector<int> bfs=BFS_Traversal(n,adj);
    cout<<"\nTraversed Graph : ";
    for(auto it : bfs){
        cout<<it;
    }
    return 0;
}
