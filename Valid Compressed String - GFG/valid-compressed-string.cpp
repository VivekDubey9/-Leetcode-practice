//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int j=0,num=0;
       for(int i=0;i<T.size();i++){
           if(isdigit(T[i])){
               num = num*10 + T[i]-'0';
           }
           else {
               if(num!=0){
                   j+=num;
               }
               num=0;
               if(j>S.length() || 
               S[j]!=T[i])return 0;
               j++;
           }
           
       }
       j+=num;
       if(j!=S.length())return 0;
       return 1;
       
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends