#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> edges(100005);

vector<bool> visited(100005);

vector<ll> color(100005);

bool ok = true;

void dfs(ll cur, ll prev){ // this dfs perform color operations
	if (visited[cur]){
		return;
	}
	visited[cur] = true;

	color[cur] = 3-prev;

	for(ll num: edges[cur]){
		if(!visited[num]){
			dfs(num, color[cur]);
		}
		else{
			if(color[num] == color[cur]){
				ok = false;
			}
		}
	}
}

int main() {
	ll len, edge;
	cin>>len>>edge;

	for(int hi = 0; hi< edge; hi++){
		ll a, b;cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	for(int i = 1; i<= len; i++){
		dfs(i, 2);
	}

	if(!ok){
		cout<<-1;
	}
	else{
		ll a = 0;
		ll b = 0;
		for(ll i = 1; i<= len; i++){
			if(color[i] == 1) a++;
			else{b++;}
		}
		cout<<a<<endl;
		for(ll j = 1; j<= len; j++){
			if(color[j] == 1){
				cout<<j<<" ";
			}
		}
		cout<<endl;
		cout<<b<<endl;
		for(ll j = 1; j<= len; j++){
			if(color[j] == 2){
				cout<<j<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}
