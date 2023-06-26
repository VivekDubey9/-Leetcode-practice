//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],int lo,int mid,int hi){
        long long int left = lo;
        long long int right = mid+1;
        vector<long long int> temp;
       long long  int cnt=0;
        while(left<=mid && right<=hi){
            if(arr[left]<=arr[right]){
                
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt+= (mid-left+1);
                right++;
            }
            
        }
        while(left<=mid)temp.push_back(arr[left++]);
        while(right<=hi)temp.push_back(arr[right++]);
        for(int i=lo;i<=hi;i++){
            arr[i] = temp[i-lo];
        }
        return cnt;
        
    }
    long long int mergeSort(long long arr[],int lo,int hi){
        long long int cnt=0;
        if(lo>=hi)return cnt;
        long long int mid = (lo+hi)/2;
        
        cnt+=mergeSort(arr,lo,mid);
        cnt+=mergeSort(arr,mid+1,hi);
        cnt+=merge(arr,lo,mid,hi);
        return cnt;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends