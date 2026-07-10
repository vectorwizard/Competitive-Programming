#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    map<ll,ll> pref;
    pref[-1] = 0;
    for(ll i=0;i<n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        l--;
        r--;
        ll sum = pref[n-1] - pref[r] + pref[l-1];
        if(((sum+(r-l+1)*k)%2)==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
