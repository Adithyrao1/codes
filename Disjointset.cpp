#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector <int> rank,parent;
public:
	DisjointSet(int n) {
		rank.resize(n+1,0);
		parent.resize(n+1);
		for(int i=0;i<n+1;i++) {
			parent[i] = i;
		}
	}
	int findUpar(int node) {
		if(parent[node]==node) return node;
     return parent[node] = findUpar(parent[node]);
	}
	void unionByrank(int u,int v) {
		int ulp_u = findUpar(u);
		int ulp_v = findUpar(v);
		if(ulp_u == ulp_v) return;
		if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
		else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
		else {
			parent[ulp_v]  = ulp_u;
			rank[ulp_u]++;
		}
	}
};
int main() {
	DisjointSet ds(7);
	ds.unionByrank(1,2);
	ds.unionByrank(2,3);
	ds.unionByrank(4,5);
	if(ds.findUpar(1) == ds.findUpar(7)) cout<<"Same"<<endl;
	else cout<<"Not Same"<<endl;
	ds.unionByrank(6,7);
	ds.unionByrank(5,6);
	ds.unionByrank(3,7);
	cout<<endl<<endl;
	if(ds.findUpar(1) == ds.findUpar(7)) cout<<"Same"<<endl;
	else cout<<"Not Same"<<endl;
	return 0;
}