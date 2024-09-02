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

vi arr;
vi st;

void buildtree(int si, int ss, int se) {
    if (ss == se) {
        st[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    buildtree(2*si, ss, mid);
    buildtree(2*si+1, mid+1, se);
    st[si] = st[2*si] + st[2*si+1]; // Store sum of child nodes
}

ll query(int si, int ss, int se, int qs, int qe) {
    if (qs > se || ss > qe) return 0; // No overlap, return 0
    if (qs <= ss && qe >= se) return st[si]; // Total overlap, return node value

    int mid = (ss + se) / 2;

    ll l = query(2*si, ss, mid, qs, qe);
    ll r = query(2*si+1, mid+1, se, qs, qe);

    return l + r; // Return the sum of the ranges
}

void update(int si, int ss, int se, int qi) {
    if (ss == se) {
        st[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid) update(2*si, ss, mid, qi);
    else update(2*si+1, mid+1, se, qi);

    st[si] = st[2*si] + st[2*si+1]; // Update with the new sum
}

int main() {
    ll n, l, r,q;
   
        cin >> n >> q;
        arr.clear();
        arr.resize(n);
        st.clear();
        st.resize(4 * n);

        for0(i, n) cin >> arr[i];
        
        buildtree(1, 0, n - 1);
        while(q--) {
        cin >> l >> r ;
        cout << query(1, 0, n - 1, l, r) << endl;
         }
    return 0;
}
