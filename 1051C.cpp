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
    vector<ll> indegree(n+1,0);
    for(ll i=0;i<n-1;i++){
        ll u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x>y){
            adj[u].push_back(v);
            indegree[v]++;
        }   
        else{
            adj[v].push_back(u);
            indegree[u]++;
        }
    }
    queue<ll> q;
    for(ll i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    ll cnt = n;
    vector<ll> ans(n+1);
    while(!q.empty()){
        ll siz = q.size();
        for(ll i=0;i<siz;i++){
            ll node = q.front();
            q.pop();
            ans[node] = cnt;
            cnt--;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    }
    for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
