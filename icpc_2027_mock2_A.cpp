#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,l,d;
    cin>>n>>l>>d;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll x = (d/l);
    ll rem = d%l;
    ll ans = x*n;
    if(x%2==0){
        ll ind = upper_bound(a.begin(),a.end(),rem) - a.begin();
        ind--;
        if(ind>=0) ans+=(ind+1);
        cout<<ans<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            a[i] = (l-a[i]);
        }
        reverse(a.begin(),a.end());
        ll ind = upper_bound(a.begin(),a.end(),rem) - a.begin();
        ind--;
        if(ind>=0) ans+=(ind+1);
        cout<<ans<<endl;
    }
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}