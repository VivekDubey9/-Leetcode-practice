//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node,vector<int> adj[],int col,vector<int> &color){
        for(auto it:adj[node]){
            if(color[it]==col)return false;
        }
        return true;
        
    }
    bool dfs(int node,vector<int> adj[],int m,int n,vector<int> &color){
        
        if(node == n)return true;
        for(int i=1;i<=m;i++){
            if(isSafe(node,adj,i,color)){
                color[node]=i;
                if(dfs(node+1,adj,m,n,color) )return true;
                color[node]=0;
            }
        }
        return false;
            
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> color(n,0);
        if(dfs(0,adj,m,n,color))return true;
        else return false;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends