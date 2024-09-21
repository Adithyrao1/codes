#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<pair<ll,ll>>
#define pb push_back
#define mod 998244353
#define MOD 1000000007
#define ll long long
#define inf LLONG_MAX
#define for0(i,n) for(ll i=0;i<n;i++)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define all(x) begin(x),end(x)
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define tc(t) ll t ; cin>>t ; while(t--)
vector<int> ngeleft(vector<int>& arr) {
	
	int n  = arr.size();
	stack <int> st;
	
	vector<int> ans(n);
	ans[0]=-1;
	st.push(arr[0]);
	
	for(int i = 1 ;i < n ; i ++) {
		
		while(!st.empty() && st.top() <= arr[i]) st.pop();
		
		if(!st.empty()) ans[i] = st.top();
		else ans[i] = -1;
		
		st.push(arr[i]);
	}
	return ans;
}
vector<int> ngeright(vector<int>& arr) {
	
	int n = arr.size();
	
	vector<int> ans(n);
	ans[n-1]=-1;
	
	stack<int> st;
	st.push(arr[n-1]);
	
	for(int i = n-2;  i>= 0 ; i--) {
		
		while(!st.empty() && st.top() <= arr[i]) st.pop();
		
		if(!st.empty()) ans[i] = st.top();
		else ans[i] = -1;
		
		st.push(arr[i]);
	}
	
	return ans;
}
int main() {
	
	
	vector<int> arr = {9,12,6,13,8,2,0};
	vector<int> ans = ngeleft(arr);
	vector<int> ans2 = ngeright(arr);
	
	for(int c: ans) cout<<c<<" ";
	cout<<endl;
	for(int c: ans2) cout<<c<<" ";
	
	
	return 0;
}