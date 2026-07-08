#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll mid,vector<ll> &a,ll c){
    ll n = a.size();
    ll total = 0;
    for(ll i=0;i<n;i++){
        ll x = (2*mid+a[i])*(2*mid+a[i]);
        total+=x;
        if(total>c) return total;
    }
    return total;
}

void solve() {
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll low = 0;
    ll high = 1e9;
    ll ans = 0;
    while(low<=high){
        ll mid = low+(high-low)/2;
        if(func(mid,a,c)==c){
            ans = mid;
            break;
        }
        else if(func(mid,a,c)>c){
            high = mid-1;
        }
        else low = mid+1;
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
