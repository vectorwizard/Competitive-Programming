#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> gaps;
    for(ll i=1;i<n;i++){
        gaps.push_back(a[i]-a[i-1]-1);
    }
    sort(gaps.begin(),gaps.end());
    ll target = n-k;
    ll ans = n;
    for(ll i=0;i<target;i++){
        ans+=gaps[i];
    }
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
