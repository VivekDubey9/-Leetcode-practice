//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,vector<int> &prices,int buy,vector<vector<int>> &dp){
        if(i>=prices.size())return 0;
        int ans=0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy==0){
            ans = max(-prices[i]+solve(i+1,prices,1,dp),solve(i+1,prices,0,dp));
        }
        else if(buy==1){
            ans = max(solve(i+1,prices,1,dp),prices[i]+solve(i+1,prices,0,dp));
        }
        return dp[i][buy] = ans;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int> > dp(n,vector<int>(2,-1));
        return solve(0,prices,0,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends