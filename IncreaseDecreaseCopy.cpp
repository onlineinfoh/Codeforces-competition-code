#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int len; cin>>len;
        vector<ll> A(len);
        vector<ll> B(len+1);
        for(int a = 0; a< len; a++) cin>>A[a];
        for(int a = 0; a< len+1; a++) cin>>B[a];
        ll ans = 0;
        ll mini = 1e9;
        for(int a = 0; a< len; a++){
            int one = min(A[a], B[a]);
            int two = max(A[a], B[a]);
            if(B[len]>= one && B[len]<= two) mini = 0;
            else{
                mini = min(mini, min(abs(B[len]-one), abs(B[len]-two)));
            }
            ans+=abs(A[a]-B[a]);
        }

        cout<<ans+mini+1<<endl;
    }
}