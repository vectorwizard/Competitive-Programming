#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll x = 0;

ll func(ll node,vector<vector<ll>> &adj){
    ll cnt = 0;
    ll maxi2 = 0;
    ll maxi = 0;
    for(auto it:adj[node]){
        ll temp = func(it,adj);
        if(temp>maxi){
            maxi2 = maxi;
            maxi = temp;
        }
        else if(temp>maxi2){
            maxi2 = temp;
        }
        cnt++;
    }
    if(cnt>1){
        x+=maxi2;
    }
    return maxi +1;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> p(n+1);
    vector<vector<ll>> adj(n+1);
    for(ll i=2;i<=n;i++){
        cin>>p[i];
        adj[p[i]].push_back(i);
    }
    func(1,adj);
    ll ans = n + x;
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) {
        x=0;
        solve();
    }
    return 0;
}
