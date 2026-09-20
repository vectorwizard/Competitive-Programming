#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> color;

bool dfs(ll node,ll col,vector<vector<ll>> &adj){
    color[node] = col;
    bool ans = true;
    for(auto it:adj[node]){
        if(color[it]==col) return false;
        else if(color[it]==-1){
            ans = ans & dfs(it,!col,adj);
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vec[i] = {x,y};
    }
    map<ll,vector<ll>> mpp;
    for(ll i=0;i<n;i++){
        mpp[vec[i].first].push_back(i);
        mpp[vec[i].second].push_back(i);
    }
    vector<vector<ll>> adj(n+1);
    for(auto it:mpp){
        if(it.second.size()>2){
            cout<<"NO"<<endl;
            return;
        }
        if(it.second.size()==2){
            adj[it.second[0]].push_back(it.second[1]);
            adj[it.second[1]].push_back(it.second[0]);
        }
    }
    color.assign(n,-1);
    bool ans = true;
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            ans = ans & dfs(i,0,adj);
        }
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}