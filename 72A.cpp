#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll s,ll i){
    if(s>i) return true;
    return false;
}

void solve() {
    ll s,i,e;
    cin>>s>>i>>e;
    if((s<i) && ((i-s)>=e)){
        cout<<0<<endl;
        return;
    }
    ll low = 0;
    ll high = e;
    ll ans = high;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(s+mid,(e-mid)+i)){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<(e-ans+1)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
