// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<ll> edge[500005];
bool checked[500005];
ll ans[500005];

void solve(){
	ll ppl, grp; 
	cin >> ppl >> grp;
	for(ll a = 0; a< grp; a++){
		ll len;
		cin >> len;

		ll tem[len];
		for(ll b = 0; b< len; b++){
			cin >> tem[b];
			//--tem[b];
		}
		for(ll x = 0; x< len-1; x++){
			edge[tem[x]].push_back(tem[x+1]);
			edge[tem[x+1]].push_back(tem[x]);
		}
	}

	for(ll b = 1; b<= ppl; b++){
		if(!checked[b]){
			vector<ll> com;
			queue<ll> q;
			q.push(b);

			//bfs
			while(! q.empty()){
				ll num = q.front();
				q.pop();
				if(checked[num]) continue;
				checked[num] = 1;
				com.push_back(num);

				for(ll i: edge[num]){
					if(! checked[i]){
						q.push(i);
					}
				}
			}
			for(ll x : com){
				ans[x] = com.size();
			}
		}
	}

	for(ll v = 1; v<= ppl; v++){
		cout << ans[v]<<" ";
	}
}

int main() {
	solve();
	return 0;
}