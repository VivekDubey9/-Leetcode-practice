//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


#define pii pair<int,int>
class Solution {
public:
    int minimumCost(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int> > adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii> > pq;
        pq.push({0,k});  //{dist,node}
        vector<int> dist(n+1,1e9);
        dist[k] =0;
        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                int newTime = it.second;
                if(dist[adjNode]>newTime +time){
                    dist[adjNode] = time+newTime;
                    pq.push({time+newTime,adjNode});
                }
            }
        }
        bool flag =0;
        int mn=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                flag=1;
                break;
            }
            mn = max(dist[i],mn);
            
        }
        if(flag)return -1;
        else return mn;

        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends