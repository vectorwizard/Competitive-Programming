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
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++) cin>>a[i];
    map<ll,ll> mpp;
    for(ll i=1;i<=n;i++){
        mpp[a[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            cout<<-1<<endl;
            return;
        }
    }
    ll i = 1;
    vector<ll> ans(n+1);
    while(i<n){
        ll cnt = mpp[a[i]];
        for(ll j=0;j<cnt-1;j++){
            ans[i+j] = i+j+1;
        }
        ans[i+cnt-1] = i;
        i+=cnt;
    }
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
