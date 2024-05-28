#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok = true;

vector<vector<ll>> edges(150005);
vector<ll> sz(150005);
vector<ll> nedges(150005);
vector<ll> label(150005);

void relabel(ll l, ll changeto){
	if(label[l] == changeto) return;
	label[l] = changeto;

	for(ll v: edges[l]){
		relabel(v, changeto);
	}
}

void merge(ll l, ll r){
	edges[l].push_back(r);
	edges[r].push_back(l);

	ll label_l = label[l];
	ll label_r = label[r];

	nedges[label_r]+=1;

	if(label_l == label_r) return;

	// if the size of l is bigger, swap with r, together with the swap of label-type
	if(sz[label_l] > sz[label_r]){
		swap(l, r);
		swap(label_l, label_r);
	}
						// Because...
	relabel(l, label_r);// We are always merging aka changing l TO r
	// dfs starting from index l
	// (since we are changing all the labels that are related to l to r's label)

	sz[label_r]+=sz[label_l];
	sz[label_l]=sz[label_r];

	nedges[label_r]+=nedges[label_l];
	nedges[label_l]=nedges[label_r];

}

int main() {
	ll len, pair;
	cin>>len>>pair;
	for(ll a = 0; a<= len; a++){
		sz[a] = 1;
		label[a] = a;
	}

	for(ll a = 0; a< pair; a++){
		ll l, r;
		cin>>l>>r;
		merge(l, r);
	}


	for(ll a = 1; a<= len; a++){
		if(nedges[label[a]]*2 !=sz[label[a]]*(sz[label[a]]-1)){
			ok = false;
			break;
		}		
	}

	cout<<(ok ? "YES" : "NO");

	return 0;
}
