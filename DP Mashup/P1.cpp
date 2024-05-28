#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll num;
	cin>>num;
	if(num%2 == 1) {cout<< 0;return 0;}
	cout<<fixed;
	cout<<(int)pow(2, num/2);
}
