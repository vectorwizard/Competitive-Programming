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
    map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        mpp[a[i]] = i;
    }
    ll maxi = -1;
    for(ll i=1;i<=1000;i++){
        for(ll j=1;j<=1000;j++){
            if(__gcd(i,j)!=1) continue;
            if(mpp.find(i)!=mpp.end() && mpp.find(j)!=mpp.end()){
                maxi = max(maxi,(mpp[i]+mpp[j]+2));
            }
        }
    }
    cout<<maxi<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
