#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin>>t; while(t--){
		int len, pos; cin>>len>>pos; --pos;
		vector<ll> A(len);
		vector<ll> B(len);
		for(int a = 0; a< len; a++) cin>>A[a];
		for(int a = 0; a< len; a++) cin>>B[a];
		ll ans = 0;
		for(int a = len-1; a> pos; a--){
			ans+=min(A[a], B[a]);
		}
		
		ll mini = A[pos];
		ll bottom_counter = B[pos];
		for(int a = pos-1; a>=0; a--){
			mini = min(mini, A[a]+bottom_counter);
			bottom_counter += B[a];
		}

		cout<<(ans+mini)<<endl;
	}
}
