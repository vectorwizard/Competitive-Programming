#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll ans = 0;

bool func(ll x){
    ll r = round(sqrt(x));
    if((r*r)==x) return true;
    return false;
}

ll dfs(ll node,ll par,vector<vector<ll>> &adj,ll n,vector<ll> &a){
    vector<ll> subtree;
    ll cnt = 1;
    subtree.push_back(1);
    for(auto it:adj[node]){
        if(it==par) continue;
        ll x = dfs(it,node,adj,n,a);
        cnt+=x;
        subtree.push_back(x);
    }
    if((n-cnt)>0) subtree.push_back(n-cnt);
    if(func(a[node])){
        ll e1 = 0,e2 = 0,e3 = 0;
        for(auto s:subtree){
            e3+=(e2*s);
            e2+=(e1*s);
            e1+=s;
        }
        ans+=e3;
    }
    return cnt;
}

void solve() {  
    ans = 0;
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,adj,n,a);
    cout<<ans<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
