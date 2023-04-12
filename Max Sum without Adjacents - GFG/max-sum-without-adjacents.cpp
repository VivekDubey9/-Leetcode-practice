//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int *arr,int ind,int n,vector<int> &dp){
	    if(ind>=n) return 0;
	    if(dp[ind]!=-1)return dp[ind];
	    int take = arr[ind];
	    if(ind+2<n) take+=solve(arr,ind+2,n,dp);
	    int not_take = solve(arr,ind+1,n,dp);
	    return dp[ind] = max(take,not_take);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n+1,-1);
	    return solve(arr,0,n,dp);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends