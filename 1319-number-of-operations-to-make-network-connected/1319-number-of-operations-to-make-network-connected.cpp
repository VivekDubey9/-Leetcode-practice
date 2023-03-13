 

class DisjointSet {
    
public:
    vector<int> rank, parent;
   
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
         DisjointSet ds(n);
        int extras=0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)==ds.findUPar(v))extras++;
             ds.unionByRank(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i)cnt++;
        }
        
        //to count how many extra edges
     
       // cout<<extras<<"-> ";
       // cout<<cnt<<endl;
        if(extras<cnt-1)return -1;
        else return cnt-1;


        
        
        
    }
};