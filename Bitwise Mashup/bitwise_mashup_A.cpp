// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll cases; cin>>cases;
	while(cases--){
		ll len; cin>>len;
		ll ans; cin>>ans;
		for(ll a = 1; a< len; a++){
			ll tem; cin>>tem;
			ans&=tem;
		}
		cout<<ans<<endl;
	}
}
