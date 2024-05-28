// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
	int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;   
        set<int> ans[105][105];
        int arr[105][105];
        for(int i = 0; i< a; i++){
            for(int j = 0; j< b; j++){
                cin>>arr[i][j];
            }
        }

        ans[0][0].insert(arr[0][0]);
        
        for(int i = 0; i< a; i++){
            for(int j = 0; j< b; j++){
                if(i == 0 && j != 0){
                    for(int num: ans[i][j-1])
                    ans[i][j].insert(gcd(arr[i][j], num));
                }
                if(i != 0 && j == 0){
                    for(int num: ans[i-1][j])
                    ans[i][j].insert(gcd(arr[i][j], num));
                }
                if(i != 0 && j != 0){
                    for(int num: ans[i-1][j])
                    ans[i][j].insert(gcd(arr[i][j], num));
                    
                    for(int num: ans[i][j-1])
                    ans[i][j].insert(gcd(arr[i][j], num));
                }
            }
        }

        int hi = 0;
        for(int num: ans[a-1][b-1]) hi = max(hi, num);
        
        cout<<hi<<endl;
    }
}