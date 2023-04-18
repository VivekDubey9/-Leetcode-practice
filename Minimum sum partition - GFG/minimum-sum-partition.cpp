//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	   //  int n = nums.size();
	   int totalsum=0;
        for(int i=0;i<n;i++)totalsum+=nums[i];
        vector<vector<int> > dp(n,vector<int>(totalsum+1,0));
        for(int i=0;i<n;i++)dp[i][0]=1;
        if(nums[0]<=totalsum)dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int target=1;target<=totalsum;target++){
                bool not_take = dp[i-1][target];
                bool take = false;
                if(nums[i]<=target){
                    take = dp[i-1][target-nums[i]];
                }
                dp[i][target] = take || not_take;
            }
        }
        int mini = 1e9;
        for(int i=0;i<=totalsum/2;i++){
            if(dp[n-1][i]==true){
                int diff = abs(i-(totalsum-i));
                mini = min(mini,diff);
            }
        }
        return mini;

	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends