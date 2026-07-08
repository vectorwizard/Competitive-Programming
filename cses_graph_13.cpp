#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<priority_queue<pair<int,int>>> dist(n+1);
    
}  

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
