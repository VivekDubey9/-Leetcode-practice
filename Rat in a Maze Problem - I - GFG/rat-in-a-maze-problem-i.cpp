//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int row,int col,vector<vector<int> > &maze,int n,vector<string> &ans,
    vector<vector<int> > &vis,string str){
       // if(row>=n || col>=n)return;
        if(row==n-1 && col==n-1){
            ans.push_back(str);
            return;
        }
        //vis[row][col] = 1;
          if(row+1<n && maze[row+1][col]==1 && !vis[row+1][col]){
            vis[row][col]=1;
            solve(row+1,col,maze,n ,ans,vis,str+'D');
             vis[row][col]=0;
        }
          if(col-1>=0 && maze[row][col-1]==1 && !vis[row][col-1]){
            vis[row][col]=1;
            solve(row,col-1,maze,n ,ans,vis,str+'L');
            vis[row][col]=0;
        }
        
        if(col+1<n && maze[row][col+1]==1 && !vis[row][col+1]){
            vis[row][col]=1;
            solve(row,col+1,maze,n,ans,vis,str+'R');
            vis[row][col]=0;
        }
        if(row-1>=0 && maze[row-1][col]==1 && !vis[row-1][col]){
            vis[row][col]=1;
            solve(row-1 ,col,maze,n, ans,vis,str+'U');
            vis[row][col]=0;
            
        }
      
      
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0)return {"-1"};
        vector<vector<int> > vis(n,vector<int>(n,0));
        string str;
        vis[0][0]=1;
        solve(0,0,m,n,ans,vis,str);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends