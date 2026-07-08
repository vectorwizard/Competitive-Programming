#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll mid,vector<ll> &a,ll h){
    vector<ll> b;
    for(ll i=0;i<mid;i++){
        b.push_back(a[i]);
    }
    sort(b.rbegin(),b.rend());
    ll x=0;
    for(ll i=0;i<b.size();i+=2){
        x+=b[i];
    }
    if(x<=h) return true;
    return false;
}
void solve() {
    ll n,h;
    cin>>n>>h;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll low = 1;
    ll high = n;
    ll ans = 1;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,h)){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
