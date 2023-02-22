//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
         queue<pair<int,pair<int,int> > > pq;
        //int n = flights.size();
        vector<pair<int,int> > adj[n];
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int price= it[2];
            adj[u].push_back({v,price});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        pq.push({0,{src,0}});
         //stops,node,distance
        while(!pq.empty()){
            int node = pq.front().second.first;
            int stops = pq.front().first;
            int d = pq.front().second.second;
              pq.pop();
            if(stops>k){
                continue;
            }
          
            for(auto it:adj[node]){
                int adjNode = it.first;
                int cost = it.second;
                if(stops<=k){
                    if(d+cost< dist[adjNode]){
                        dist[adjNode] = d+cost;
                        pq.push({stops+1,{adjNode,d+cost}});
                    }
                }

            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends