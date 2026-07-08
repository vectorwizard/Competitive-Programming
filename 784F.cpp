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
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<pair<ll,ll>> suffix(n,{0,0});
    suffix[n-1] = {a[n-1],n-1};
    for(ll i=n-2;i>=0;i--){
        suffix[i] = {(suffix[i+1].first + a[i]),i};
    }
    ll sum = 0;
    ll ans = 0;
    sort(suffix.begin(),suffix.end());
    for(ll i=0;i<n;i++){
        sum+=a[i];
        ll ind = lower_bound(suffix.begin(),suffix.end(),make_pair(sum,0LL))-suffix.begin();
        if(ind==n) continue;
        ll x = suffix[ind].first;
        if(x!=sum) continue;
        ind = suffix[ind].second;
        if(i<ind) ans = max(ans,(n-ind+i+1));
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
