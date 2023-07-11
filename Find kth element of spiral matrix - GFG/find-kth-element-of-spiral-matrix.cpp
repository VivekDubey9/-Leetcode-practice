//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int mat[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int top=0,bottom = n-1,left = 0,right = m-1;
 		int dir=0;
 	    int cnt=0;
 	    vector<int> ans;
 		while(top<=bottom && left<= right){
 		    if(dir==0){ //left
 		        for(int i=left;i<=right;i++){
 		            cnt++;
 		            ans.push_back(mat[top][i]);
 		            if(cnt==k)return mat[top][i];
 		            
 		            
 		        }
 		        top++;
 		        dir=1;
 		        
 		    }
 		    else if(dir==1){
 		        for(int i=top;i<=bottom;i++){
 		            cnt++;
 		              ans.push_back(mat[i][right]);
 		            if(cnt==k)return mat[i][right];
 		            
 		        }
 		        right--;
 		        dir=2;
 		    }
 		    else if(dir==2){
 		        for(int i=right;i>=left;i--){
 		            cnt++;
 		            ans.push_back(mat[top][i]);
 		            if(cnt==k)return mat[bottom][i];
 		            
 		        }
 		        bottom--;
 		        dir=3;
 		    }
 		    else if(dir==3){
 		        for(int i=bottom;i>=top;i--){
 		            cnt++;
 		            if(cnt==k)return mat[i][left];
 		            
 		        }
 		        dir=0;
 		        left++;
 		    }
 		}
 		return 0;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends