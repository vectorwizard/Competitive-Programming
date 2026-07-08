#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
stack<ll> st;
vector<ll> coins;
vector<ll> dp;
void dfs(ll node,vector<ll> &vis,vector<vector<ll>> &adj){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it]==0) dfs(it,vis,adj);
    }
    st.push(node);
}
void dfs1(ll node,unordered_map<ll,set<ll>> &mpp1,unordered_map<ll,ll> &mpp2,unordered_map<ll,ll> &mpp3,vector<ll> &vis,ll cnt,vector<vector<ll>> &rev_adj){
    vis[node] = 1;
    mpp1[cnt].insert(node);
    mpp2[cnt]+=coins[node];
    mpp3[node] = cnt;
    for(auto it:rev_adj[node]){
        if(vis[it]!=1){
            dfs1(it,mpp1,mpp2,mpp3,vis,cnt,rev_adj);
        }
    }
}
ll dfs2(ll node,vector<vector<ll>> &adj_scc,unordered_map<ll,ll> &mpp2){
    ll maxi = mpp2[node];
    for(auto it:adj_scc[node]){
        ll x;
        if(dp[it]!=-1) x = dp[it];
        else x = dfs2(it,adj_scc,mpp2);
        maxi = max(maxi,mpp2[node]+x);
    }
    return dp[node]=maxi;
}
void solve() {
    ll n,m;
    cin>>n>>m;
    coins.assign(n,0);
    for(ll i=0;i<n;i++) cin>>coins[i];
    vector<vector<ll>> adj(n);
    vector<pair<ll,ll>> edges;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        edges.push_back({u,v});
    }
    vector<ll> vis(n,0);
    for(ll i=0;i<n;i++){
        if(vis[i]!=1) dfs(i,vis,adj);
    }
    vector<vector<ll>> rev_adj(n);
    for(ll i=0;i<n;i++){
        for(auto it:adj[i]){
            rev_adj[it].push_back(i);
        }
    }
    unordered_map<ll,set<ll>> mpp1;
    unordered_map<ll,ll> mpp2;
    unordered_map<ll,ll> mpp3;
    vis.assign(n,0);
    ll cnt = 0;
    while(!st.empty()){
        ll node = st.top();
        st.pop();
        if(vis[node]==1) continue;
        dfs1(node,mpp1,mpp2,mpp3,vis,cnt,rev_adj);
        cnt++;
    }
    ll size_scc = mpp2.size();
    vector<vector<ll>> adj_scc(size_scc);
    for(auto it:edges){
        ll u = it.first;
        ll v = it.second;
        if(mpp3[u]!=mpp3[v]){
            ll upar_u = mpp3[u];
            ll upar_v = mpp3[v];
            adj_scc[upar_u].push_back(upar_v);
        }
    }
    ll maxi = 0;
    dp.assign(size_scc,-1);
    for(ll i=0;i<size_scc;i++){
        ll x;
        if(dp[i]!=-1) x = dp[i];
        else x = dfs2(i,adj_scc,mpp2);
        maxi = max(maxi,x);
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}