#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

string ans = "";
void dfs(ll node,vector<vector<ll>> &adj){
    while(adj[node].size()>0){
        ll backk = adj[node].back();
        adj[node].pop_back();
        dfs(backk,adj);
    }
    ans+=('a'+node);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> adj(k);
    for(ll i = 0;i<k;i++){
        for(ll j=0;j<k;j++){
            adj[i].push_back(j);
        }
    }
    dfs(0,adj); 
    reverse(ans.begin(),ans.end());
    string final = "";
    ll siz = ans.size()-1;
    ll ind = 0;
    for(ll i=0;i<n;i++){
        final+=ans[ind];
        ind = (ind+1)%siz;
    }
    cout<<final<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
