//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(int N) {
        // Code here
        if(N==2)return 1;
        long long int middle ;
        bool flag = true;
        if(N%2==0){
            flag = false;
            middle = N-1;
            
        }
        else{
            middle = N;
        }
        long long x = middle;
           middle = middle/2;
            long long int ans = middle*(middle+1);
        if(flag==false){
            //long long int toadd = 2*(N-1)+1;
            ans+=N/2;
        }
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
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends