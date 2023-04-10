//Function returning false if directed graph contains cycle


#include <bits/stdc++.h>
using namespace std;


bool dfs(int node,vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(dfs(it, adj, vis, pathVis) ==true) return true;
        }else if( pathVis[it] == 1){
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool usingTopo(int V, vector<int> adj[]) {
    //using Kahns algorithm
    vector<int> topo;
    vector<int> indegree(V, 0);

    for(int i=0;i<V;i++) {
        for(auto adjNode: adj[i]) {
            indegree[adjNode]++;
        }
    }
    
    //queue which stores all nodes with indegree 0
    queue<int> q;
    for(int i=0;i<V;i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        topo.push_back(node);
        
        for(auto adjNode: adj[node]) {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
    
    if(topo.size() != V) return true;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    // code here
    
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    
    for(int i=0;i<V;i++) {
        if(!vis[i]) {
            if(dfs(i,adj,vis,pathVis) == true) return true;
        }
    }
    return false;
}

//{ Driver Code Starts.

int main() {

    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << isCyclic(V, adj);
    return 0;
}

// } Driver Code Ends