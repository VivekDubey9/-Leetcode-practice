class DisjointSet {
    
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
    private:
    bool isValid(int adjr,int adjc,int n){
        return adjr<n && adjr>=0 && adjc<n && adjc>=0;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                    int node = i*n+j;
                    int dr[] ={-1,0,1,0};
                    int dc[] = {0,1,0,-1};
                    for(int ind =0;ind<4;ind++){
                        int adjr = i+dr[ind];
                        int adjc = j+dc[ind];
                        if(isValid(adjr,adjc,n) && grid[adjr][adjc]==1 ){
                            int newNode = adjr*n + adjc;
                            ds.unionBySize(node,newNode);
                        }
                    }
            }
        }
        //now change and store the value 
         int mx =0;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
               if(grid[i][j]==0){
                   set<int> st;
                    int dr[] ={-1,0,1,0};
                    int dc[] = {0,1,0,-1};
                    for(int ind =0;ind<4;ind++){
                        int adjr = i+dr[ind];
                        int adjc = j+dc[ind];
                        if(isValid(adjr,adjc,n) && grid[adjr][adjc]==1 ){
                            int newNode = adjr * n + adjc;
                            int x = ds.findUPar(newNode);
                            st.insert(x);
                            
                        }
                    }
                     int totalSize=0;
                   for(auto it:st){
                       totalSize+=ds.size[it];  
                   }
                   
                   mx = max(mx,totalSize+1);
                   
               }
            }
        }
        for(int i=0;i<n*n;i++){
            int x =ds.findUPar(i);
            mx = max(mx,ds.size[x]);
        }
        return mx;
        
        
        
        
    }
};