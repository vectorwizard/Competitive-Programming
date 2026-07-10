#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll maxi = 1;
    ll cnt = 1;
    for(ll i=1;i<n;i++){
        if((a[i]-a[i-1])>k){
            maxi = max(maxi,cnt);
            cnt = 1;
        }
        else cnt++;
    }
    maxi = max(maxi,cnt);
    cout<<(n-maxi)<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
