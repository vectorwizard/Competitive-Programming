#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,c;
    cin>>n>>c;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    ll m = (n+1)/2;
    if(c==0){
        ll ans = 0;
        for(ll i=0;i<n;i++){
            if(i>=m){
                if(a[i]<0) break;
            }
            ans+=a[i];
        }
        cout<<ans<<endl;
        return;
    }
    else{
        ll ans = 0;
        for(ll i=0;i<n;i++){
            a[i] = a[i] -  c;
        }
        for(ll i=0;i<n;i++){
            if(i>=m){
                if(a[i]<0) break;
            }
            ans+=a[i];
        }
        cout<<ans<<endl;
        return;
    }
} 

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
