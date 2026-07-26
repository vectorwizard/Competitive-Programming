#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,k,z;
    cin>>n>>k>>z;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll ans = 0;
    for(ll i=0;i<=z;i++){
        if(i==0){
            ll sum = 0;
            for(ll i=0;i<=k;i++) sum+=a[i];
            ans = max(ans,sum);
            continue;
        }
        ll cnt = (k + 1) - (2*i);
        ll sum = 0;
        ll maxi = 0;
        for(ll j=0;j<=cnt;j++){
            if(j<cnt) sum+=a[j];
            if(j!=0) maxi = max(maxi,a[j]+a[j-1]);
        }
        sum+=(i*maxi);
        ans = max(ans,sum);
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
