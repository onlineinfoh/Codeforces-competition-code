#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#include<vector>
# include<algorithm>
# include<map>
typedef long long ll;

void op(vector<bool> vec, int a, int b){
	int tem1 = 0;
	for(int i = 0; i< a; i++){
		if(vec[i] = true){
			tem1 = i;
			break;
		}
	}
	int tem2 = 0;
	for(int i = a-1; i>= 0; i--){
		if(vec[i] = true){
			tem2 = i;
			break;
		}
	}
	for(int i = tem1; i<= tem2; i++){
		vec[i] = true;
	}
}

int main() {
	int cas;
	cin>>cas;
	for(int hi = 0; hi< cas; hi++){
		int a, b;
		cin>>a>>b;
		vector<bool> W_col(b);
		vector<bool> W_row(a);
		vector<bool> B_col(b);
		vector<bool> B_row(a);
		for(int i = 0; i< a; i++){
			W_row[i] = false;
			B_row[i] = false;
		}
		for(int i = 0; i< b; i++){
			W_col[i] = false;
			B_col[i] = false;
		}
		for(int i = 0; i< a; i++){
			string s;
			cin>>s;
			for(int j = 0; j< b; j++){
				if(s[j] == 'B'){
					B_col[j] = true;
					B_row[i] = true;
			}
				else{
					W_col[j] = true;
					W_row[i] = true;
				}
			}
		}

		op(B_col, a, b);op(W_col, a, b);op(B_row, a, b);op(W_row, a, b);


		bool okB = true;
		bool okW = true;

		for(int i = 0; i< a; i++){
			if(B_row[i] == false){
				okB = false;
			}
			if(W_row[i] == false){
				okW = false;
			}
		}
		for(int i = 0; i< b; i++){
			if(B_col[i] == false){
				okB = false;
			}
			if(W_col[i] == false){
				okW = false;
			}
		}
		if(okB || okW){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}




/*int cas;
	cin>>cas;
	for(int hi = 0; hi< cas; hi++){
		int len;
		cin>>len;
		map<int, int> map;
		for(int i = 0; i< len; i++){
			int num; cin>>num;
			if(map.find(num) != map.end()){
				map[num]++;
			}
			else{
				map[num] = 1;
			}
		}
		int hold = 0;
		for(const auto& pair:map){
			hold++;
		}
		if(hold%2 == 1){
			cout<<"Alice"<<endl;
		}
		else{
			cout<<"Bob"<<endl;
		}
	}
	return 0;*/
