//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(vector<int> arr,int target,int ind,vector<vector<int>> &dp){
        if(target==0)return true;
        if(ind==0)return arr[0]==target;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool not_take = f(arr,target,ind-1,dp);
        bool take = false;
        
        if(arr[ind]<=target){
            take = f(arr,target-arr[ind],ind-1,dp);
        }
        return dp[ind][target]=take || not_take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int> > dp(arr.size(),vector<int>(sum+1,-1));
        return f(arr,sum,arr.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends