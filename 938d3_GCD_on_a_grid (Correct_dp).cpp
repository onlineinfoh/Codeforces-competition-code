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

vector<int> generateDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end(), greater<int>());
    return divisors;
}

vector<int> gcdDivisors(int a, int b) {
    int gcdValue = gcd(a, b);
    return generateDivisors(gcdValue);
}

int main() {
	int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b; 
        int arr[105][105];
        for(int i = 0; i< a; i++){
            for(int j = 0; j< b; j++){
                cin>>arr[i][j];
            }
        }
        vector<int> divisors = gcdDivisors(arr[0][0], arr[a-1][b-1]);
        for(int x:divisors){
            if(gcd(arr[0][0], x) == min (arr[0][0], x) && gcd(arr[a-1][b-1], x) == min (arr[a-1][b-1], x)){  
                int ans[105][105]  ={0};
                ans[0][0]= 1;
                for(int i = 0; i< a; i++){
                    for(int j = 0; j< b; j++){
                        if(i>0){
                            if(arr[i][j]>=x && arr[i][j]%x==0)
                                ans[i][j] |= ans[i-1][j];
                        }
                        if(j>0){
                            if(arr[i][j]>=x && arr[i][j]%x==0)
                                ans[i][j] |= ans[i][j-1];
                        }
                    }
                }
                if(ans[a-1][b-1] == 1){
                    cout<<x<<endl;
                    break;
                }
            }
        }

    }
}