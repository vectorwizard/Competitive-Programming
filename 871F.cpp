#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> leaves;
    for(ll i=1;i<=n;i++){
        if(adj[i].size()==1) leaves.push_back(i);
    }
    ll leaf = leaves.size();
    set<ll> st;
    for(auto it:leaves){
        st.insert(adj[it][0]);
    }
    ll siz = st.size();
    cout<<siz<<" "<<(leaf/siz)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
