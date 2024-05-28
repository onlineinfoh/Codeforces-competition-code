#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok = true;
vector<vector<ll>> edges(150005);

vector<bool> vis(150005);

ll node = 0;

ll dfs(ll num){
	ll con = 0;
	if(vis[num]) return 0;
	node++;
	vis[num] = true;
	con+=edges[num].size();
	for(ll v: edges[num]){
		if(!vis[v]){
			con+=dfs(v);
		}
	}
	return con;

}

int main() {
	ll len, pair;
	cin>>len>>pair;
	for(ll a = 0; a< pair; a++){
		ll l, r;
		cin>>l>>r;
		edges[l].push_back(r);
		edges[r].push_back(l);
	}
	for(ll a = 1; a<= len; a++){
		if(!vis[a]){
			node = 0;
			ll t = dfs(a);
			//if(node == 2  && t == 2) continue;
			if(node*(node-1) !=t ) ok = false;
		}
	}

	if(ok) cout<<"YES";
	else cout<<"NO";;

	return 0;
}
