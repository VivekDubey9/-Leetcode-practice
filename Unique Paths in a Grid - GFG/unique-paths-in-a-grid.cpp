//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int UniquePathHelper(int i, int j, int r, int c,
                     vector<vector<int> >& A,
                     vector<vector<int> >& paths,int mod)
{
    // boundary condition or constraints
    if (i == r || j == c) {
        return 0;
    }
 
    if (A[i][j] == 0) {
        return 0;
    }
 
    // base case
    if (i == r - 1 && j == c - 1) {
        return 1;
    }
 
    if (paths[i][j] != -1) {
        return paths[i][j];
    }
    paths[i][j]
           = (UniquePathHelper(i + 1, j, r, c, A, paths,mod)
             + UniquePathHelper(i, j + 1, r, c, A, paths,mod))%mod;
 
    return paths[i][j]%mod;
}
 
int uniquePaths(int n,int m,vector<vector<int> >& A)
{
 
    int r = A.size(), c = A[0].size();
 
    // create a 2D-matrix and initializing
    // with value 0
 
    vector<vector<int> > paths(r, vector<int>(c, -1));
     int mod = 1e9+7;
    int x = UniquePathHelper(0, 0, r, c, A, paths,mod);
   
 
    return x%mod;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends