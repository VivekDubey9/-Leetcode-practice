//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortedInsert(int x,stack<int> &st){
    if(st.empty()){
        st.push(x);
        return;
    }
    if(x>st.top()){
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    sortedInsert(x,st);
    st.push(y);
}
void solve(stack<int> &st){
    if(st.empty())return;
    int x = st.top();
    st.pop();
    solve(st);
    sortedInsert(x,st);
}
void SortedStack :: sort()
{
   solve(s);
   
}