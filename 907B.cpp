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
    vector<ll> x(q);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<q;i++) cin>>x[i];
    ll maxi = 32;
    for(ll i=0;i<q;i++){
        if(x[i]>=maxi) continue;
        ll div = 1<<x[i];
        for(ll j=0;j<n;j++){
            if(a[j]%div==0){
                a[j]+=(1<<(x[i]-1));
            }
        }
        maxi = x[i];
    }
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
