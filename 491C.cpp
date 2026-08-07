#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,ll n){
    ll xy = n;
    ll x = 0;
    while(n>0){
        ll mini = min(n,mid);
        x+=mini;
        n-=mini;
        ll y = n/10;
        if(y>n) continue;
        else n-=y;
    }
    if(x*2>=xy) return true;
    return false; 
}

void solve() {
    ll n;
    cin>>n;
    ll low = 1;
    ll high = n;
    ll ans = n;
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
    // cin>>t;
    while (t--) solve();
    return 0;
}
