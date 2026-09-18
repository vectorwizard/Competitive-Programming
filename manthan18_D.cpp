#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<ll> seq(n);
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        cin>>seq[i];
        mpp[seq[i]] = i;
    }
    vector<vector<ll>> final(n+1);
    for(ll i=1;i<=n;i++){
        vector<pair<ll,ll>> vec;
        for(auto it:adj[i]){
            vec.push_back({mpp[it],it});
        }
        sort(vec.begin(),vec.end());
        for(auto it:vec){
            final[i].push_back(it.second);
        }
    }
    queue<ll> q;
    q.push(1);
    vector<ll> vis(n+1,0);
    vis[1] = 1;
    vector<ll> ans;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:final[node]){
            if(vis[it]==0){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    if(ans==seq){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}