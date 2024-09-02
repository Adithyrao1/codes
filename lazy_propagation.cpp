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

int arr[100001];
int seg[4*100001], lazy[4*100001];

void build(int si, int ss, int se) {
    if (ss == se) {
        seg[si] = arr[ss];
        return;
    }
    
    int mid = (ss + se) >> 1;
    build(2*si, ss, mid);
    build(2*si + 1, mid + 1, se);
    
    seg[si] = seg[2*si] + seg[2*si + 1];
}

void update(int si, int ss, int se, int l, int r, int val) {
    if (lazy[si] != 0) {
        int dx = lazy[si];
        lazy[si] = 0;
        
        seg[si] += (se - ss + 1) * dx;
        
        if (ss != se) {
            lazy[2*si] += dx;
            lazy[2*si + 1] += dx;
        }
    }
    
    if (ss > r || se < l) return;
    
    if (ss >= l && se <= r) {
        int dx = (se - ss + 1) * val;
        seg[si] += dx;
        
        if (ss != se) {
            lazy[2*si] += val;
            lazy[2*si + 1] += val;
        }
        return;
    }
    
    int mid = (ss + se) >> 1;
    update(2*si, ss, mid, l, r, val);
    update(2*si + 1, mid + 1, se, l, r, val);
    
    seg[si] = seg[2*si] + seg[2*si + 1];
}

int query(int si, int ss, int se, int qs, int qe) {
    if (lazy[si] != 0) {
        int dx = lazy[si];
        lazy[si] = 0;
        
        seg[si] += (se - ss + 1) * dx;
        
        if (ss != se) {
            lazy[2*si] += dx;
            lazy[2*si + 1] += dx;
        }
    }
    
    if (ss > qe || se < qs) return 0;
    
    if (ss >= qs && se <= qe) {
        return seg[si];
    }
    
    int mid = (ss + se) >> 1;
    return query(2*si, ss, mid, qs, qe) + query(2*si + 1, mid + 1, se, qs, qe);
}

int main() {
    ll n, q, q_type, l, r, val;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    build(1, 0, n - 1);
    
    while (q--) {
        cin >> q_type;
        
        if (q_type == 1) {
            cin >> l >> r >> val;
            update(1, 0, n - 1, l, r, val);
        } else if (q_type == 2) {
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }
    
    return 0;
}
