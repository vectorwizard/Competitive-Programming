#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll k;
    cin>>k;
    vector<ll> a(k);
    for(ll i=0;i<k;i++){
        cin>>a[i];
    }
    for(ll i=0;i<k;i++){
        if(a[i]>=3){
            cout<<"YES"<<endl;
            return;
        }
    }
    ll cnt = 0;
    for(ll i=0;i<k;i++){
        if(a[i]>=2){
            cnt++;
        }
    }
    if(cnt>=2){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
