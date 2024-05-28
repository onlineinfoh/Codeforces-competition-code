#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll cas;cin>>cas;
	for(ll hi = 0; hi< cas; hi++){
		ll len, k;cin>>len>>k;
		vector<ll> vec(len);
		for(int a = 0; a< len; a++){
			cin>>vec[a];
		}
		ll l, r;
		l = 0;r = len-1;
		ll ans = 0;

		while(l<=r){
			if(vec[l] == vec[r]){
				if(l==r){
					if(vec[l]>k) break;
					else ans++;
					break;
				}

				if(vec[l]*2>k){
					if(vec[l]*2==k+1) ans++;
					break;
				}
				else{
					
					k-=vec[l]*2;
					ans+=2;
				}
				l++;
				r--;
			}
			else if(vec[l]< vec[r]){
				if(vec[l]*2>k){
					if(vec[l]*2-1 == k) ans++;
					break;
				}
				else{
					k-=vec[l]*2;
					vec[r] = vec[r]-vec[l];
					ans++;
				}
				l++;
			}
			else{
				if(vec[r]*2>k){
					break;
				}
				else{
					k-=vec[r]*2;
					vec[l] = vec[l]-vec[r];
					ans++;
				}
				r--;
			}

			if(k == 0) break;
		}

		cout<<ans<<endl;
	}
}
