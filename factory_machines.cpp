#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class DisjointSet{
public:
    vector<ll> par,size;
    DisjointSet(ll n){
        par.resize(n);
        size.resize(n,1);
        for(ll i=0;i<n;i++) par[i] = i;
    }
    ll findupar(ll node){
        if(par[node]==node) return node;
        return par[node] = findupar(par[node]);
    }
    void join(ll u,ll v){
        ll u_upar = findupar(u);
        ll v_upar = findupar(v);
        if(u_upar==v_upar) return;
        if(size[u_upar]<size[v_upar]){
            size[v_upar]+=size[u_upar];
            par[u_upar] = v_upar;
        }
        else{
            size[u_upar]+=size[v_upar];
            par[v_upar] = u_upar;
        }
    }
};
void solve(){
    ll n;
    cin>>n;
    DisjointSet ds(n+1);
    vector<pair<ll,ll>> coordinates(n+1);
    for(ll i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        coordinates[i] = {a,b};
    }
    vector<ll> c(n+1);
    vector<ll> k(n+1);
    for(ll i=1;i<=n;i++) cin>>c[i];
    for(ll i=1;i<=n;i++) cin>>k[i];
    vector<vector<ll>> edges;
    for(ll i=1;i<=n;i++){
        ll x1 = coordinates[i].first;
        ll y1 = coordinates[i].second;
        for(ll j=i+1;j<=n;j++){
            ll x2 = coordinates[j].first;
            ll y2 = coordinates[j].second;
            ll man_dist = (abs(x2-x1) + abs(y2-y1)) * (k[i]+k[j]);
            edges.push_back({man_dist,i,j});
        }
    }
    for(ll i=1;i<=n;i++){
        edges.push_back({c[i],0,i});
    }
    sort(edges.begin(),edges.end());
    ll cost = 0;
    vector<ll> hotspots;
    vector<pair<ll,ll>> lan;
    for(auto it:edges){
        ll u = it[1];
        ll v = it[2];
        ll w = it[0];
        if(ds.findupar(u)!=ds.findupar(v)){
            ds.join(u,v);
            cost+=w;
            if(u==0) hotspots.push_back(v);
            else if(v==0) hotspots.push_back(u);
            else{
                lan.push_back({u,v});
            }
        }
    }
    cout<<cost<<endl;
    cout<<hotspots.size()<<endl;
    for(auto it:hotspots) cout<<it<<" ";
    cout<<endl;
    cout<<lan.size()<<endl;
    for(auto it:lan){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Prll output to STDOUT */   
    ll t = 1;
    while(t--) solve();
    return 0;
}
