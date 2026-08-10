#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+2);
    a[0] = 0;
    a[n+1] = m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    n = n +2;
    vector<ll> good(n,0);
    vector<ll> bad(n,0);
    for(ll i=n-2;i>=0;i--){
        if(i%2==0){
            good[i] = good[i+1] + (a[i+1]-a[i]);
            bad[i] = bad[i+1];
        }
        else{
            good[i] = good[i+1];
            bad[i] = bad[i+1] + (a[i+1]-a[i]);
        }
    }
    ll ans = good[0];
    ll pref = 0;
    for(ll i=0;i<n-1;i++){
        if((a[i+1]-a[i])>1){
            ll take = pref;
            take++;
            take+=bad[i+1];
            ans = max(ans,take);
            take = pref;
            take+=(a[i+1]-a[i]-1);
            take+=bad[i+1]; 
            ans = max(ans,take);
        } 
        if(i%2==0) pref+=(a[i+1]-a[i]);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
