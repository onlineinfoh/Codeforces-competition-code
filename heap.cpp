#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& vec, int len, int cur){ 
	int largest = cur;
	int l = cur*2+1;
	int r = cur*2+2;
	if(l<len && vec[l]>vec[largest])
		largest = l;
	if(r<len && vec[r]>vec[largest])
		largest = r;
	if(largest!=cur){
		swap(vec[cur], vec[largest]);
		heapify(vec, len, largest);
	}
}

void heapSort(vector<int>& vec, int len){
	// start with the last element that can possibly have children
	for(int a = len/2 -1; a>=0; a--){
		heapify(vec, len, a);
	}
	for(int a = len-1; a>=0; a--){
		swap(vec[a], vec[0]);
		heapify(vec, a, 0);
	}
}

int main() {
	int len; cin>>len;
	vector<int> vec(len);
	for(int a = 0; a< len; a++){
		cin>>vec[a];
	}
	heapSort(vec, len);

	for(int i: vec) cout<<i<<" ";
}
