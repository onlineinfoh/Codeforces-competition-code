// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll len, k; cin>>len>>k;
	vector<ll> value(len);
	vector<ll> awake(len);
	for(int a = 0; a< len; a++) cin>>value[a];
	for(int a = 0; a< len; a++) cin>>awake[a];
	if(k==len){
		ll sum  =0;
		for(int a = 0; a< len; a++){
			sum+=value[a];
		}
		cout<<sum;
		return 0;
	}
	vector<ll> preSum(len);
	preSum[0] = awake[0] == 1 ? 0 : value[0];
	//cout<<preSum[0]<<" ";
	for(int a = 1; a< len; a++){
		preSum[a]+=preSum[a-1];
		preSum[a]+=awake[a]==1?0:value[a];
		//cout<<preSum[a]<<" ";
	}
	ll ans = 0;
	for(int a = 0; a< len; a++){
		ans+=awake[a]==0?0:value[a];
	}
	ll tem = 0;
	for(int a = 0; a<= len-k; a++){
		tem = max(tem, preSum[a+k-1]- (a-1 == -1 ? 0 : preSum[a-1]) );
	}
	cout<<(ans+tem);
}
