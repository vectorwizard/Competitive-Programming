#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> maxi(n+1,-1e18);
    maxi[0] = 0;
    for(ll i=0;i<n;i++){
        ll sum = 0;
        for(ll j=i;j<n;j++){
            sum+=a[j];
            ll len = j-i+1;
            maxi[len] = max(maxi[len],sum);
        }
    }
    vector<ll> ans(n+1);
    ans[0] = *max_element(maxi.begin(),maxi.end());
    for(ll i=1;i<=n;i++){
        ll p = -1e18;
        for(ll j=0;j<=n;j++){
            ll y = maxi[j] + min(i,j)*x;
            p = max(p,y);
        }
        ans[i] = p;
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
