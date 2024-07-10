#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, len; cin>>n>>len;
    vector<vector<pair<int, int>>> adj(n+1); //<to, weight>
    for(int a = 0; a< len; a++){
        int from, to, weight; cin>>from>>to>>weight;
        adj[from].push_back({to, weight});
    }
    vector<int> dis(n+1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <toReachDis, curNode>

    dis[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        int curDis= pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curDis > dis[curNode])
            continue;

        for(auto it: adj[curNode]){
            if(dis[curNode]+it.second < dis[it.first]){
                dis[it.first] = curDis+it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }

    cout<<"Starting node: 1"<<endl;
    for(int a = 1; a<= n; a++){
        cout<<"From 1 to "<<a<<", distance is "<<dis[a]<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("filein.txt", "r", stdin);
    solve();
    return 0;
}