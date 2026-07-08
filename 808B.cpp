#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll> ans(n+1,0);
    for(ll i=1;i<=n;i++){
        ll x = (r/i);
        if((x*i)<l){
            cout<<"NO"<<endl;
            return;
        }
        else{
            ans[i] = x*i;
        }
    }
    cout<<"YES"<<endl;
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
