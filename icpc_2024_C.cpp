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
    vector<ll> x(n);
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>x[i];
    }
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        vec[i] = {x[i],a[i]};
    }
    sort(vec.begin(),vec.end());
    vector<vector<ll>> pse(n);
    vector<vector<ll>> nse(n);
    pse[0] = {-1,1000000000,-1};
    stack<vector<ll>> st;
    st.push({vec[0].first,vec[0].second,0});
    for(ll i=1;i<n;i++){
        while(!st.empty() && st.top()[1]>vec[i].second){
            st.pop();
        }
        if(st.empty()) pse[i] = {-1,1000000000,-1};
        else{
            pse[i] = st.top();
        }
        st.push({vec[i].first,vec[i].second,i});
    }
    nse[n-1] = {n,1000000000,n};
    stack<vector<ll>> st1;
    st1.push({vec[n-1].first,vec[n-1].second,n-1});
    for(ll i=n-2;i>=0;i--){
        while(!st1.empty() && st1.top()[1]>vec[i].second){
            st1.pop();
        }
        if(st1.empty()) nse[i] = {n,1000000000,n};
        else{
            nse[i] = st1.top();
        }
        st1.push({vec[i].first,vec[i].second,i});
    }
    vector<vector<ll>> edges;
    for(ll i=0;i<n;i++){
        if(i>0){
            edges.push_back({(vec[i].first-vec[i-1].first)*(min(vec[i].second,vec[i-1].second)),i-1,i});
        }
        if(i<n-1){
            edges.push_back({(vec[i+1].first-vec[i].first)*(min(vec[i+1].second,vec[i].second)),i+1,i});
        }
        if(pse[i][0]!=-1){
            edges.push_back({(vec[i].first-pse[i][0])*(pse[i][1]),pse[i][2],i});
        }
        if(nse[i][0]!=n){
            edges.push_back({(nse[i][0]-vec[i].first)*(nse[i][1]),nse[i][2],i});
        }
    }
    sort(edges.begin(),edges.end());
    DisjollSet ds(n);
    ll ans = 0;
    for(auto it:edges){
        ll w = it[0];
        ll u = it[1];
        ll v = it[2];
        if(ds.findupar(u)!=ds.findupar(v)){
            ds.unionbysize(u,v);
            ans+=w;
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
