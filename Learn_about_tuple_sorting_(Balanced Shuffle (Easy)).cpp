// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin>>s;
	vector< tuple<int, int, string> > vec(s.length());
	int open = 0, close = 0;
	for(int a = 0; a < s.length(); a++) {
        get<0>(vec[a]) = open-close;
        get<1>(vec[a]) = -1 * static_cast<int>(a);
        get<2>(vec[a]) = string(1, s[a]);
        //cout<<get<0>(vec[a])<<" "<<get<1>(vec[a])<<" "<< get<2>(vec[a])<<endl;

        if(s[a] == '(') open++;
        else close++;
    }
	sort(vec.begin(), vec.end());
    for(tuple<int, int, string> t : vec) cout<< get<2>(t);
}
