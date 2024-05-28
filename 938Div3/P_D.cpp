#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll cas;cin>>cas;
	for(ll hi = 0; hi< cas; hi++){
		ll n, m, k;cin>>n>>m>>k;
		vector<ll> vec1(n);vector<ll> vec2(m);
		map<ll, ll>map;
		for(ll a = 0; a< n; a++){
			cin>>vec1[a];
		}
		for(ll a = 0; a< m; a++){
			cin>>vec2[a];
			if(map.find(vec2[a]) != map.end()) map[vec2[a]]++;
			else map[vec2[a]] = 1;
		}
		ll valNum = 0;
		ll ans =0;
		for(int a = 0; a<= m-1; a++){
			if(map.find(vec1[a]) != map.end()){
				if(map[vec1[a]] >=1) valNum++;
				map[vec1[a]]--;
			}
		}
		if(valNum>=k) ans++;
		/*
		cout<<valNum<<endl;
		for(const auto& pair : map){
			cout<<pair.first<<": "<<pair.second<<"\t";
		}
		cout<<endl<<endl;
		*/

		for(int a = m-1; a< n-1; a++){
			

			if(map.find(vec1[a-m+1]) != map.end()){
				if(map[vec1[a-m+1]]>=0) valNum--;
				map[vec1[a-m+1]]++;
			}
			
			if(map.find(vec1[a+1]) != map.end()){
				if(map[vec1[a+1]] >=1) valNum++;
				map[vec1[a+1]]--;
			}
			if(valNum>=k) ans++;

			/*
			cout<<valNum<<endl;

			
			for(const auto& pair : map){
				cout<<pair.first<<": "<<pair.second<<"\t";
			}
			cout<<endl<<endl;
			*/
			
		}

		// ** eliminate the case that vec2 has only length of 1 **
		cout<<ans<<endl;
	}
	return 0;
}
