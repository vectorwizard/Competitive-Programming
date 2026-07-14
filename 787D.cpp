#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<vector<ll>> ans;

void dfs(ll node,vector<vector<ll>> &adj,vector<ll> &temp){
    temp.push_back(node);
    if(adj[node].size()==0){
        ans.push_back(temp);
        return;
    }
    ll size = adj[node].size();
    for(ll i=0;i<size;i++){
        if(i==0){
            dfs(adj[node][i],adj,temp);
        }
        else{
            vector<ll> vec;
            dfs(adj[node][i],adj,vec);
        }
    }
}

void solve() {  
    ans.clear();
    ll n;
    cin>>n;
    ll root;
    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<=n;i++){
        ll p;
        cin>>p;
        if(p==i){
            root=i;
            continue;
        }
        adj[p].push_back(i);
    }
    vector<ll> temp;
    dfs(root,adj,temp);
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++){
        cout<<ans[i].size()<<endl;
        for(auto it:ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
