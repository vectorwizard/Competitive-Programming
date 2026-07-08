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
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> vec(n);
    vec[0] = x;
    for(ll i=1;i<n;i++){
        vec[i] = (vec[i-1]*a + b)%c;
    }
    ll ans = 0;
    ll temp = 0;
    for(ll i=0;i<k;i++){
        temp^=vec[i];
    }
    ans = temp;
    ll l = 0;
    for(ll r=k;r<n;r++){
        temp^=vec[r];
        temp^=vec[l];
        l++;
        ans = ans^temp;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
