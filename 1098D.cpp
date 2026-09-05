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
    vector<pair<ll,ll>> a(n);
    vector<ll> ys(n);
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a[i] = {x,y};
        ys[i] = y;
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    vector<ll> pref_max(n);
    vector<ll> suff_max(n);
    vector<ll> pref_min(n);
    vector<ll> suff_min(n);
    pref_max[0] = a[0].second;
    pref_min[0] = a[0].second;
    suff_max[n-1] = a[n-1].second;
    suff_min[n-1] = a[n-1].second;
    for(ll i=1;i<n;i++){
        pref_max[i] = max(pref_max[i-1],a[i].second);
        pref_min[i] = min(pref_min[i-1],a[i].second);
    }
    for(ll i=n-2;i>=0;i--){
        suff_max[i] = max(suff_max[i+1],a[i].second);
        suff_min[i] = min(suff_min[i+1],a[i].second);
    }
    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());
    for(ll i=0;i<=n-2;i++){
        if(a[i].first==a[i+1].first) continue;
        ll l = max(pref_min[i],suff_min[i+1]);
        ll r = min(pref_max[i],suff_max[i+1]);
        if(l>=r) continue;
        ll left = lower_bound(ys.begin(),ys.end(),l)-ys.begin();
        ll right = upper_bound(ys.begin(),ys.end(),r-1)-ys.begin();
        right--;
        if(left<=right) ans+=(right-left+1);
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
