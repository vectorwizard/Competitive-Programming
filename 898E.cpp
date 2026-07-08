#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &a,ll x){
    ll n = a.size();
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(a[i]>=mid) continue;
        ans+=(mid-a[i]);
    }
    if(ans<=x) return true;
    return false;
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll low = 0;
    ll high = 1e9+*max_element(a.begin(),a.end());
    ll ans = 0;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,x)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
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
