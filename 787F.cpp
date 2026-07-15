#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll dist_x;

ll dfs(ll node,ll parent,ll x,ll depth,vector<vector<ll>> &adj,set<ll> &st){
    if(node==x) dist_x = depth;
    ll ans = 0;
    for(auto it:adj[node]){
        if(it==parent) continue;
        ll res = dfs(it,node,x,depth+1,adj,st);
        if(res==-1) continue;
        ans+=res;
    }
    if(ans==0){
        if(st.count(node)==0) return -1;
        else return 1;
    }
    return ans+1;
}

void solve() {  
    ll n,k;
    cin>>n>>k;
    ll x,y;
    cin>>x>>y;
    set<ll> st;
    for(ll i=0;i<k;i++){
        ll z;
        cin>>z;
        st.insert(z);
    } 
    st.insert(x);
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = dfs(y,-1,x,0,adj,st);
    ans--;
    cout<<(2*ans-dist_x)<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
