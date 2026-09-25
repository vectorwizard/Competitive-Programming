#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll ans0 = 0;
ll ans1 = 0;

bool dfs(ll node,ll col,vector<vector<ll>> &adj,vector<ll> &color,ll n){
    color[node] = col;
    if(node<=n){
        if(col==0) ans0++;
        else ans1++;
    }
    for(auto it:adj[node]){
        if(color[it]==-1){
            if(dfs(it,!col,adj,color,n)==false) return false;
        }
        else if(color[it]==col) return false;
    }
    return true;
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+m+1);
    ll extra = n+1;
    for(ll i=0;i<m;i++){
        ll l,r;
        string c;
        cin>>l>>r>>c;
        if(c=="imposter"){
            adj[l].push_back(r);
            adj[r].push_back(l);
        }
        else{
            adj[extra].push_back(l);
            adj[l].push_back(extra);
            adj[extra].push_back(r);
            adj[r].push_back(extra);
            extra++;
        }
    }
    vector<ll> color(n+m+1,-1);
    int ans = 0;
    for(ll i=1;i<=n;i++){
        if(color[i]==-1){
            ans1 = 0;
            ans0 = 0;
            if(dfs(i,0,adj,color,n)==false){
                cout<<-1<<endl;
                return;
            }
            ans+=max(ans1,ans0);
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
