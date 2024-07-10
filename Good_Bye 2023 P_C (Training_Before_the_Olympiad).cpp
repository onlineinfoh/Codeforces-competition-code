// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll t; cin>>t;
	while(t--){
		ll len; cin>>len;
		ll sum = 0;
		ll odd = 0;
		for(ll a = 0; a< len; a++){
			ll num; cin>>num;
			sum+=num;
			if(num%2==1) odd++;
			if(a==0){
				cout<<sum<<" ";
				continue;
			}
			if(odd==1) {cout<<sum-1<<" ";continue;}
			ll sub = 0;
			if(odd==2){
				sub = 0;
			}
			else{
				if(odd%3==1){
					sub = odd/3+1;
				}
				else{
					sub = odd/3;
				}
			}
			cout<<sum-sub<<" ";
		}
		cout<<endl;
	}
}
