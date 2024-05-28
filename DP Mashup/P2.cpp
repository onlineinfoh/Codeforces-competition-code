#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll len, let; cin>>len>>let;
	string s; cin>>s;
	vector<string> letters(let);
	for(ll a = 0; a< let; a++) cin>>letters[a];
	vector<ll> dp(len);
	ll prev = 0;
	bool notfoundyet = true;
	for(ll a = 0; a< len; a++){
		if(find(letters.begin(), letters.end(), string(1, s[a])) != letters.end()){
			notfoundyet = false;
			if(prev == 0){
				dp[a] = a == 0? 1 : 1+dp[a-1];
			}
			else{
				dp[a] = dp[a-1]+prev+1;
				//dp[a] += dp[a-1];
			}
			prev += 1;
		}
		else{
			prev = 0;
			dp[a] = notfoundyet? 0 : dp[a-1];
		}
	}
	ll ans = 0; 
	//for(int a = 0; a< len; a++) cout<<dp[a]<<endl;
	cout<<dp[len-1];
}
