#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<ll> degree(n+1,0);
    vector<pair<ll,ll>> edges;
    for(ll i = 0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        degree[x]++;
        degree[y]++;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
        edges.push_back({x,y});
    }
    vector<ll> ans;
    queue<ll> q;
    vector<ll> k_core(n+1,1);
    for(ll i=1;i<=n;i++){
        if(degree[i]<k) {
            q.push(i);
            k_core[i] = 0;
        }
    }  
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto it:adj[node]){
            if(k_core[it.first]==0) continue;
            degree[it.first]--;
            if(degree[it.first]<k){
                k_core[it.first] = 0;
                q.push(it.first);
            }
        }
    }
    ll cnt = 0;
    for(ll i=1;i<=n;i++){
        if(k_core[i]==1) cnt++;
    }
    ans.push_back(cnt);
    for(ll i=m-1;i>=1;i--){
        ll x = edges[i].first;
        ll y = edges[i].second;
        if(k_core[x]==1 && k_core[y]==1){
            degree[x]--;
            degree[y]--;
            if(degree[x]<k){
                q.push(x);
                k_core[x] = 0;
                cnt--;
            }
            if(degree[y]<k){
                q.push(y);
                k_core[y] = 0;
                cnt--;
            }
        }
        while(!q.empty()){
            ll node = q.front();
            q.pop();
            for(auto it:adj[node]){
                ll edge = it.first;
                ll idx = it.second;
                if(idx<i && k_core[edge] == 1){
                    degree[edge]--;
                    if(degree[edge]<k){
                        q.push(edge);
                        k_core[edge] = 0;
                        cnt--;
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}