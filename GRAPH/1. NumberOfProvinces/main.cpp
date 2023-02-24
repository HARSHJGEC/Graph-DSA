#include <bits/stdc++.h>

using namespace std;
class Solution {
private:
    void BFS(int node,vector<int> &visited, vector<int> adj[]){
        visited[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            node=q.front();
            q.pop();
            for(auto &it:adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        return;
    }
    void DFS(int city,vector<int> &visited, vector<int> adj[]){
        visited[city]=1;
        for(auto it: adj[city]){
            if(!visited[it])
                DFS(it,visited,adj);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(isConnected[row][col]==1 && row!=col){
                    adj[row].push_back(col);
                    adj[col].push_back(row);
                }
            }
        }
        int provinces=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                //BFS(i,visited,adj);
                DFS(i,visited,adj);
            }
        }
        return provinces;
    }
};

int main() {

    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };


    Solution ob;
    cout << ob.findCircleNum(adj) << endl;


    return 0;
}
