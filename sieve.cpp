#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int,int>
#define vi vector<ll>
#define vii vector<pair<ll,ll>>
#define pb push_back
#define mod 998244353
#define MOD 1000000007
#define inf INT_MAX
#define for0(i,n) for(int i=0;i<n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define all(x) begin(x),end(x)
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define tc(t) ll t ; cin>>t; while(t--)
ll N = 1e6;
vector<bool> isprime(N,true);

void sieve() {
	
	isprime[0] = isprime[1] = false;
	
	for(ll i = 2;  i * i <= N ; i++ ) {
		
		if(isprime[i]) {
			
			for(ll j = i * i  ; j <= N ; j+=i) {
				
				isprime[j] = false;
			}
		}
	}
}
int main()
{
	
	sieve();
	
	
    return 0;
}
