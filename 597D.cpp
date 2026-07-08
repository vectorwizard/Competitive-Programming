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
    ll n;
    cin>>n;
    vector<ll> c(n+1);
    vector<ll> k(n+1);
    vector<pair<ll,ll>> polls(n+1);
    for(ll i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        polls[i] = {x,y};
    }
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<vector<ll>> edges;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
        edges.push_back({c[i],0,i});
    }
    for(ll i=1;i<=n;i++){
        cin>>k[i];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            ll dist = abs(polls[i].first-polls[j].first) + abs(polls[i].second-polls[j].second);
            edges.push_back({dist*(k[i]+k[j]),i,j});
        }
    }
    DisjollSet ds(n+1);
    sort(edges.begin(),edges.end());
    ll ans = 0;
    vector<ll> singles;
    vector<pair<ll,ll>> pairs;
    for(auto it:edges){
        ll w = it[0];
        ll u = it[1];
        ll v = it[2];
        ll upar_u = ds.findupar(u);
        ll upar_v = ds.findupar(v);
        if(upar_v!=upar_u){
            ds.unionbysize(u,v);
            ans+=w;
            if(u==0){
                singles.push_back(v);
            }
            else{
                pairs.push_back({u,v});
            }
        }
    }
    cout<<ans<<endl;
    cout<<singles.size()<<endl;
    for(auto it:singles) cout<<it<<" ";
    cout<<endl;
    cout<<pairs.size()<<endl;
    for(auto it:pairs){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
