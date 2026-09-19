#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &a,ll k){
    ll n = a.size();
    ll sum = a[0] + mid;
    for(ll i=1;i<n;i++){
        ll x = a[i] * 100;
        if(x>(k*sum)) return false;
        sum+=a[i];
    }
    return true;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll low = 0;
    ll high = 1e17;
    ll ans = 1e17;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,k)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
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