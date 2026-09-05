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
    vector<ll> b(k);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<k;i++) cin>>b[i];
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    ll ind = 0;
    ll ans = 0;
    for(ll i=0;i<k;i++){
        ll rem = (n-ind);
        if(rem<b[i]) break;
        ll x = b[i];
        while(x>1){
            ans+=a[ind];
            ind++;
            x--;
        }
        ind++;
    }
    while(ind<n){
        ans+=a[ind];
        ind++;
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
