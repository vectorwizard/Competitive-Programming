#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    a--;
    b--;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        vec[i] = {x,y};
    }
    if(a<k && b<k){
        cout<<0<<endl;
        return;
    }
    ll mini1 = 1e18;
    if(a<k) mini1 = 0;
    else{
        for(ll i=0;i<k;i++){
            ll cost = abs(vec[i].first-vec[a].first)+abs(vec[i].second-vec[a].second);
            mini1 = min(mini1,cost);
        }
    }
    ll mini2 = 1e18;
    if(b<k) mini2 = 0;
    else{
        for(ll i=0;i<k;i++){
            ll cost = abs(vec[i].first-vec[b].first)+abs(vec[i].second-vec[b].second);
            mini2 = min(mini2,cost);
        }
    }
    ll ans = mini1+mini2;
    ans = min(ans,abs(vec[a].first-vec[b].first)+abs(vec[a].second-vec[b].second));
    cout<<ans<<endl;
}
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
