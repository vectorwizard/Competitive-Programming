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
    vector<ll> set(31,0);
    for(ll i=30;i>=0;i--){
        for(ll j=0;j<n;j++){
            if(a[j]&(1<<i)){
                set[i]++;
            }
        }
    }
    ll ans = 0;
    for(ll i=30;i>=0;i--){
        ll need = (n-set[i]);
        if(set[i]==n){
            ans+=(1<<i);
        }
        else if(need<=k){
            k-=need;
            ans+=(1<<i);
        }
        else continue;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
