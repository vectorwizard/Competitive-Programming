#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,p;
    cin>>n>>p;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;i++){
        vec[i] = {b[i],a[i]};
    }
    sort(vec.begin(),vec.end());
    ll ans = p;
    ll cnt = 1;
    for(ll i=0;i<n;i++){
        if(vec[i].first>p) break;
        ll rem = (n-cnt);
        rem = min(rem,vec[i].second);
        ans+=(rem*vec[i].first);
        cnt+=rem;
    }
    if(cnt<n){
        ans+=((n-cnt)*p);
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
