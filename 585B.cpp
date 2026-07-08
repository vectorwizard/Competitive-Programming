#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll neg = 0;
    map<ll,ll> prefix;
    prefix[-1] = 0;
    for(ll i=0;i<n;i++){
        if(a[i]<0) neg++;
        prefix[i] = neg;
    }
    vector<ll> odds(n,0);
    vector<ll> evens(n,0);
    ll odd = 0;
    ll even = 1;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(prefix[i]%2==0) even++;
        else odd++;
        if(prefix[i]%2==0){
            ans+=(even-1);
        }
        else ans+=(odd-1);
    }
    ll x = n*(n+1)/2;
    cout<<(x-ans)<<" "<<ans<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
