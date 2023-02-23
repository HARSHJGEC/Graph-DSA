#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;//n=node m=edges
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++)// No. of iteration= No. of edges
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));
    }
    return 0;
}
