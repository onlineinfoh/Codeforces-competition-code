#include <cstdio>

#include <bits/stdc++.h>
using namespace std;
#include<vector>
# include<algorithm>
typedef long long ll;

int main() {
	ll cas;
	cin>>cas;
	for(int a = 0; a< cas; a++){
		int x, y;
		cin>>x>>y;
		if(x == 1){cout<<y<<endl;continue;}
		for(int b = 30; b>=0; b--){
			if(pow(2, b)<= y){
				cout<< static_cast<int>((pow(2, b)-1)) << " ";
				cout<< static_cast<int>((y-(pow(2, b)-1)))<< " ";
				break;
			}
		}
		for(int c = 2; c< x; c++){
			cout<<"0 ";
		}
		cout<<endl;
	}
	return 0;
}
