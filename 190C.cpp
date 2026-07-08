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
    ll x = 0;
    vector<ll> y;
    for(ll i=0;i<n;i++){
        if(a[i]==1) x++;
        else y.push_back(a[i]);
    }
    if(y.size()==0){
        cout<<0<<endl;
        return;
    }
    else if(y.size()==1){
        ll ans = y[0] + min(x,(y[0]/2));
        if(ans<3) cout<<0<<endl;
        else cout<<ans<<endl;
        return;
    }
    else{
        ll total = 0;
        ll cum = 0;
        for(ll i=0;i<y.size();i++){
            cum+=y[i];
            total+=((y[i]-2)/2);
        }
        ll ans = cum+min(total,x);
        cout<<ans<<endl;
    }
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
