#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

class DisjollSet {
public:
    vector<ll> size, parent;
    DisjollSet(ll n) {
        size.resize(n);
        parent.resize(n);
        for (ll i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }
    ll findupar(ll node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findupar(parent[node]);
    }
    void unionbysize(ll u, ll v) {
        ll upar_u = findupar(u);
        ll upar_v = findupar(v);
        if (upar_u == upar_v)
            return;
        if (size[upar_u] < size[upar_v]) {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        } else {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};
const ll mod = 1e9+7;
vector<ll> fact(1e6+2,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=1e6;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

ll power(ll a, ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1){
        ans = (ans*a)%mod;
    }
    return ans%mod;
}

ll ncr(ll n,ll r){
    ll x = fact[n];
    ll y = fact[r];
    y = (y*fact[n-r])%mod;
    ll ans = (x * power(y,mod-2))%mod;
    return ans;
}

void dfs(ll node,vector<vector<ll>> &adj,vector<ll> &vis,ll ref,DisjollSet &ds){
    vis[node] = 1;
    ds.unionbysize(ref,node);
    for(auto it:adj[node]){
        if(vis[it]==0){
            dfs(it,adj,vis,ref,ds);
        }
    }
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<=n;i++) adj[i].push_back(a[i]);
    vector<ll> vis(n+1,0);
    DisjollSet ds(n+1);
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,adj,vis,i,ds);
        }
    }
    for(ll i=1;i<=n;i++){
        ll par = ds.findupar(i);
        cout<<ds.size[par]<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cal();
    cin>>t;
    while (t--) solve();
    return 0;
}
