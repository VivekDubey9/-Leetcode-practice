//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(m < n ) return kthElement(nums2,nums1,m,n,k);
        int n1 = n;
        int n2 = m;
       // cout<<n<<m<<endl;
        int lo = max(0,k-m) , hi = min(k,n);
        int ans=0;
        while(lo <= hi){
            int cut1 = (lo+hi) /2;
            int cut2 = k - cut1;
            if(cut2<0)cut2=0;
            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1];

            int r1 = cut1==n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2==n2 ? INT_MAX : nums2[cut2];

            if(l1<=r2 && l2<=r1){
               return max(l1,l2);
            }
            else if(l1>r2){
                hi = cut1-1;
            }
            else lo = cut1+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends