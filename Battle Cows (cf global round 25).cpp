// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
		int len, cur;
		cin>>len>>cur; --cur;

		vector<int> vec(len);
		for(int a = 0; a< len; a++) cin>>vec[a];
		int ans1 = 0; // case1, calculate the number of all smaller numbers before
		// (coz you can swap with the first cow so that you can beat the rest of them)

		int ans2 = 0; // case2, if there is a bigger cow before the current one
		// swap with it and calculate the number of cows after the cow after swaping that are smaller than it

		bool bigger = false; // is there a bigger value before 'this' value
		int bigger_index = 0; // the index of the number that is bigger than 'this' value

		for(int a = 0; a< len; a++){
			if(vec[a]<=vec[cur]){ // all the numbers that are smaller, or equal to itslef
			//	(because of the swap that is assumed in the question)

				ans1++;
			}
			else{
				if(a<cur){
					bigger = true;
					bigger_index = a;
				}
				break;
			}
		}

		if(bigger){
			swap(vec[cur], vec[bigger_index]);
			ans2+= bigger_index==0?0: 1; // if bigger_index is 0, that means there were no cows to be beaten before
			// else that means the current cow beat the previous winner

			for(int a = bigger_index+1; a< len; a++){
				if(vec[a] < vec[bigger_index]) ans2++;
				else break;
			}
			
		}
		
		cout<<max(ans1-1, ans2)<<endl; // ans1 minus 1 coz it can not beat itself
	}
}
