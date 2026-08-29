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
    for(ll i=2;i<=n;i++){
        ll x;
        cin>>x;
        adj[x].push_back(i);
    }
    ll ans = 0;
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll siz = q.size();
        if(siz%2==1) ans++;
        for(ll i=0;i<siz;i++){
            ll x = q.front();
            q.pop();
            for(auto it:adj[x]){
                q.push(it);
            }
        }
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
