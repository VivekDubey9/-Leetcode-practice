//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> &height,int n,vector<int> &dp){
        if(n==0)return 0;
        if(n<0)return 0;
        //cout<<dp[n]<<"-> ";
        //cout<<endl;
        if(dp[n]!=-1)return dp[n];  //memoization step
        int ss = INT_MAX;
        int fs = solve(height,n-1,dp) + abs(height[n]-height[n-1]);
        if(n-2>=0)
         ss = solve(height,n-2,dp)+abs(height[n]-height[n-2]);
        return dp[n]=min(fs,ss);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,0);
       // return solve(height,n,dp);
       dp[0]=0;
      
       for(int i=1;i<n;i++){
           
           int fs = dp[i-1]+abs(height[i]-height[i-1]);
           int ss = INT_MAX;
           if(i-2>=0)
            ss = dp[i-2]+abs(height[i]-height[i-2]);
           dp[i] = min(fs,ss);
       }
       return dp[n-1];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends