#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll inf = 1e17;
	ll len;
	cin>>len;
	ll dp[len+1][1<<3]; // dp[first i juice][bitmask of 1 to 7]  4+2+1
	// 0-index  1to7
	for(ll a = 0; a<= len; a++){
		for(ll b = 0; b< 8; b++){
			dp[a][b] = inf;
		}
	}
	// base case
	dp[0][0]=0; // no juice with no vitamin costs 0
	for(ll a = 0; a< len; a++){  // iterate through all juice options
	// a<len, not a<= len  because: 
	// except the last one
	// since we don't need to update the lastone+1 juice
		ll cost;
		string s;
		cin>>cost>>s;

		ll juiceType = 0;
		for(int i = 0; i<3; i++){
			bool have = false;
			for(char cc:s){
				char c = 'C'-i;
				if(c==cc){
					have = true;
				}
			}
			if(have) juiceType+=1<<i;
		}
		for(ll mask = 0; mask<8; mask++){
			dp[a+1][mask] = min(dp[a+1][mask], dp[a][mask]);
			dp[a+1][mask|juiceType] = min(dp[a+1][mask|juiceType], dp[a][mask]+cost);
		}
	}
	ll out = dp[len][7];
	if(out==inf) cout<<-1;
	else cout<<out;
}
