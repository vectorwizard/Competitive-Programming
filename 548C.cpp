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
const ll mod = 1e9 + 7;
ll power(ll a,ll b){
    if(b==0) return 1;
    ll x = power(a,b/2)%mod;
    ll y = (x*x)%mod;
    if(b%2==1){
        y=(y*a)%mod;
    }
    return y%mod;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    DisjollSet ds(n+1);
    set<int> temp;
    for(ll i=0;i<n-1;i++){
        ll u,v,x;
        cin>>u>>v>>x;
        if(x!=1){
            ds.unionbysize(u,v);
        }
    }
    set<ll> st;
    for(ll i=1;i<=n;i++){
        ll upar = ds.findupar(i);
        st.insert(upar);
    }
    ll total = power(n,k);
    ll cnt = 0;
    for(auto it:st){
        cnt=(cnt+power(ds.size[it],k))%mod;
    }
    cout<<(total-cnt+mod)%mod<<endl;
}   
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}