#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,ll n){
    ll x = mid/2;
    ll rem = mid-x;
    ll k = x+1;
    ll ans = k*(rem+1);
    if(ans>=n) return true;
    return false;
}

void solve() {
    ll n;
    cin>>n;
    ll low = 0;
    ll high = 1e9;
    ll ans = high;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,n)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
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
