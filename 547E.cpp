#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void solve() {
    ll h,n;
    cin>>h>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll sum = 0,min_pref = 1e18;
    for(int i=0;i<n;i++){
        sum+=a[i];
        min_pref = min(min_pref,sum);
        if((sum+h)<=0){
            cout<<i+1<<endl;
            return;
        }
    }
    if(sum>=0){
        cout<<-1<<endl;
        return;
    }
    ll diff = -sum;
    ll cnt = (h+min_pref)/diff;
    cnt = max(0LL,cnt);
    ll rem = h - (diff*cnt);
    cnt = cnt*n;
    for(ll i=0;i<n;i++){
        rem+=a[i];
        if(rem<=0){
            ll ans = cnt+i+1;
            cout<<ans<<endl;
            return;
        }
    }
    cnt+=n;
    for(ll i=0;i<n;i++){
        rem+=a[i];
        if(rem<=0){
            ll ans = cnt+i+1;
            cout<<ans<<endl;
            return;
        }
    }
} 

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}