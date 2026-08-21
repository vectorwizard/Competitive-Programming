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
    vector<ll> ans(n+1,-1);
    for(ll i=2;i<=n;i+=2){
        ans[i] = 1;
    }
    ll x = 2;
    for(ll i=3;i<=n;i+=2){
        if(ans[i]==-1){
            for(ll j=i;j<=n;j+=i){
                if(ans[j]==-1) ans[j] = x;
            }
            x++;
        }
    }
    for(ll i=2;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}