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

void solve() {
    ll n,m;
    cin>>n>>m;
    DisjollSet ds(n+1);
    while(m--){
        ll siz;
        cin>>siz;
        ll first;
        for(ll i=0;i<siz;i++){
            ll x;
            cin>>x;
            if(i==0) first = x;
            ds.unionbysize(first,x);
        }
    }
    for(ll i=1;i<=n;i++){
        ll u_par = ds.findupar(i);
        cout<<ds.size[u_par]<<" ";
    }
    cout<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
