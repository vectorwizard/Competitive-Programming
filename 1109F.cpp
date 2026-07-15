#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

pair<ll,ll> dfs(ll node,vector<vector<ll>> &adj,vector<ll> &a){
    if(a[node]!=0){
        return {a[node],a[node]};
    }
    vector<pair<ll,ll>> vec;
    for(auto it:adj[node]){
        auto it1 = dfs(it,adj,a);
        if(it1.first==-1 || it1.second==-1) return {-1,-1};
        vec.push_back({it1.first,it1.second});
    }
    vector<pair<ll,ll>> temp = vec;
    sort(temp.begin(),temp.end());
    ll siz = temp.size();
    for(ll i=1;i<siz;i++){
        if(temp[i].first!=temp[i-1].second+1) return {-1,-1};
    }
    ll bad = 0;    
    for(ll i=0;i<siz;i++){
        ll a = vec[i].first;
        ll b = vec[(i+1)%siz].second;
        if(a>b) bad++;
    }
    if(bad>1){
        return {-1,-1};
    }
    ll mini = 1e9;
    ll maxi = 0;
    for(auto it:temp){
        mini = min(mini,it.first);
        maxi = max(maxi,it.second);
    }
    return {mini,maxi};
}

void solve() {  
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=2;i<=n;i++){
        ll p;
        cin>>p;
        adj[p].push_back(i);
    }
    for(ll i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    auto it = dfs(1,adj,a);
    if(it.first==-1 || it.second==-1){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
