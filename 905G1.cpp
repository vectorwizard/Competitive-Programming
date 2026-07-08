#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(n);
    a[0] = 1;
    for(ll i=1;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    ll maxi = *max_element(b.begin(),b.end());
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    ll l = 0;
    ll r = n-1;
    while(r>=0){
        if(a[l]<b[r]){
            l++;
            r--;
        }
        else{
            r--;
        }
    }
    cout<<(n-l)<<endl;
}

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
