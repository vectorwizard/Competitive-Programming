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
    ll xorr = 0;
    for(ll i=0;i<n;i++){
        xorr^=a[i];
    }
    if(xorr==0){
        cout<<"YES"<<endl;
        return;
    }
    ll pre = n;
    ll prefix = 0;
    for(ll i=0;i<n;i++){
        prefix^=a[i];
        if(prefix==xorr){
            pre = i;
            break;
        }
    }
    ll suf = -1;
    ll suffix = 0;
    for(ll i=n-1;i>=0;i--){
        suffix^=a[i];
        if(suffix==xorr){
             suf = i;
            break;
        }
    }
    if(pre<suf) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
