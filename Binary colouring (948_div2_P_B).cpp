// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
		vector<int> vec(32, 0);

		int num; cin>>num;

		for(int a = 31; a>=0; a--){
			if(num & (1<<a)){
				vec[a] = 1;
			}
		}
		
		bool prev_one = false;

		cout<<32<<endl;

		for(int a = 0; a<= 30; a++){
			if(vec[a]==1 && vec[a+1] == 1){
				if(!prev_one){
					vec[a] = -1;
					prev_one = true;
				}
				else{
					vec[a] = 0;
				}
			}
			else if(vec[a]==1 && vec[a+1] == 0){
				if(prev_one){
					vec[a] = 0;
					vec[a+1] = 1;
					prev_one = false;
				}
			}
		}

		for(int x:vec) cout<<x<<" ";
		cout<<endl;
	}
}
