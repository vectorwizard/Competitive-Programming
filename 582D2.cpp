#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<vector<ll>> costs(2e5+1);
    for(ll i=0;i<n;i++){
        ll x = a[i];
        ll cost = 0;
        while(x>0){
            costs[x].push_back(cost);
            x/=2;
            cost++;
        }
        costs[0].push_back(cost);
    }
    for(ll i=0;i<=2e5;i++){
        sort(costs[i].begin(),costs[i].end());
    }
    ll ans = 1e9;
    for(ll i=0;i<=2e5;i++){
        if(costs[i].size()<k) continue;
        ll temp = 0;
        for(ll j = 0;j<k;j++) temp+=costs[i][j];
        ans = min(ans,temp);
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
