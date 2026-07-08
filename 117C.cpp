#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,ll k,ll target){
    ll x = 0,y=0;
    if(mid<=k){
        x = mid * (mid + 1) / 2;
    }
    if(mid>k){
         ll total = k*k;
         ll need = 2*k-1 - mid;
         y = total - (need * (need + 1) / 2);
    }
    if((x+y)>=target) return true;
    return false;
}
void solve() {
    ll k,x;
    cin>>k>>x;
    ll low = 1;
    ll high = 2*k-1;
    ll ans=2*k-1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,k,x)){
            ans = mid;
            high = mid-1;
        }
        else low=mid+1;
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
