#include <bits/stdc++.h>
using namespace std;
// 1-indexed
int main() {
	int t; cin>>t;
	while(t--){
		int n, m, k; cin>>n>>m>>k;
		string s; cin>>s;
		vector<char> vec;
		vec.push_back('L');
		for(char c: s) vec.push_back(c);
		vector<int> disSwan(n+1, 1e9);
		disSwan[0] = 0;
		vector<bool> poss(n+2); // addtional starting point and end point
		poss[0] = true;
		for(int i = 0; i<= n; i++){
			if(poss[n+1]) break;
			if(!poss[i]) continue;
			if(vec[i] == 'L'){
				for(int j = i+1; j<= min(i+m, n+1); j++){
					if(j == n+1){
						poss[n+1] = true;
						break;
					}
					// both for W, L
					poss[j] = true;
					disSwan[j] = min(disSwan[j], disSwan[i]);
				}
			}
			if(vec[i] == 'W'){
				int toSwim = disSwan[i]+1;
				if(toSwim<=k){
					poss[i+1] = true;
					disSwan[i+1] = min(disSwan[i+1], toSwim);
				}
			}
		}
		//for(int a = 0; a<=n; a++) cout<<disSwan[a]<<" ";
		cout<<(poss[n+1] ? "YES": "NO")<<endl;
	}
}