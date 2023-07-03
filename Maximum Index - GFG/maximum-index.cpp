//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        stack<pair<int,int> > low, high;
        for(int i=0;i<n;i++){
            if(low.empty() || low.top().first > arr[i]){
                low.push({arr[i],i});
            }
            else{
                while(!high.empty() && high.top().first < arr[i]){
                    high.pop();
                }
                high.push({arr[i],i});
            }
        }
        int ans = 0;
        while(!low.empty() && !high.empty()){
            if(low.top().second < high.top().second && low.top().first <= high.top().first){
                ans = max(ans, high.top().second - low.top().second);
            }
            if(low.top().first > high.top().first){
                high.pop();
            }
            else{
                low.pop();
            }
            
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends