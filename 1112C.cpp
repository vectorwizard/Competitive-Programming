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
    vector<vector<ll>> a(n);
    for(ll i=0;i<n;i++){
        ll l,r,u,v;
        cin>>l>>r>>u>>v;
        a[i] = {l,r,u,v};
    }
    for(ll m=n;m>=0;m--){
        ll cnt = 0;
        for(ll i=0;i<n;i++){
            ll l = a[i][0];
            ll r = a[i][1];
            ll u = a[i][2];
            ll v = a[i][3];
            ll x = cnt+1;
            ll right_rank = m - x + 1;
            if((x<l || x>r) && (right_rank<u || right_rank>v)) cnt++;
        }
        if(cnt>=m){
            cout<<m<<endl;
            return;
        }
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
